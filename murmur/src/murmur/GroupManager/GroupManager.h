#ifndef _GROUPMANAGER_H
#define _GROUPMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/x509.h>
#include <openssl/aes.h>
#include <openssl/hmac.h>
#include <ccn/ccn.h>
#include <ccn/bloom.h>
#include <ccn/charbuf.h>
#include <ccn/keystore.h>
#include <ccn/signing.h>
#ifdef __cplusplus
}
#endif

#include "murmur_pch.h"
#include "RemoteUser.h"
#include "ServerUser.h"
#include "../MediaProcess/media_pro.h"

class NdnContext: public QObject {
    private:
        Q_OBJECT
        Q_DISABLE_COPY(NdnContext)
    protected:
        QMutex *pNdnMutex;

    public:
        NdnContext();
        ~NdnContext() { ccn_free(); assert(pNdnMutex); delete pNdnMutex; }

        // exclusion filter should be adjusted here
        void sendEnumerationInterest(QString channel, QString userName);
        struct ccn_charbuf *make_interest_template();

        void sendRefreshInterest(QString channel, QString userName);

        bool isEnumerationInterest(ccn_upcall_info *info, const char *channel);
        bool isRefreshInterest(ccn_upcall_info *info, const char *channel);

        void mutexLock() { assert(pNdnMutex); pNdnMutex->lock(); }
        void mutexUnlock() { assert(pNdnMutex); pNdnMutex->unlock(); }
        int get_public_key(struct ccn_pkey **pkeyp, const char *, const char *);

    private:
        int ccn_init();
        int ccn_open();
        int ccn_free();
        int ccn_publish_key(const char *, const char *);

    public:
        struct ccn *ccn;
    private:
        struct ccn_closure *refresh_closure;
        struct ccn_closure *join_closure;
        struct ccn_closure *req_closure;
        struct ccn_bloom   *exclusive_filter;
};

class GroupManager: public QThread {
    private:
        Q_OBJECT
        Q_DISABLE_COPY(GroupManager)

    friend class NdnContext; 

    protected:
        bool bRunning;
        QMutex LUserMutex;
        QMutex RUserMutex;

        void StartThread();
        void StopThread();
    public:
        void run();
        void log(const QString &msg);

    public:
        GroupManager(NdnMediaProcess* pNdnMediaPro);
        ~GroupManager();

        /* Public interface for other modules to acquire
         * a list of active users
         */
        QHash<QString, RemoteUser *> getRemoteUsers() { return qhRemoteUsers; };
        RemoteUser *getRemoteUser(QString user) { return qhRemoteUsers[user]; };
        char *localUserName() { return strrchr(localPrefix, '/') + 1; }

        /* Start user enumeration when the user enters
         * a new channel (join a new call)
         */
        int userEnterChannel(QString channel, QString userName);

        void initLocalUser(ServerUser *u);
        void addLocalUser(ServerUser *u);
        void delLocalUser(ServerUser *u);
        
        // set the local proxy ServerUser, only call when the first user enters the channel 
        void setLocalUser(ServerUser *u);
        // reset the local proxy with a valid ServerUser
        void resetLocalUser(ServerUser *u);

        bool matchLocalUser(ServerUser *u) {return (localUser == u);}
        bool localUserExist(QString prefix, QString name);
        QString getFullLocalName(QString name); 

        int addRemoteUser(QString prefix, QString userName);
        bool remoteUserExist(QString prefix, QString name);

        /* convert userlist to xml encoded format
         * <list>
         * <user><username>name</username><prefix>prefix</prefix></user>
         * <user>......</user>
         * </list>
         */ 
        void userListtoXml(const char **);
        int parseXmlUserList(const unsigned char *incoming_data);

    signals:
        /* signal to notify other modules that 
         * a new user joined this call
         */
        void remoteUserJoin(RemoteUser *);

        /* signal to notify other modules that
         * a user has left the call
         */
        void remoteUserLeave(int);

        /* signal to notify other modules that 
         * the user has changed its channel;
         * this will not be implemented for now
         */
        void channelChanged();

    public slots:
        /* slots to handle userHasLeft signal sent by RemoteUser;
         * will delete this RemoteUser and propagate this change
         * to client and other modules
         */
        void deleteRemoteUser(QString);

        // send out refresh interest when timer goes off
        void sendRefreshInterest();

    public:
        static const int MAX_LENGTH = 400;
        static const char broadcastPrefix[MAX_LENGTH];
        static const int REFRESH_INTERVAL = 12;

        // useful for localUser to notify other users in its lifetime
        QTimer *refreshTimer;

        // channel name; should always be "root" for now
        char channelComp[MAX_LENGTH];

        /* the connection information about the local user
         * this is needed to notify the local user about the
         * status of remote users
         */
        ServerUser *localUser;

        NdnContext *pNdnContext;

        /* senwang*/
        NdnMediaProcess *pNdnMediaPro;  

    private:
        // name prefix used by local user
        char localPrefix[MAX_LENGTH];

        // tracks the list of active remote users
        QHash<QString, RemoteUser *> qhRemoteUsers;
        QQueue<int> qqRSesIds;

        // a copy list of active local users
        QList<QString> qlLocalUsers;
};
        
#else
class GroupManager;
#endif
