#ifndef MEDIA_PRO_H
#define MEDIA_PRO_H

#include "murmur_pch.h"

#ifdef   __cplusplus 
extern "C" { 
#endif 
#include "pthread.h"
#include <ccn/ccn.h>
#include <ccn/charbuf.h>
#include <ccn/keystore.h>
#ifdef   __cplusplus 
} 
#endif 

struct buf_list {
    void *buf;
    size_t len;
    struct buf_list *link;
};

class NDNState;
struct data_buffer {
    struct ccn_closure *callback;
    NDNState *state;
    char direction[5];
    unsigned seq;
    struct buf_list *buflist;

    //char proto[5];
    //pthread_cond_t changed;    
    //int waiters;
    //int have_data;
};

enum UserType{REMOTE_USER, LOCAL_USER};

class UserDataBuf:public QObject{
    private:
        Q_OBJECT;
        Q_DISABLE_COPY(UserDataBuf);

    private:   
    static const int MAX_SEG_NUM = 40;
    static const int MAX_LENGTH = 40;

    public:
    UserDataBuf() {
        interested = 0;    
        iSegNum = 0;
        iNeedDestroy = 0;

        /*allocate memory for ccn_closure, we don't need to free it, for the ccn stuff will do that*/
        data_buf.callback = (struct ccn_closure *)malloc(sizeof(struct ccn_closure));
    };

    ~UserDataBuf() { 
       struct buf_list *p = NULL, *pBuf = data_buf.buflist;
       while (pBuf != NULL) {
            p = pBuf->link;
            free(pBuf->buf);
            free(pBuf);
            pBuf = p;
       }
       iSegNum = 0;
    };
    
    int splitUserName();
    public:
    /*the owner name of this buffer*/
    QString user_name;
    /*data buffer for caching the ongoing/incoming packet*/
    struct data_buffer data_buf;
    /*user type: REMOTE_USER, LOCAL_USER*/
    int user_type;
    /*the flag for identifying whether this user is a newcomer*/
    int interested;

    /* flag to indicate this buf has detached with a user */
    int iNeedDestroy;

    char szNameSeg[MAX_SEG_NUM][MAX_LENGTH];
    unsigned int iSegNum;
};


class NDNState:public QObject{
    private:
        Q_OBJECT;
        Q_DISABLE_COPY(NDNState);

    public:
    /*flag indicating whether the ccn connection is alive*/
    int active;
    /*signal for notifying other module changes of ccn connection*/
    pthread_cond_t changed;
    /*lock for CCN connection*/
    pthread_mutex_t ndn_lock;
    /*CCN(NDN) connection*/
    struct ccn *ccn;
    struct ccn_closure rtp_pipeline_callback;

    /*send interest with seq x plus hint_ahead ahead of content with seq x being received */
    int hint_ahead;                                                                  
    /*the flag to open/close the debug output*/
    int ccn_debug_print_enabled;

    public:
    NDNState() {
        active = false;
        ccn = NULL;
        pthread_cond_init(&changed, NULL);
        memset(&ndn_lock, 0, sizeof(ndn_lock));
    };

    ~NDNState() {};

    void ccn_debug_print(char *w);

    void emitSignal(QString strUserName) {
        emit remoteMediaArrivalSig(strUserName);
    };

    signals:
    void remoteMediaArrivalSig(QString); 
    /* after receiving a media packet of remote users, this signal will be emitted to notify
     * other module to get it.
     */

};

class NdnMediaProcess:public QThread {
    private:
        Q_OBJECT;
        Q_DISABLE_COPY(NdnMediaProcess);

    public: 
    /* the data structure for maintaining ccn API related stuff*/
    NDNState ndnState; 
    
    private:
    /* the remote user map */
    QHash<QString, UserDataBuf *> qmRemoteUser;

    /* for this thread will use this map for lookuping
     * other thread may invoke the functions (e.g. addRemoteUser)
     * to change the map, we need a lock.
     */
    QMutex RUsersLock;

    /* the local user list */
    QHash<QString, UserDataBuf *> qmLocalUser;
    /* the lock of local user map*/
    QMutex LUsersLock;
    
    private:
    /* cache the packet in buffer waiting for working thread sending*/
    int ndnDataSend(UserDataBuf *userBuf, const void *buf, size_t len);

    /*get the data from the buffer, do not block if there are no data actually*/
    int ndn_wait_message(UserDataBuf *userBuf, char *msg, int msg_len);

    /* check each local user's buffer to find out if there are some packets 
     * to be sent.If have, send it.
     */
    int doPendingSend();

    /* find the new or resetted remote user in the remote user list,send the 
     * first interest for the user.
     */
    int checkInterest();

    /*output some debug information*/
    void ccn_debug_print(char *w);

    public:
    /*Initate some internal data structure*/
    NdnMediaProcess();
    ~NdnMediaProcess();

    /* realize the virtul function of Othread run()
     * main body of the new thread which is responsible for sending 
     * pending media packets and interests and receiving media contents 
     * corresponding to interests which has been sent.
     */
    void run();

    /*start the working thread*/
    int startThread();
    /*stop the working thread*/
    int stopThread();
    
    /* add a remote user to this module. the function will allocte a buffer
     * for incoming media data. 
     * strUserName is the NDN name of the remote user.
     */
    void addRemoteUser(QString strUserName);

    /* delete a remote user from this module and withdraw the buffer allocated 
     * to the user.
     */
    void deleteRemoteUser(QString strUserName);

    /* add a local user to this molude. a buffer will be allocte to this 
     * local user for outgoing media data. 
     * strUserName is the NDN name of the local user.
     */
    void addLocalUser(QString strUserName);

    /* delete local user from this module and withdraw the buffer allocated 
     * to the user.
     */
    void deleteLocalUser(QString strUserName);

    /* this function stores the media data of local users to the buffer,then 
     * the caller of this function can return. the work thread is in charge of sending 
     * the data actually.
     */
    int sendLocalMedia(QString &strUserName, char *msg, int msg_len);

    /* get a media packet of some remote user, this function will get a oldest data packet from 
     * the remote user's buffer. the caller will not be blocked, because before calling this 
     * funtion, it must have received the remodeMediaArrivalSig signal
     */  
    int getRemoteMedia(QString strUserName, char *msg, int msg_len);

};
#endif 
