#include "media_pro.h"
#include <sstream>

#define FRESHNESS 10 
using std::string;
using std::stringstream;

void NDNState::ccn_debug_print(char *w)
{
    if (!ccn_debug_print_enabled)
        return;
    printf("%s", w);
    fflush(stdout);
}

void need_fresh_interest(UserDataBuf *userBuf)
{
    if (userBuf != NULL)
        userBuf->interested = 0;
}

/*
void everybody_notice(struct data_buffer *db)
{
    if (db != NULL)
        pthread_cond_broadcast(&db->changed);
}
*/

int checkNameInterestMatch(struct ccn_upcall_info *info, UserDataBuf * userBuf) {
    int i;
    if (info->interest_ccnb == NULL || info->interest_comps == NULL
            || info->interest_comps->n < userBuf->iSegNum ) return -1;
    for (i = 0; i < userBuf->iSegNum; i++) {
        if (ccn_name_comp_strcmp(info->interest_ccnb, info->interest_comps, i, 
                    userBuf->szNameSeg[i]) != 0) return -1; 
    }
    return 0;
}

int checkNameContentMatch(struct ccn_upcall_info *info, UserDataBuf * userBuf) {
    int i;
    if (info->content_ccnb == NULL || info->content_comps == NULL
            || info->content_comps->n < userBuf->iSegNum ) return -1;
    for (i = 0; i < userBuf->iSegNum; i++) {
        if (ccn_name_comp_strcmp(info->content_ccnb, info->content_comps, i, 
                    userBuf->szNameSeg[i]) != 0) return -1; 
    }
    return 0;
}

enum ccn_upcall_res
rtp_content_handler(struct ccn_closure *selfp,
		    enum ccn_upcall_kind kind,
		    struct ccn_upcall_info *info)
{
    UserDataBuf *userBuf  = (UserDataBuf *)selfp->data;
	qWarning("<<<<>>>>>  Handling Incoming Voice Content\n");

    //
    if (userBuf == NULL || userBuf->iNeedDestroy) {
        if (userBuf != NULL) delete userBuf;
        selfp->data = NULL;
        if (kind == CCN_UPCALL_FINAL) free(selfp);
        return CCN_UPCALL_RESULT_OK;
    }

    struct data_buffer *buffer = &userBuf->data_buf;
    const unsigned char *content_value;
    NDNState *state = buffer->state;
    int call_matches = 0;

    if (kind == CCN_UPCALL_FINAL) {
        fprintf(stderr, "rtp_content_handler((%s), CCN_UPCALL_FINAL, ...)\n", userBuf->user_name.toStdString().c_str());
        need_fresh_interest(userBuf);
        free(selfp);
        return CCN_UPCALL_RESULT_OK;
    }

    /*check if the content is belong to this user.*/
    if (checkNameInterestMatch(info, userBuf) == 0) 
        call_matches = 1;
 
    if (kind == CCN_UPCALL_INTEREST_TIMED_OUT) {
        if (call_matches)
            return (CCN_UPCALL_RESULT_REEXPRESS);
        return CCN_UPCALL_RESULT_OK;
    }
    if (kind == CCN_UPCALL_CONTENT || kind == CCN_UPCALL_CONTENT_UNVERIFIED) {
        const unsigned char *ccnb = info->content_ccnb;
        size_t ccnb_size = info->pco->offset[CCN_PCO_E];
        struct ccn_indexbuf *comps = info->content_comps;
        
        call_matches = 0;
        if (checkNameContentMatch(info, userBuf) == 0 )
            call_matches = 1;

        if (call_matches) {
            /* Update the appropriate path for next time */
            long seq;
            const unsigned char *seqptr = NULL;
            char *endptr = NULL;
            size_t seq_size = 0;
            int k = comps->n - 2;
            struct ccn_charbuf *pathbuf = ccn_charbuf_create();
            ccn_name_init(pathbuf);
            ccn_name_append_components(pathbuf, ccnb, comps->buf[0], comps->buf[k]);
            seq = ccn_ref_tagged_BLOB(CCN_DTAG_Component, ccnb,
                    comps->buf[k], comps->buf[k + 1],
                    &seqptr, &seq_size);
            if (seq >= 0) {
                seq = strtol((const char *)seqptr, &endptr, 10);
                if (endptr != ((const char *)seqptr) + seq_size)
                    seq = -1;
            }
            if (seq >= 0) {
                struct ccn_charbuf *temp = ccn_charbuf_create();
                int sav = pathbuf->length - 1;
                if (state->ccn_debug_print_enabled >= 'V') {
                    ccn_charbuf_putf(temp, "(%ld)", seq);
                    state->ccn_debug_print(ccn_charbuf_as_string(temp));
                    temp->length = 0;
                }
                ccn_charbuf_putf(temp, "%ld", seq + 1);
                ccn_name_append(pathbuf, temp->buf, temp->length);
                ccn_express_interest(info->h, pathbuf, selfp, NULL);
                if (state->hint_ahead > 1) { 
                    /* Issue a read-ahead to get the future packets
                     * flowing sooner */
                    pathbuf->length = sav;
                    ccn_charbuf_append_closer(pathbuf);
                    temp->length = 0;
                    ccn_charbuf_putf(temp, "%ld", seq + state->hint_ahead);
                    ccn_name_append(pathbuf, temp->buf, temp->length);
                    ccn_express_interest(info->h, pathbuf,
                            &state->rtp_pipeline_callback, NULL);
					
					// debug
					char * uri = ccn_charbuf_as_string(pathbuf);
					qWarning("fetching the next segment: %s\n", uri);
                }
                ccn_charbuf_destroy(&temp);
            }
            else {
                fprintf(stderr, "URP - expecting seq num, got junk\n");
            }
            ccn_charbuf_destroy(&pathbuf);

            /* Append it to the queue */
            struct buf_list *b;
            b = (struct buf_list *)calloc(1, sizeof(*b));
            b->link = NULL;
            ccn_content_get_value(ccnb, ccnb_size, info->pco,
                    &content_value, &b->len);
            b->buf = malloc(b->len);
            memcpy(b->buf, content_value, b->len);
            if (buffer->buflist == NULL)
                buffer->buflist = b;
            else {
                struct buf_list *p = buffer->buflist;
                while (p->link != NULL)
                    p = p->link;
                p->link = b;
            }
            
            /*emit the signal for get the data out of the buffer*/
            state->emitSignal(userBuf->user_name);
        }
    }
    return CCN_UPCALL_RESULT_OK;
}

enum ccn_upcall_res
rtp_pipeline_content_handler(struct ccn_closure *selfp,
                             enum ccn_upcall_kind kind,
                             struct ccn_upcall_info *info)
{
    if (kind == CCN_UPCALL_CONTENT || kind == CCN_UPCALL_CONTENT_UNVERIFIED) {
	const unsigned char *ccnb = info->content_ccnb;
	struct ccn_indexbuf *comps = info->content_comps;

    /*
     * This is our read-ahead that attempts to get the new data
     * on the other side to be sent just as soon as it is generated.
     * We can just mostly ignore it here; the real delivery happens
     * in rtp_content_handler above.  The only processing here is to
     * do some detection and timely repair of the occasional dropped
     * packet.  Since this is all operating in one thread, we don't
     * have to worry about locking.
     */

    long seq;
    const unsigned char *seqptr = NULL;
    char *endptr = NULL;
    size_t seq_size = 0;
    int k = comps->n - 3;
    seq = ccn_ref_tagged_BLOB(CCN_DTAG_Component, ccnb,
            comps->buf[k], comps->buf[k + 1],
            &seqptr, &seq_size);
    if (seq >= 0) {
        seq = strtol((const char *)seqptr, &endptr, 10);
        if (endptr != ((const char *)seqptr) + seq_size)
            seq = -1;
    }
    /* selfp->intdata holds the largest sequence number seen so far */
    if (seq == selfp->intdata + 2) {
        /*
         * Out-of-order arrival may be due to a lost data packet.
         * Try to recover faster by re-issuing an interest for the
         * missing piece.
         */
        struct ccn_charbuf *pathbuf = ccn_charbuf_create();
        struct ccn_charbuf *temp = ccn_charbuf_create();
        ccn_name_init(pathbuf);
        ccn_name_append_components(pathbuf, ccnb, comps->buf[0], comps->buf[k]);
        ccn_charbuf_putf(temp, "%ld", seq - 1);
        ccn_name_append(pathbuf, temp->buf, temp->length);
        ccn_charbuf_destroy(&temp);
        ccn_express_interest(info->h, pathbuf, selfp, NULL);
        fprintf(stderr, "(%ld?!)\n", seq - 1);
        ccn_charbuf_destroy(&pathbuf);
    }
    if (seq > selfp->intdata)
        selfp->intdata = seq;
    else if (seq > 0 && seq + 100 < selfp->intdata)
        selfp->intdata = seq; /* reset - probably new audio stream */
    }
    return CCN_UPCALL_RESULT_OK;
}

void 
data_buffer_init(NDNState *state, UserDataBuf *userBuf, const char *direction)
{
    struct data_buffer *db = &userBuf->data_buf;
    db->callback->data = userBuf;
    db->state = state;
    db->buflist = NULL;
    strncpy(db->direction, direction, sizeof(db->direction));
    if (db->direction[0] == 'r')
        db->callback->p = &rtp_content_handler;
    need_fresh_interest(userBuf);
    //return(db);
}

static struct ccn_keystore *cached_keystore = NULL;

void
init_cached_keystore(void)
{
    struct ccn_keystore *keystore = cached_keystore;
    int res;

    //XXX - missing mutex
    if (keystore == NULL) {
	struct ccn_charbuf *temp = ccn_charbuf_create();
	keystore = ccn_keystore_create();
	ccn_charbuf_putf(temp, "%s/.ccnx/.ccnx_keystore", getenv("HOME"));
	res = ccn_keystore_init(keystore,
				ccn_charbuf_as_string(temp),
				"Th1s1sn0t8g00dp8ssw0rd.");
	if (res != 0) {
	    printf("Failed to initialize keystore %s\n", ccn_charbuf_as_string(temp));
	    exit(1);
	}
	ccn_charbuf_destroy(&temp);
	cached_keystore = keystore;
    }
}

const struct ccn_pkey *
get_my_private_key(void)
{
    //XXX - missing mutex
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_private_key(cached_keystore));
}

const struct ccn_certificate *
get_my_certificate(void)
{
    //XXX - missing mutex
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_certificate(cached_keystore));
}

const unsigned char *
get_my_publisher_key_id(void)
{
    //XXX - missing mutex
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_public_key_digest(cached_keystore));
}


ssize_t
get_my_publisher_key_id_length(void)
{
    //XXX - missing mutex
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_public_key_digest_length(cached_keystore));
}

int
ndn_make_remote_path(struct ccn_charbuf *path, UserDataBuf *userBuf) {
    int i;
    ccn_name_init(path);
    //ccn_name_append_str(path, userBuf->user_name.c_str());
    for (i = 0; i < userBuf->iSegNum; i++) {
        ccn_name_append_str(path, userBuf->szNameSeg[i]);
    }
    ccn_name_append_str(path, "audio");
    return(0);
}

NdnMediaProcess::NdnMediaProcess()
{
    //struct ccn *h = NULL;
    const char *env_VOCCN_DEBUG = NULL;
    const char *env_VOCCN_RTP_HINT_AHEAD = NULL;
    //struct rtp_ccn_state *rtp_state; 
    
    ndnState.hint_ahead = 20;
    ndnState.ccn_debug_print_enabled = 0;
    env_VOCCN_RTP_HINT_AHEAD = getenv("VOCCN_RTP_HINT_AHEAD");
    if (env_VOCCN_RTP_HINT_AHEAD != NULL && env_VOCCN_RTP_HINT_AHEAD[0] != 0)
    ndnState.hint_ahead = atoi(env_VOCCN_RTP_HINT_AHEAD);
    
    env_VOCCN_DEBUG = getenv("VOCCN_DEBUG");
    if (env_VOCCN_DEBUG != NULL && env_VOCCN_DEBUG[0] != 0) {
        ndnState.ccn_debug_print_enabled = env_VOCCN_DEBUG[0];
    }
    
    /* Also set up handler for pipelining */
    ndnState.rtp_pipeline_callback.p = &rtp_pipeline_content_handler;
    ndnState.rtp_pipeline_callback.data = &ndnState;
}

NdnMediaProcess::~NdnMediaProcess()
{
    QHash<QString,UserDataBuf *>::iterator it; 
    QMutexLocker qmlLocal(&LUsersLock);
    for ( it = qmLocalUser.begin(); it != qmLocalUser.end(); ++it ) {
        delete it.value(); 
    }

    QMutexLocker qmlRemote(&RUsersLock);
    for ( it = qmRemoteUser.begin(); it != qmRemoteUser.end(); ++it ) {
        delete it.value();
    }
}

int UserDataBuf::splitUserName()
{
    string name = user_name.toStdString();
    stringstream ss(name);
    string sub_str;
    iSegNum = 0;
    while(getline(ss,sub_str,'/')) {
        if (strcmp(sub_str.c_str(), "") == 0) continue;
        strncpy(szNameSeg[iSegNum], sub_str.c_str(), sizeof(szNameSeg[iSegNum])); 
        iSegNum++;
    }
}

void NdnMediaProcess::addRemoteUser(QString strUserName)
{

    UserDataBuf *rUser = new UserDataBuf(); 
    data_buffer_init(&ndnState, rUser, "recv");
    rUser->user_name = strUserName;
    rUser->user_type = REMOTE_USER;
    rUser->splitUserName();
    QMutexLocker qml(&RUsersLock);
    qmRemoteUser.insert(strUserName, rUser); 
}

void NdnMediaProcess::deleteRemoteUser(QString strUserName)
{
    QMutexLocker qml(&RUsersLock);
    UserDataBuf *p =  qmRemoteUser.value(strUserName);
    if (p == NULL) {
        RUsersLock.unlock();
        return;
    }
    qmRemoteUser.remove(strUserName); 
    if (p->interested == 0) delete p;
    else p->iNeedDestroy = 1;
}

void NdnMediaProcess::addLocalUser(QString strUserName)
{

    UserDataBuf *rUser = new UserDataBuf; 
    data_buffer_init(&ndnState, rUser, "send");
    rUser->user_name = strUserName;
    rUser->user_type = LOCAL_USER;
    rUser->splitUserName();
    QMutexLocker qml(&LUsersLock);
    qmLocalUser.insert(strUserName, rUser); 
}

void NdnMediaProcess::deleteLocalUser(QString strUserName)
{
    QMutexLocker qml(&LUsersLock);
    UserDataBuf *p =  qmLocalUser.value(strUserName);
    if (p == NULL) return;
    qmLocalUser.remove(strUserName); 
    delete p;
}

#if 0
void NdnMediaProcess::rtp_ccn_setup_call()
{
    pthread_mutex_lock(&ccn_state.rtp_ccn_lock);
    if (ccn_state.active) {
         printf("Warning - a call is already set up!\n");
    }
    ccn_state.active = 1;
    pthread_mutex_unlock(&ccn_state.rtp_ccn_lock);
}

void NdnMediaProcess::rtp_ccn_teardown_call()
{
    pthread_mutex_lock(&ccn_state.rtp_ccn_lock);
    ccn_state.active = 0;
    /*
    everybody_notice(ccn_state.rtp_send_buf);
    everybody_notice(ccn_state.rtcp_send_buf);
    everybody_notice(ccn_state.rtp_recv_buf);
    everybody_notice(ccn_state.rtcp_recv_buf);
    */
    while (ccn_state.ccn != NULL) {
        printf("------------- CALL TEARDOWN\n");
        pthread_cond_wait(&ccn_state.changed, &ccn_state.rtp_ccn_lock);
    }
    /*
    need_fresh_interest(ccn_state.rtp_recv_buf);
    need_fresh_interest(ccn_state.rtcp_recv_buf);
    */
    pthread_mutex_unlock(&ccn_state.rtp_ccn_lock);
}
#endif 

int NdnMediaProcess::ndnDataSend(UserDataBuf *userBuf, const void *buf, size_t len)
{

#define CHARBUF_DESTROY \
    ccn_charbuf_destroy(&message);\
    ccn_charbuf_destroy(&path); \
    ccn_charbuf_destroy(&signed_info); \
    ccn_charbuf_destroy(&seq);

    int res = 0;
    int seq_num = -1;
    struct ccn_charbuf *message = ccn_charbuf_create();
    struct ccn_charbuf *path = ccn_charbuf_create();
    struct ccn_charbuf *signed_info = ccn_charbuf_create();
    struct ccn_charbuf *seq = ccn_charbuf_create();
    unsigned char *ccn_msg = NULL;
    size_t ccn_msg_size = 0;
    
    ccn_name_init(path);
    
    /* yes, this seems backwards, but the remote end sends an interest
     * in the local rtp data, because that way the packet can be routed
     * to the right place
     */
    if (ndnState.active){
        seq_num = userBuf->data_buf.seq++;
        for (int i = 0; i < userBuf->iSegNum; i++) {
            ccn_name_append_str(path, userBuf->szNameSeg[i]);
        }
        ccn_name_append_str(path, "audio"); 
    }
    
    if (seq_num < 0) {
        res = -1;
        CHARBUF_DESTROY;
        return res;
    }
    
    ccn_charbuf_putf(seq, "%u", seq_num);
    ccn_name_append(path, seq->buf, seq->length);
    
    /* Create message */
    res = ccn_signed_info_create(signed_info,
                                 /* pubkeyid */ get_my_publisher_key_id(),
                                 /* publisher_key_id_size */ get_my_publisher_key_id_length(),
                                 /* datetime */ NULL,
                                 /* type */ CCN_CONTENT_DATA,
                                 /* freshness */ FRESHNESS,
				                 /* finalblockid */ NULL,
                                 /* keylocator */ NULL);
    if (res != 0) {
	    fprintf(stderr, "signed_info_create failed %d (line %d)\n", res, __LINE__);
        CHARBUF_DESTROY;
        return res;
    }
    res = ccn_encode_ContentObject( /* out */ message,
				   path,
				   signed_info,
				   buf, len,
			       /* keyLocator */ NULL, get_my_private_key());

    if (res != 0) {
        fprintf(stderr, "encode_ContentObject failed %d (line %d)\n", res, __LINE__);
        CHARBUF_DESTROY;
        return res;
    }
    
    ccn_msg = (unsigned char *)calloc(1, message->length);
    ccn_msg_size = message->length;
    memcpy(ccn_msg, message->buf, message->length);
    { struct ccn_parsed_ContentObject o = {0};
        res = ccn_parse_ContentObject(ccn_msg, ccn_msg_size, &o, NULL);
        if (res < 0) {
            fprintf(stderr, "created bad ContentObject, res = %d\n", res);
            abort();
        }
    }

	qWarning("ContentObject for voice data created");
    
    struct buf_list *p = NULL, *b = userBuf->data_buf.buflist;
    while (b != NULL) { p = b; b = b->link; }
    b = (struct buf_list*)calloc(1, sizeof(struct buf_list));
    if (b == NULL) {
        CHARBUF_DESTROY;
        return -1;
    }
    if (p != NULL)
        p->link = b;
    else userBuf->data_buf.buflist = b;
    
    b->buf = ccn_msg;
    b->len = ccn_msg_size;
    b->link = NULL;

    CHARBUF_DESTROY;
    return res;
}

int NdnMediaProcess::doPendingSend()
{
    int res = 0;

    QMutexLocker qml(&LUsersLock);
    QHash<QString,UserDataBuf *>::iterator it; 
    for ( it = qmLocalUser.begin(); it != qmLocalUser.end(); ++it ) {
        struct buf_list  *p ,*b = it.value()->data_buf.buflist;
        if (b != NULL) {
            p = b->link;
            if (b != NULL && b->buf != NULL) {
                /*do not neet lock,beacause the ccn connection is just used by this mudule
                 * other module just set active to end this module*/
                res = ccn_put(ndnState.ccn, b->buf, b->len);
				qWarning("Just put a voice object to ccnd\n");
                free(b->buf);
                b->len = 0;
                b->buf = NULL;
            }
            free(b);
            it.value()->data_buf.buflist = p;
        }
    }
    return res;
}

int NdnMediaProcess::checkInterest()
{
    int res = 0;
    QMutexLocker qml(&RUsersLock);
    QHash<QString,UserDataBuf *>::iterator it; 
    for ( it = qmRemoteUser.begin(); it != qmRemoteUser.end(); ++it ) {
        if (!it.value()->interested) {
            /* Use a template to express our order preference for the first packet. */
            struct ccn_charbuf *templ = ccn_charbuf_create();
            struct ccn_charbuf *path = ccn_charbuf_create();
            ccn_charbuf_append_tt(templ, CCN_DTAG_Interest, CCN_DTAG);
            ccn_charbuf_append_tt(templ, CCN_DTAG_Name, CCN_DTAG);
            ccn_charbuf_append_closer(templ);
            ccn_charbuf_append_tt(templ, CCN_DTAG_ChildSelector, CCN_DTAG);
            ccn_charbuf_append_tt(templ, 1, CCN_UDATA);
            ccn_charbuf_append(templ, "0", 1);	/* low bit 0: leftmost/oldest */
            ccn_charbuf_append_closer(templ); /*<ChildSelector>*/
            ccn_charbuf_append_tt(templ, CCN_DTAG_AnswerOriginKind, CCN_DTAG);
            ccn_charbuf_append_tt(templ, 1, CCN_UDATA);
            ccn_charbuf_append(templ, "0", 1);
            ccn_charbuf_append_closer(templ); /* </AnswerOriginKind> */
            ccn_charbuf_append_closer(templ);
            res = ndn_make_remote_path(path, it.value());
            if (res >= 0) {
                if (it.value()->data_buf.callback->p == NULL) abort();
                res = ccn_express_interest(ndnState.ccn, path, it.value()->data_buf.callback, templ);
				qWarning("Expressing Interest %s\n", ccn_charbuf_as_string(path));
                it.value()->interested = 1;
            }
            if (res < 0)
                ndnState.ccn_debug_print("IFAILED");
            ccn_charbuf_destroy(&path);
            ccn_charbuf_destroy(&templ);
        }
    }
    return res;
}

int NdnMediaProcess::ndn_wait_message(UserDataBuf *userBuf, char *buf, int len)
{
    if (ndnState.ccn == NULL || userBuf == NULL) {
        errno = 9; //EBADFD;
        return(-1);
    }
    if (userBuf->data_buf.buflist == NULL) {
        errno = EAGAIN;
        len = -1;
    }
    else {
        struct buf_list *b = userBuf->data_buf.buflist;
        userBuf->data_buf.buflist = b->link;
        if (b->len < len)
            len = b->len;
        memcpy(buf, b->buf, len);
		qWarning("received data with length %d\n", len);
        free(b->buf);
        b->buf = NULL;
        b->len = 0;
        free(b);
        b = NULL;
    }
    return(len);
}

int NdnMediaProcess::startThread() {
    struct ccn *h;

    pthread_mutex_lock(&ndnState.ndn_lock);
    /* Shut down any lingering session */
    while (ndnState.ccn != NULL) {
        ndnState.active = 0;
        printf("waiting for old session to die\n");
        pthread_cond_wait(&ndnState.changed, &ndnState.ndn_lock);
    }
    h = ccn_create();
    if (ccn_connect(h, NULL) == -1) {
        ccn_perror(h, "Failed to contact ccnd");
        //ccn_state.active_session = NULL;
        ccn_destroy(&h);
        pthread_mutex_unlock(&ndnState.ndn_lock);
        return (-1);
    }
     
    ndnState.ccn = h; 
    //ndnState.active = 1;
 
    if (! isRunning()) {
        printf("Starting voice thread"); 
        ndnState.active = true;

        start(QThread::HighestPriority);
#ifdef Q_OS_LINUX
        int policy;
        struct sched_param param;
        if (pthread_getschedparam(pthread_self(), &policy, &param) == 0) {
            if (policy == SCHED_OTHER) {
                policy = SCHED_FIFO;
                param.sched_priority = 1;
                pthread_setschedparam(pthread_self(), policy, &param);
            }
        }
#endif
    }
    pthread_mutex_unlock(&ndnState.ndn_lock);
    return 0;
}

int NdnMediaProcess::stopThread() {

    pthread_mutex_lock(&ndnState.ndn_lock);
    /* Shut down any lingering session */
    while (ndnState.ccn != NULL) {
        ndnState.active = false;
        printf("waiting for old session to die\n");
        pthread_cond_wait(&ndnState.changed, &ndnState.ndn_lock);
    }

    ndnState.active = false;
    if (isRunning()) {
        printf("Ending voice thread");

    }
    pthread_mutex_unlock(&ndnState.ndn_lock);
}

void NdnMediaProcess::run() {
    int res = 0;

    for(;;) {
        //pthread_mutex_lock(&ndnState.ndn_lock);
        if (ndnState.active != 0) {
            
            /* check each local user's buffer to find out if there are some packets 
             * to be sent.If have, send it. */ 
            doPendingSend();
           
            /* find the new or resetted remote user in the remote user list,send the 
             * first interest for the user.*/
            checkInterest();
        }
        else /* other module has stopped this thread */
            res = -1;
        //pthread_mutex_unlock(&ndnState.ndn_lock);

        if (res >= 0) {
            /* wait for content coming for 5 ms. After being received, a content packet will
             * be cached in the remote user's buffer. Then the next Interest for the remote user
             * will be sent immediately*/
            res = ccn_run(ndnState.ccn, 5);
        }
        if (res < 0)
            break;
    }
    
    pthread_mutex_lock(&ndnState.ndn_lock);
    ccn_destroy(&ndnState.ccn);
    ndnState.ccn = NULL;
    /*This thread has stopped, so notify other modules*/
    pthread_cond_broadcast(&ndnState.changed);
    pthread_mutex_unlock(&ndnState.ndn_lock);
}

int NdnMediaProcess::sendLocalMedia(QString &strUserName, char *msg, int msg_len)
{
    int len, res;

    QMutexLocker qml(&LUsersLock);
    UserDataBuf *p = qmLocalUser.value(strUserName); 
    if (p == NULL) return -1;
    res = ndnDataSend(p, msg, msg_len);

    if (res >= 0) {
		ndnState.ccn_debug_print("d");
        res = len;
    }
    else {
		ndnState.ccn_debug_print("(dx)");
        errno = EAGAIN;
        res = -1;
    }
    return(res);
}

int NdnMediaProcess::getRemoteMedia(QString strUserName,char* msg, int msg_len)
{
    int res;

    QMutexLocker qml(&RUsersLock);
    UserDataBuf *p = qmRemoteUser.value(strUserName); 
    res = ndn_wait_message(p, msg, msg_len);

    if (res < 0) {
        if (ndnState.ccn_debug_print_enabled >= 'v')
            ndnState.ccn_debug_print("(DX)");
        errno = EAGAIN;
    } else {
        ndnState.ccn_debug_print("D");
	}
    return(res);
}


