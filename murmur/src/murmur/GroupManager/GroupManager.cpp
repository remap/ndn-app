#include <cstring>
#include <ctime>
#include "murmur_pch.h"
#include "GroupManager.h"
#include "Server.h"

#define DEBUG

#ifdef DEBUG
#define DPRINT(fmt, ...)                                          \
{                                                                 \
    fprintf(stderr, "[%s:%d:%s] ", __FILE__, __LINE__, __func__); \
    fprintf(stderr, fmt, ##__VA_ARGS__);                          \
    fprintf(stderr, "\n");                                        \
}
#else
#define DPRINT(fmt, ...)                                          \
{                                                                 \
    fprintf(stderr, fmt, ##__VA_ARGS__);                          \
    fprintf(stderr, "\n");                                        \
}
#endif

#define MAX_LENGTH GroupManager::MAX_LENGTH

struct ccn_bloom {
    int n;
    struct ccn_bloom_wire *wire;
};

char LocalSharingPrefix[512]= "/";
const int ESTUSERS = 20;
const unsigned char SEED[] = "1412";

static ccn_keystore *cached_keystore = NULL;
static GroupManager *pGroupManager = NULL;

enum HandlerType{INTEREST, CONTENT, NONE};

static void setClosureHandler(ccn_closure **fp, HandlerType t);
static enum ccn_upcall_res incoming_content(ccn_closure *selfp, 
                            ccn_upcall_kind kind, 
                            ccn_upcall_info *info);
static enum ccn_upcall_res incoming_interest(ccn_closure *selfp, 
                            ccn_upcall_kind kind, 
                            ccn_upcall_info *info);
static enum ccn_upcall_res handler_test(ccn_closure *selfp,
                                  ccn_upcall_kind kind,
                                  ccn_upcall_info *info);

static void append_bloom_filter(ccn_charbuf *templ, ccn_bloom *b);
static int ccn_interest_get_filter(const ccn_upcall_info *info,
                            const unsigned char **value, size_t *size);

static void ccn_name_append_prefix(ccn_charbuf *buf, const char *prefix);
static void ccn_name_get_prefix(ccn_upcall_info *info, const unsigned char **data, int start, int end);

static void init_cached_keystore();
static const ccn_pkey *get_my_private_key();
static const ccn_pkey *get_my_public_key();
static const unsigned char *get_my_publisher_key_id();
static ssize_t get_my_publisher_key_id_length();

static int ccn_create_keylocator(ccn_charbuf *c, const ccn_pkey *k);

static ccn_charbuf *create_passive_templ();

static ccn_charbuf *create_passive_templ() {
	ccn_charbuf *templ = ccn_charbuf_create();
	ccn_charbuf_append_tt(templ, CCN_DTAG_Interest, CCN_DTAG); // <interest>
	ccn_charbuf_append_tt(templ, CCN_DTAG_Name, CCN_DTAG); // <name>
	ccn_charbuf_append_closer(templ); // </name>
	ccn_charbuf_append_tt(templ, CCN_DTAG_AnswerOriginKind, CCN_DTAG); // <AnswerOriginKind>
	ccn_charbuf_append_tt(templ, 1, CCN_UDATA);
	ccn_charbuf_append(templ, "1", 1);
	ccn_charbuf_append_closer(templ); // </AnswerOriginKind>
	ccn_charbuf_append_closer(templ); // </interest>
	return (templ);
}



/*
 * set ccn_closure handler according HandlerType
 */
static void setClosureHandler(ccn_closure **fp, HandlerType t) {
    ccn_closure *clp = static_cast<ccn_closure *>(calloc(1, sizeof(ccn_closure)));
    switch (t) {
    case INTEREST:
        clp->p = &incoming_interest;
        break;
    case CONTENT:
    case NONE:
        clp->p = &incoming_content;
        break;
    default:
        clp->p = &handler_test;
        break;
    }
    *fp = clp;
}

/*
 * A ccn hanler, just for test, or you can change it to 
 * fit other purpose
 */
static enum ccn_upcall_res handler_test(ccn_closure *selfp,
                                  ccn_upcall_kind kind,
                                  ccn_upcall_info *info)
{
    (void)selfp;
    (void)info;

    DPRINT("test ccn_closure handler");
    switch (kind) {
    case CCN_UPCALL_FINAL:
        DPRINT("handler_test(): CCN_UPCALL_FINAL");
        return (CCN_UPCALL_RESULT_OK);
    case CCN_UPCALL_INTEREST_TIMED_OUT:
        DPRINT("handler_test(): CCN_UPCALL_INTEREST_TIMED_OUT");
           
        return (CCN_UPCALL_RESULT_OK);
    case CCN_UPCALL_CONTENT:
    case CCN_UPCALL_CONTENT_UNVERIFIED:
        DPRINT("handler_test(): CCN_UPCALL_CONTENT");
        return (CCN_UPCALL_RESULT_OK);
    default:
        DPRINT("handler_test(): default");
        return (CCN_UPCALL_RESULT_ERR);
    }
    return (CCN_UPCALL_RESULT_OK);   
}

static void append_bloom_filter(ccn_charbuf *templ, ccn_bloom *b) {
    ccn_charbuf_append_tt(templ, CCN_DTAG_Exclude, CCN_DTAG);
    ccn_charbuf_append_tt(templ, CCN_DTAG_Bloom, CCN_DTAG);
    int wireSize = ccn_bloom_wiresize(b);
    ccn_charbuf_append_tt(templ, wireSize, CCN_BLOB);
    ccn_bloom_store_wire(b, ccn_charbuf_reserve(templ, wireSize), wireSize);
    templ->length += wireSize;
    ccn_charbuf_append_closer(templ);
    ccn_charbuf_append_closer(templ);
}

static int ccn_interest_get_filter(const ccn_upcall_info *info,
        const unsigned char **data, size_t *data_size) {
    ccn_buf_decoder decoder;
    ccn_buf_decoder *d;
    d = ccn_buf_decoder_start(&decoder,
                              info->interest_ccnb + info->pi->offset[CCN_PI_B_Exclude],
                              info->pi->offset[CCN_PI_E_Exclude] - info->pi->offset[CCN_PI_B_Exclude]);
    if (!ccn_buf_match_dtag(d, CCN_DTAG_Exclude))
        return -1;
    ccn_buf_advance(d);
    if (ccn_buf_match_dtag(d, CCN_DTAG_Bloom)) {
        ccn_buf_advance(d);
        if (ccn_buf_match_blob(d, data, data_size))
            ccn_buf_advance(d);
        ccn_buf_check_close(d);
    }    
    return 0;
}


static void ccn_name_get_prefix(ccn_upcall_info *info, const unsigned char **data, int start, int end) {
    int i = start;
    size_t len = 0;
    unsigned char *temp = (unsigned char *)calloc(256, sizeof(unsigned char));
    unsigned char *sptr = temp;
    const unsigned char *ptr = NULL;
    while (i <= end) {
        *temp++ = '/';
        ccn_name_comp_get(info->interest_ccnb, info->interest_comps, i, &ptr, &len);
        memcpy(temp, ptr, len);
        temp = temp + len;
        ptr = NULL;
        ++i;
    }
    *temp = '\0';
    *data = sptr;
}

static void ccn_name_append_prefix(ccn_charbuf *buf, const char *prefix) {
    static char temp[MAX_LENGTH];
    char *dst = temp;
    const char *src = prefix + 1;
    while (*src) {
        if (*src != '/' && *(src + 1) != '\0') {
                *dst++ = *src++;
        } else {
            if (*(src + 1) == '\0' && *src != '/') {
                *dst++ = *src;
            }
            *dst = '\0';
            dst = temp;
            ccn_name_append_str(buf, dst);
            src++;
        }
    }
}

const char GroupManager::broadcastPrefix[MAX_LENGTH] = "/ndn/broadcast/conference/";

GroupManager::GroupManager(NdnMediaProcess *pNdnMediaPro) {

    DPRINT("Initialize GroupManager Module");

    pGroupManager = this;
    const char *env_LOCAL_PREFIX = NULL;
    env_LOCAL_PREFIX = getenv("LOCAL_PREFIX");
    if (env_LOCAL_PREFIX != NULL && env_LOCAL_PREFIX[0] != 0)
        strncpy(LocalSharingPrefix, env_LOCAL_PREFIX, sizeof(LocalSharingPrefix) - 1);    

    this->pNdnMediaPro = pNdnMediaPro;
    // fill localuser sharing prefix
    int len = strlen(LocalSharingPrefix);
	if (LocalSharingPrefix[len - 1] != '/') {
		LocalSharingPrefix[len++] = '/';
		LocalSharingPrefix[len] = '\0';
	}
    char *ptr = localPrefix;
    memcpy(ptr, LocalSharingPrefix, len);
    *(ptr + len) = '\0';

    // fill channel, current only "root" supported
    strcpy(channelComp, "root");

    /* Local ServerUser, get information from server
     * let the first user enter server be the
     * agent of the GroupManager
     */
    localUser = NULL;

    // ui_session id for remoteUsers
    for (int i = 5001; i < 10000; ++i)
        qqRSesIds.enqueue(i);

    refreshTimer = new QTimer(this);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(sendRefreshInterest()));  

}

GroupManager::~GroupManager() {

    delete pNdnContext;
    if (refreshTimer != NULL) {
        refreshTimer->stop();
        delete refreshTimer;
        refreshTimer = NULL;
    }

    pGroupManager = NULL;
    StopThread();
}

void GroupManager::StopThread() {

    bRunning = false;
    if (isRunning()) {
		log("Ending Userlist Handling thread");
		wait();
    }
}

void GroupManager::log(const QString &msg) {
    qWarning("localPrefix<%s> => %s\n", localPrefix, msg.toLocal8Bit().constData());
}

void GroupManager::StartThread() {
	if (! isRunning()) {
		log("Starting Userlist Handling thread");
		bRunning = true;

        pNdnContext = new NdnContext;

        // start or restart the refreshTimer for current localUser 
        refreshTimer->start(REFRESH_INTERVAL * 1000);

		start(QThread::HighestPriority);
#ifdef Q_OS_LINUX
		// QThread::HighestPriority == Same as everything else...
		int policy;
		sched_param param;
		if (pthread_getschedparam(pthread_self(), &policy, &param) == 0) {
			if (policy == SCHED_OTHER) {
				policy = SCHED_FIFO;
				param.sched_priority = 1;
				pthread_setschedparam(pthread_self(), policy, &param);
			}
		}
#endif
	}
}

void GroupManager::run() {
    int res = 0;
    while (bRunning) {
        if (res >= 0) {
            pNdnContext->mutexLock(); 
            res = ccn_run(pNdnContext->ccn, 5);
            pNdnContext->mutexUnlock(); 

            // give other thread chance to hold the lock
            usleep(2);
        }
    }
}

QString GroupManager::getFullLocalName(QString name) {
    QString temp = QString(LocalSharingPrefix) + name;
    return temp;
}

bool GroupManager::localUserExist(QString prefix, QString name) {
    if ((prefix != QString(LocalSharingPrefix))) return false;

    LUserMutex.lock();
    if (qlLocalUsers.contains(name)) return true;
    LUserMutex.unlock();
    return false;
}
void GroupManager::initLocalUser(ServerUser *u) {

    localUser = u;

    // update localPrefix, append or replace localUserName 
    log("initLocalUser(): update localPrefix");
    char *ptr = strrchr(localPrefix, '/') + 1;
    QByteArray qba = (u->qsName).toLocal8Bit();
    int len = qba.size();

    memcpy(ptr, qba.constData(), len);
    ptr += len;
    *ptr = '\0';

}

void GroupManager::setLocalUser(ServerUser *u) {
    /* assign u to localUser, this is the first user enter
     * the channel, or any other valid user
     */
    initLocalUser(u); 
    QString temp = QString(LocalSharingPrefix) + u->qsName;
    pNdnMediaPro->addLocalUser(temp);

    LUserMutex.lock();
    qlLocalUsers.append(u->qsName);
    LUserMutex.unlock();

    StartThread();
    userEnterChannel(QString(channelComp), u->qsName);
}

/* 
 * Param ServerUser being NULL implies no localUser connected
 * to this server any longer
 * not NULL indicates either this is the first user connected
 * to this server or it is a live user purposing for replacing
 * previous assigned localUser which has left the channel
 */
void GroupManager::resetLocalUser(ServerUser *u) {
    if (u == NULL) {// no localUser exists any longer
        StopThread();
        localUser = NULL;
        return;
    }
    /* assign u to localUser, could be the first user enter
     * the channel, or any other valid user
     */
    initLocalUser(u); 
}

void GroupManager::addLocalUser(ServerUser *u) {
    // another user enter the channel, or any other valid user

    QString temp = QString(LocalSharingPrefix) + u->qsName;
    pNdnMediaPro->addLocalUser(temp);
    LUserMutex.lock();
    qlLocalUsers.append(u->qsName);
    LUserMutex.unlock();
    
    userEnterChannel(QString(channelComp), u->qsName);
}

void GroupManager::delLocalUser(ServerUser *u) {
    for (int i = 0; i < qlLocalUsers.size(); ++i)
        if (qlLocalUsers.at(i) == u->qsName) {

            QString temp = QString(LocalSharingPrefix) + u->qsName;
            pNdnMediaPro->deleteLocalUser(temp);

            LUserMutex.lock();
            qlLocalUsers.removeAt(i);
            LUserMutex.unlock();
        }
}

int GroupManager::addRemoteUser(QString prefix, QString userName) {

    if (localUserExist(prefix, userName)  // not local
            || remoteUserExist(prefix, userName))  // already add remoteUser
        return -1;

    QString temp = QString(prefix) + userName;
    pNdnMediaPro->addRemoteUser(temp);

    log(QString("addRemoteUser(%1, %2)").arg(prefix).arg(userName));
    RemoteUser *u = new RemoteUser(prefix, userName);
    u->uiSession = qqRSesIds.dequeue();
    u->moveToThread(this->thread());
    u->cChannel = localUser->cChannel;
    connect(u, SIGNAL(userHasLeft(QString)), this, SLOT(deleteRemoteUser(QString)));

    RUserMutex.lock();
    qhRemoteUsers.insert(userName, u);
    RUserMutex.unlock();
    
    // fire a signal to notify other modules that a new user joins the call
    emit remoteUserJoin(u);
    return 0;
}

bool GroupManager::remoteUserExist(QString prefix, QString remoteUser) {

	bool bExist = true;

    RUserMutex.lock();
	QHash<QString, RemoteUser *>::const_iterator it = qhRemoteUsers.find(remoteUser);
    RUserMutex.unlock();
	
	if (it == qhRemoteUsers.constEnd()) {
		bExist = false;
	}
	else {
		RemoteUser *u = it.value();
		if (prefix != u->getPrefix())
			bExist = false;
	}

    return bExist;
}

void GroupManager::deleteRemoteUser(QString remoteUser) {
    log(QString("deleteRemoteUser(%1)").arg(remoteUser));

    RemoteUser *u = NULL;

    RUserMutex.lock();
    u = qhRemoteUsers[remoteUser];
    if (u == NULL) {
        RUserMutex.unlock();
        return; 
    }
    qhRemoteUsers.remove(remoteUser);
    RUserMutex.unlock();

    QString temp = QString(u->getPrefix()) + u->qsName;
    pNdnMediaPro->deleteRemoteUser(temp);

    qqRSesIds.enqueue(u->uiSession);
    emit remoteUserLeave(u->uiSession);
    delete u;
}

/* User send a enumeration interest to start getting 
 * already existing user list when enter a channel
 */
int GroupManager::userEnterChannel(QString channel, QString userName) {
    log(QString("userEnterChannel(%1): send first enumeration interest").arg(channel));
    pNdnContext->sendEnumerationInterest(channel, userName);
    return 0;
}

static inline void xmlEncoding(QString &qsData, const QString userName, const QString prefix) {
    qsData.append("<user>");
    qsData.append("<username>");
    qsData.append(userName);
    qsData.append("</username>");
    qsData.append("<prefix>");
    qsData.append(prefix);
    qsData.append("</prefix>");
    qsData.append("</user>");
}

void GroupManager::userListtoXml(const char **data) {
    // append remoteUsers
    log("userListtoXml():encoding user list to XML format");
    QString qsData;
    qsData.append("<list>");
    QHashIterator<QString, RemoteUser *> it(qhRemoteUsers);
    while (it.hasNext()) {
        it.next();
        xmlEncoding(qsData, it.key(), it.value()->getPrefix());
    }

    // append localUsers
    for (int i = 0; i < qlLocalUsers.size(); ++i) {
        xmlEncoding(qsData, qlLocalUsers.at(i), LocalSharingPrefix);
    }
    qsData.append("</list>");

    QByteArray qba = qsData.toLocal8Bit();
    char *buffer = static_cast<char *>(calloc(qba.size() + 1, sizeof(char)));
    memcpy(buffer, qba.constData(), qba.size());
    buffer[qba.size()] = '\0';
    *data = buffer;
}

int GroupManager::parseXmlUserList(const unsigned char *incoming_data) {

    QByteArray buffer((const char *)(incoming_data));
    QDomDocument doc;
    if (!doc.setContent(buffer)) {
        log("Cannot convert data to xml\n");
        return -1;
    }
   
    QString username, prefix;
    QDomElement docElem = doc.documentElement();  // <list>
    QDomNode node = docElem.firstChild();  // <user>
    while (!node.isNull()) {
        if (node.nodeName() != "user")
            return -1;
        node = node.firstChild();  // <username>
        if (node.nodeName() != "username")
            return -1;
        username = node.toElement().text();
        node = node.nextSibling();  // <prefix>
        if (node.nodeName() != "prefix")
            return -1;
        prefix = node.toElement().text();
        addRemoteUser(prefix, username);
        node = node.parentNode();  // <user>
        node = node.nextSibling(); // <user>
    }
    return 0;
}
void GroupManager::sendRefreshInterest() {
    LUserMutex.lock();
    for (int i = 0; i < qlLocalUsers.size(); ++i) {
        pNdnContext->sendRefreshInterest(channelComp, qlLocalUsers.at(i));
    }
    LUserMutex.unlock();
}

NdnContext::NdnContext() { 
    // install ccn routing agent
    ccn_init();

    pNdnMutex = new QMutex(QMutex::Recursive);
    ccn_open();
    assert(ccn);
}

int NdnContext::ccn_init() {

    ccn = NULL;
    req_closure = NULL;
    join_closure = NULL;
    refresh_closure = NULL;
    cached_keystore = NULL;

    exclusive_filter = ccn_bloom_create(ESTUSERS, SEED);
    if (exclusive_filter == NULL) {
        DPRINT("Failed to initialize ccn bloom filter");
        return -1;
    }

    ccn = ccn_create();
    if (ccn == NULL || ccn_connect(ccn, NULL) == -1) {
        if (ccn == NULL) {
            DPRINT("ccn_create() failed");
        } else {
            system("/usr/local/bin/ccndstart");
            usleep(1000);
            // try reconnectting
            ccn_connect(ccn, NULL);
        }
        DPRINT("Failed to initialize ccn agent connection");
        return -1;
    }
    return 0;
}    

int NdnContext::ccn_free() {

    if (ccn != NULL) {
        ccn_disconnect(ccn);
        ccn_destroy(&ccn);
    }

    if (exclusive_filter != NULL) ccn_bloom_destroy(&exclusive_filter);
    if (cached_keystore == NULL) ccn_keystore_destroy(&cached_keystore);
    if (refresh_closure != NULL) {
        free(refresh_closure);
        refresh_closure = NULL;
    }
    if (join_closure != NULL) {
        free(join_closure);
        join_closure = NULL;
    }
    if (req_closure != NULL) {
        free(req_closure);
        req_closure = NULL;
    }

    return 0;
}

int NdnContext::ccn_open() {
    ccn_charbuf *interest_filter_path;

#if 0
    /* We need to publish our public key. */
    if (0 != ccn_publish_key()) {
        DPRINT("Failed to publish server key to CCN.\n");
        /* go on anyway */
    } else {
        DPRINT("Published server key to CCN.\n");
    }
#endif
    /* we will process interests that indicate they are querying user list
     * or refreshing their states 
     * 1. Enumeration Interest
     *   /ndn/broadcast/conference/conf-name/requesterPrefix/<Exclusive Filter>
     *   eg:
     *   /ndn/broadcast/confrence/root/thu.edu/cs/yangxu/<exclusive_filter>
     * 2. Refresh Interest
     *   /ndn/broadcast/conference/refresh/userName
     */

    interest_filter_path = ccn_charbuf_create();
    if (interest_filter_path == NULL 
            || ccn_name_init(interest_filter_path) == -1) {
        DPRINT("Failed to allocate or initialize interest filter path");
        return -1;
    }
    ccn_name_append_prefix(interest_filter_path, GroupManager::broadcastPrefix);
    if (req_closure == NULL) {
        setClosureHandler(&req_closure, INTEREST);
    }
    ccn_set_interest_filter(ccn, interest_filter_path, req_closure);
    ccn_charbuf_destroy(&interest_filter_path);

    return 0;
}

/* Refresh Interest Format:
 *   /ndn/broadcast/conference/conf-name/refresh UserName
 * eg:
 *   /ndn/broadcast/conference/root/refresh/yangxu
 */
bool NdnContext::isRefreshInterest(ccn_upcall_info *info, const char *channel) {
    int res = 0;
    
    res = ccn_name_comp_strcmp(info->interest_ccnb, info->interest_comps, 3, channel);
    if (res != 0) {
        return false;
    }
   
    const unsigned char *temp = NULL;
    size_t len = 0;
    res =  ccn_name_comp_get(info->interest_ccnb, info->interest_comps, 4, &temp, &len);
    if (res != 0) {
        return false;
    }
    res = strncmp((const char *)temp, "refresh", len);

    return (res == 0 ? true : false);
}

/* Enumeration Interest Format:
 *   /broadcastPrefix/conf-name/localPrefix/<exclusive filter>
 * eg:
 *   /ndn/broadcast/conference/root/thu.edu/cs/yangxu/[user1]
 */
bool NdnContext::isEnumerationInterest(ccn_upcall_info *info, const char *channel) {
    return (false == isRefreshInterest(info, channel));
}

/* Start user enumeration when the user enters a new channel
 * Interest Format:
 *   /broadcastPrefix/conf-name/localPrefix
 * eg:
 *   /ndn/broadcast/conference/root/thu.edu/cs/yangxu
 */
void NdnContext::sendEnumerationInterest(QString channel, QString userName) {
    ccn_charbuf *interest_path = NULL;

    ccn_charbuf *templ = NULL;

    interest_path = ccn_charbuf_create();
    if (interest_path == NULL || ccn_name_init(interest_path) == -1) {
        return;
    }

    ccn_name_append_prefix(interest_path, GroupManager::broadcastPrefix);
    ccn_name_append_str(interest_path, channel.toLocal8Bit().constData());
    ccn_name_append_prefix(interest_path, LocalSharingPrefix);
    ccn_name_append_str(interest_path, userName.toLocal8Bit().constData());

    (pGroupManager->RUserMutex).lock();
    // update exclusive filter according to recently known remote users
    QHash<QString, RemoteUser *>::const_iterator it = (pGroupManager->qhRemoteUsers).constBegin();
    unsigned char *bloom = exclusive_filter->wire->bloom;
    memset(bloom, 0, 1024);
    while (it != (pGroupManager->qhRemoteUsers).constEnd())
    {
        QByteArray qba = it.key().toLocal8Bit();
        ccn_bloom_insert(exclusive_filter, qba.constData(), qba.size());
        ++it;
    }
    (pGroupManager->RUserMutex).unlock();

    templ = make_interest_template();
    // set interest handler
    if (join_closure == NULL) {
        setClosureHandler(&join_closure, CONTENT);
    }

    // Express enumeration interest
    pNdnMutex->lock();
    ccn_express_interest(ccn, interest_path, join_closure, templ);
    pNdnMutex->unlock();

    ccn_charbuf_destroy(&templ);
    ccn_charbuf_destroy(&interest_path);
}

/* Send refresh interest when timer goes off
 * Default Lifetime: 0x4000 <4 seconds>
 * Interest Format:
 *   /ndn/broadcast/conference/conf-name/refresh/UserPrefix/UserName
 * eg:
 *   /ndn/broadcast/conference/root/refresh/thu.edu/yangxu
 */
void NdnContext::sendRefreshInterest(QString channel, QString userName) {
    ccn_charbuf *interest_path;

    interest_path = ccn_charbuf_create();
    if (interest_path == NULL || ccn_name_init(interest_path) == -1) {
        return;
    }

    ccn_name_append_prefix(interest_path, GroupManager::broadcastPrefix);
    ccn_name_append_str(interest_path, channel.toLocal8Bit().constData());
    ccn_name_append_str(interest_path, "refresh");
	ccn_name_append_prefix(interest_path, LocalSharingPrefix);
    ccn_name_append_str(interest_path, userName.toLocal8Bit().constData());


/*
    ccn_charbuf *templ = ccn_charbuf_create();
    ccn_charbuf_append_tt(templ, CCN_DTAG_Interest, CCN_DTAG);
    ccn_charbuf_append_tt(templ, CCN_DTAG_Name, CCN_DTAG);
    ccn_charbuf_append_closer(templ);
    ccn_charbuf_append_tt(templ, CCN_DTAG_InterestLifetime, CCN_DTAG);
    ccnb_append_number(templ, 4096);
    ccn_charbuf_append_closer(templ);
    ccn_charbuf_append_closer(templ);
*/

    // Express refresh interest to notify other users in the channel
    if (refresh_closure == NULL) {
        setClosureHandler(&refresh_closure, NONE);
    }

	static ccn_charbuf *templ = NULL;
	templ = create_passive_templ();

    pNdnMutex->lock();
    //ccn_express_interest(ccn, interest_path, refresh_closure, NULL);
    ccn_express_interest(ccn, interest_path, refresh_closure, templ);
    pNdnMutex->unlock();

    ccn_charbuf_destroy(&interest_path);
    ccn_charbuf_destroy(&templ);
	templ = NULL;
}

 /* process incoming interest;
 * 1) if this is an enumeration interest, the 
 *    (username, name_prefix) pairs known to this class
 *    would be sent in the reply;
 * 2) if this is a refresh intrest, the reception time
 *    would be updated for this RemoteUser (the requestor)
 *    and no content needs to be replied
 */
static enum ccn_upcall_res incoming_interest(ccn_closure *selfp,
                                ccn_upcall_kind kind,
                                ccn_upcall_info *info)
{
    assert(pGroupManager);
    int res;

    const char *data = NULL;
    const unsigned char *requester = NULL;
    const unsigned char *refresher = NULL;
    const unsigned char *filter = NULL;
    size_t filter_len = 0;
    const unsigned char *channel = NULL;
    size_t clen = 0;

    ccn_charbuf *signed_info = NULL;
    ccn_charbuf *name = NULL;
    ccn_charbuf *content = NULL;

    RemoteUser *refreshUser = NULL;

    // requesterPrefix starts from index 4 to (info->interest_comps->n - 2)
    int nameEnd = 0;

    switch (kind) {
    case CCN_UPCALL_FINAL:
        DPRINT("invite_handler(selfp=%p, kind=%d, selfp->intdata = %d) CCN_UPCALL_FINAL",
                reinterpret_cast<void *>(selfp),
                (int)kind,
                (int)selfp->intdata);
        return (CCN_UPCALL_RESULT_OK);

    case CCN_UPCALL_INTEREST_TIMED_OUT:
        DPRINT("invite_handler(selfp=%p, kind=%d, selfp->intdata = %d) CCN_UPCALL_INTEREST_TIMED_OUT",
                (void *)selfp,
                (int)kind,
                (int)selfp->intdata);

        return (CCN_UPCALL_RESULT_OK);

    case CCN_UPCALL_INTEREST:
        /* Two types of interest need to be handler:
         * 1. Enumeration Interest
         *   /ndn/broadcast/conference/conf-name/requesterPrefix/<Exclusive Filter>
         *   eg:
         *   /ndn/broadcast/confrence/root/thu.edu/cs/yangxu/<exclusive_filter>
         * 2. Refresh Interest
         *   /ndn/broadcast/conference/conf-name/refresh/UserPrefix/userName
        */

        nameEnd = (info->interest_comps)->n - 2;
        ccn_name_comp_get(info->interest_ccnb, info->interest_comps, 3, &channel, &clen);
        if ((pGroupManager->pNdnContext)->isRefreshInterest(info, (const char *)(channel))) { // Refresh Interest

            // need to check the refresher, due to the time crossing between enumeration and refresh
            ccn_name_get_prefix(info, &refresher, 5, nameEnd);
            QString tmp((const char *)refresher);
            QString user(tmp.section('/', -1));
            tmp.chop(user.size());
            
            pGroupManager->addRemoteUser(tmp, user);

            if (refresher != NULL) {
                free((void *)refresher);
                requester = NULL;
            }

            refreshUser = pGroupManager->getRemoteUser(user);
            if (refreshUser != NULL)
                refreshUser->setLastRefreshTime();
        } else {
            /* enumeration interest
             * no exclusive filter attached implies the requester is a new comer 
             * else check whether in the exclusive filter
             * if in, then no need to reply
             * if not, then reply with known user list
             */
            
            res = ccn_interest_get_filter(info, &filter, &filter_len);
            if (res == 0) {
                ccn_bloom *b = ccn_bloom_from_wire(filter, filter_len);
                char *localer = pGroupManager->localUserName();
                if (ccn_bloom_match(b, localer, strlen(localer))) { // local user excluded
                    pGroupManager->log(QString("exclusive filter checking: user = %1<excluded>").arg(localer));
                    ccn_bloom_destroy(&b);

                    ccn_name_get_prefix(info, &requester, 4, nameEnd);
                    QString tmp((const char *)requester);
                    QString user(tmp.section('/', -1));
                    tmp.chop(user.size());
                    
                    pGroupManager->addRemoteUser(tmp, user);

                    if (requester != NULL) {
                        free((void *)requester);
                        requester = NULL;
                    }

                    return (CCN_UPCALL_RESULT_OK);
                }
                ccn_bloom_destroy(&b);
            }

            /* construct reply data
             * format:
             *   /broadcastPrefix/conf-name/requesterPrefix/knownUserList
             * eg:
             *   /ndn/broadcast/conference/root/thu.edu/cs/yangxu/localUserPrefix:user1Prefix:user2Prefix
             */
            signed_info = ccn_charbuf_create();
            res = ccn_signed_info_create(signed_info,
                    /*pubkeyid*/ get_my_publisher_key_id(),
                    /*publisher_key_id_size*/ get_my_publisher_key_id_length(),
                    /*datetime*/ NULL,
                    /*type*/ CCN_CONTENT_DATA,
                    /*freshness*/ -1,
                    /*finalblockid*/ NULL,
                    /*keylocator*/ NULL);
            if (res < 0) {
                DPRINT("FAILED TO CREATE signed_info (res == %d)", res);
            }

            name = ccn_charbuf_create();
            content = ccn_charbuf_create();
            ccn_name_init(name);
            ccn_name_append_components(name, info->interest_ccnb,
                    info->interest_comps->buf[0], info->interest_comps->buf[nameEnd + 1]);


            // get user list, the caller need to free the data buffer allocated 
            pGroupManager->userListtoXml(&data);

            ccn_encode_ContentObject(content, name, signed_info,
                    data, strlen(data), 
                    NULL, get_my_private_key());
            ccn_put(info->h, content->buf, content->length);

            ccn_charbuf_destroy(&signed_info);
            ccn_charbuf_destroy(&name);
            ccn_charbuf_destroy(&content);
            if (data != NULL) {
                free((void *)data);
                data = NULL;
            }

            ccn_name_get_prefix(info, &requester, 4, nameEnd);
            QString tmp((const char *)requester);
            QString user(tmp.section('/', -1));
            tmp.chop(user.size());
            
            pGroupManager->addRemoteUser(tmp, user);

            if (requester != NULL) {
                free((void *)requester);
                requester = NULL;
            }
        }
        return (CCN_UPCALL_RESULT_OK);

    default:
        return (CCN_UPCALL_RESULT_OK);
    }
}

static enum ccn_upcall_res incoming_content(ccn_closure *selfp,
                                  ccn_upcall_kind kind,
                                  ccn_upcall_info *info)
{
    assert(pGroupManager);

    size_t len = 0;
    const unsigned char *valuep = NULL;
    const unsigned char *channel = NULL;
    size_t clen = 0;
    const unsigned char *userName = NULL;
    size_t slen = 0;

    switch (kind) {
    case CCN_UPCALL_FINAL:
        /* this closure is no longer in use */
        return (CCN_UPCALL_RESULT_OK);
    case CCN_UPCALL_INTEREST_TIMED_OUT:
        /* An enumeration interest timeing out implies the end of 
         * the enumeration round
         * An refresh interest is expected to time out as no reply 
         * is supposed.
         */
        if (0) printf("call_handler(selfp=%p, kind=%d, selfp->intdata = %d) CCN_UPCALL_INTEREST_TIMED_OUT\n",
                      (void *)selfp,
                      (int)kind,
                      (int)selfp->intdata);
        ccn_name_comp_get(info->interest_ccnb, info->interest_comps, 3, &channel, &clen);
        if ((pGroupManager->pNdnContext)->isEnumerationInterest(info, (const char *)(channel))) { // Enumeration Interest, set local user refresh timer
            // log("EnumerationInterest timeout");
            /* User list enumeration round finished
             * start or restart the refreshTimer for current localUser 
             */
            
            /* don't reexpress the enumeration interests */
        } else {
            // log("RefreshInterest timeout");
        }
        return (CCN_UPCALL_RESULT_OK);

    case CCN_UPCALL_CONTENT:
    case CCN_UPCALL_CONTENT_UNVERIFIED:
        /* Incoming content responses to previously expressed interests */ 
        break;
    default:
        return (CCN_UPCALL_RESULT_ERR);
    }

    /* CONTENT Parsing and Handling*/
    /* get ccn content packet's real data*/
    ccn_content_get_value(info->content_ccnb, info->pco->offset[CCN_PCO_E],
                          info->pco,
                          &valuep, &len);

    /* Packet format:
     *   /broadcastPrefix/conf-name/localPrefix/<userlist>
     *      <userlist>: xml encoded list
     */
    pGroupManager->log(QString("Parsing incoming content: <%1>").arg((char *)valuep));
    
    if (-1 == pGroupManager->parseXmlUserList(valuep)) {
        pGroupManager->log("Invalid user list format received"); 
        return (CCN_UPCALL_RESULT_REEXPRESS);
    }

    // send the next enumeration interest
    ccn_name_comp_get(info->content_ccnb, info->content_comps, 3, &channel, &clen);
    ccn_name_comp_get(info->content_ccnb, info->content_comps, info->content_comps->n - 2, &userName, &slen);
    (pGroupManager->pNdnContext)->sendEnumerationInterest((const char *)(channel), (const char *)(userName));

    return (CCN_UPCALL_RESULT_OK);   
}

/*
 * make_interest_template
 * Constructs a charbuf with a ccnb encoded interest suitable
 * for use as a template, based on the uptime exclusive_filter
 * The template is
 *	<Interest>
 *		<Name></Name>
 *		<Exclude><Bloom>exclusive_filter</Bloom>
 *      </Exclude>
 *      <AnswerOriginKind>0</AnswerOriginKind>
 *	</Interest>
 */
ccn_charbuf *NdnContext::make_interest_template() {

    ccn_charbuf *templ = ccn_charbuf_create();

    ccn_charbuf_append_tt(templ, CCN_DTAG_Interest, CCN_DTAG);
    ccn_charbuf_append_tt(templ, CCN_DTAG_Name, CCN_DTAG);
    ccn_charbuf_append_closer(templ); /* </Name> */

    if (ccn_bloom_n(exclusive_filter) != 0) { 
        // exclusive_filter not empty, append it to the interest
        append_bloom_filter(templ, exclusive_filter);
    }

    ccn_charbuf_append_tt(templ, CCN_DTAG_AnswerOriginKind, CCN_DTAG);
    ccn_charbuf_append_tt(templ, 1, CCN_UDATA);
    ccn_charbuf_append(templ, "0", 1);
    ccn_charbuf_append_closer(templ); /*  </AnswerOriginKind> */

    ccn_charbuf_append_closer(templ); /* </Interest> */
    return (templ);
}

int NdnContext::ccn_publish_key(const char *prefix, const char *channel) {

    ccn_charbuf *name = NULL;
    ccn_charbuf *signed_info = NULL;
    ccn_charbuf *keylocator = NULL;
    long expire = -1;
    int res = 0;
    const ccn_pkey *pk = get_my_public_key();
    unsigned char *encoded_public_key = NULL;
    size_t encoded_public_key_len = 0;
    ccn_charbuf *message = NULL;

    if ((encoded_public_key_len = i2d_PUBKEY((EVP_PKEY *)pk, &encoded_public_key)) < 0)
        return (encoded_public_key_len);

    keylocator = ccn_charbuf_create();
    res = ccn_create_keylocator(keylocator, pk);
    if (res < 0)
        return (res);
    signed_info = ccn_charbuf_create();
    signed_info->length = 0;
    res = ccn_signed_info_create(signed_info,
                                 /*pubkeyid*/get_my_publisher_key_id(),
                                 /*publisher_key_id_size*/get_my_publisher_key_id_length(),
                                 /*datetime*/NULL,
                                 /*type*/CCN_CONTENT_KEY,
                                 /*freshness*/ expire,
                                 /*finalblockid*/NULL,
                                 /*keylocator*/keylocator);

    if (res != 0) {
        DPRINT("Failed to create signed_info (res == %d)", res);
        return res;
    }

    name = ccn_charbuf_create();
    if (name == NULL || ccn_name_init(name) == -1) {
        DPRINT("Failed to allocate or initialize key name.");
        return -1;
    }

    /* put users under keys, to make it easier to make an interest
       that watches for new data and caches it... */
    ccn_name_append_str(name, channel);
    ccn_name_append_str(name, "KEYS");
    ccn_name_append_prefix(name, prefix);

    message = ccn_charbuf_create();

    if (NULL == message) {
        DPRINT("Failed to create mesage output charbuf.");
        return -1;
    }
    res = ccn_encode_ContentObject(message,
                                   name,
                                   signed_info,
                                   encoded_public_key, encoded_public_key_len,
                                   /*algorithm*/NULL,
                                   get_my_private_key());
    if (res != 0) {
        DPRINT("Failed to encode ContentObject (res == %d)", res);
        return res;
    }
    res = ccn_put(ccn, message->buf, message->length);
    if (res < 0) {
        DPRINT("ccn_put failed (res == %d)", res);
        return res;
    }

    ccn_charbuf_destroy(&name);
    ccn_charbuf_destroy(&signed_info);
    ccn_charbuf_destroy(&keylocator);
    ccn_charbuf_destroy(&message);
    return 0;
}

/* pkeyp result of get_public_key must be ccn_pubkey_free'd by caller */
int NdnContext::get_public_key(ccn_pkey **pkeyp, const char *prefix, const char *channel) {

    ccn_charbuf *name = ccn_charbuf_create();
    int res = 0;
    ccn_parsed_ContentObject parsed = {0};
    ccn_parsed_ContentObject *pco = &parsed;
    ccn_charbuf *resultbuf = NULL;
		
    if (name == NULL || ccn_name_init(name) == -1) {
        DPRINT("Failed to allocate or initialize key name.");
        return (-1);
    }

    /* put users under keys, to make it easier to make an interest
       that watches for new data and caches it... */
    ccn_name_append_str(name, channel);
    ccn_name_append_str(name, "KEYS");
    ccn_name_append_prefix(name, prefix);
		
    resultbuf = ccn_charbuf_create();
    if (resultbuf == NULL) {
        DPRINT("Failed to allocate resultbuf for public key.");
        return (-1);
    }
    res = ccn_get(ccn, name, NULL, 3000, resultbuf, pco, NULL, 0);
    if (res < 0) {
        DPRINT("Cannot access public key for SIP via ccn");
    }
    else {
        const unsigned char *p = NULL;
        size_t size = 0;
        ccn_content_get_value(resultbuf->buf, resultbuf->length, pco, &p, &size);
        *pkeyp = ccn_d2i_pubkey(p, size);
    }
    ccn_charbuf_destroy(&name);
    ccn_charbuf_destroy(&resultbuf);
    return (res);
}

static void init_cached_keystore() {
    ccn_keystore *keystore = cached_keystore;
    int res;
    /* XXX - missing mutex? */
    if (keystore == NULL) {
	ccn_charbuf *temp = ccn_charbuf_create();
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

static const ccn_pkey *get_my_private_key() {
    /*XXX - missing mutex? */
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_private_key(cached_keystore));
}

static const ccn_pkey *get_my_public_key() {
    /*XXX - missing mutex? */
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_public_key(cached_keystore));
}

static const unsigned char *get_my_publisher_key_id() {
    /*XXX - missing mutex? */
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_public_key_digest(cached_keystore));
}

static ssize_t get_my_publisher_key_id_length() {
    /* XXX - missing mutex? */
    if (cached_keystore == NULL) init_cached_keystore();
    return (ccn_keystore_public_key_digest_length(cached_keystore));
}

static int
ccn_create_keylocator(ccn_charbuf *c, const ccn_pkey *k)
{
    int res;

    ccn_charbuf_append_tt(c, CCN_DTAG_KeyLocator, CCN_DTAG);
    ccn_charbuf_append_tt(c, CCN_DTAG_Key, CCN_DTAG);
    res = ccn_append_pubkey_blob(c, k);
    if (res < 0)
        return (res);
    else {
        ccn_charbuf_append_closer(c); /* </Key> */
        ccn_charbuf_append_closer(c); /* </KeyLocator> */
    }
    return (0);
}

