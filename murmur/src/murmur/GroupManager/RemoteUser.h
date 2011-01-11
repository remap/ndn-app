#ifndef _REMOTEUSER_H
#define _REMOTEUSER_H

#include <sys/time.h>
#include "murmur_pch.h"
#include "User.h"

class RemoteUser: public QObject, public User {
    private:
        Q_OBJECT
        Q_DISABLE_COPY(RemoteUser);
    public:
        RemoteUser(QString prefix, QString name);
        ~RemoteUser();

    public:
        const QString getPrefix() const {return remoteUserPrefix;}
        const QString getName() const {return qsName;}
        operator const QString() const;

    signals:
        /* Notify the GroupManager that this 
         * RemoteUser has left the call
         */
        void userHasLeft(QString);

    protected slots:

    public:
        /* Public interface to set refresh time 
         * Should be used by GroupManager
         */
        int setLastRefreshTime();

    protected slots:
        /* Check whether this RemoteUser is still 
         * in the call; catch the signal send by 
         * refreshTimer when timeout() happens
         */
        void checkLiveness();

    private:
        static const int REFRESH_INTERVAL = 12;
        QString remoteUserPrefix;
        QTimer *refreshTimer;
        QDateTime lastRefreshTime;
    private:
        int setRefreshTimer();
        void unsetRefreshTimer();
};

#else
class RemoteUser;
#endif
