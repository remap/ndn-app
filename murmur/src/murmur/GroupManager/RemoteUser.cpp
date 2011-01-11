#include <signal.h>
#include <unistd.h>
#include <cstdlib>
#include "murmur_pch.h"
#include "RemoteUser.h"

RemoteUser::RemoteUser(QString prefix, QString name) : remoteUserPrefix(prefix) {
    qsName = name;
    lastRefreshTime = QDateTime::currentDateTime();

    refreshTimer = new QTimer(this);
    connect(refreshTimer, SIGNAL(timeout()), this, SLOT(checkLiveness())/* , Qt::DirectConnection */);
    refreshTimer->start(REFRESH_INTERVAL * 1000);

    fprintf(stderr, "new:user = %p, timer = %p\n", this, refreshTimer);
}

RemoteUser::~RemoteUser() {
    if (refreshTimer->isActive())
        refreshTimer->stop();
    fprintf(stderr, "delete:user = %p, timer = %p\n", this, refreshTimer);
    delete refreshTimer;
    refreshTimer = NULL;
}

int RemoteUser::setLastRefreshTime() {
    lastRefreshTime = QDateTime::currentDateTime();
    return 0;
}

void RemoteUser::checkLiveness() {
    int delta = QDateTime::currentDateTime().secsTo(lastRefreshTime);
    fprintf(stderr, "RemoteUser<%s>::checkLiveness(): %d // %d\n", this->qsName.toLocal8Bit().constData(), delta, -1*delta);
    if ((-1 * delta) >= REFRESH_INTERVAL) {
        fprintf(stderr, "RemoteUser::emit userHasLeft()\n");
        emit userHasLeft(this->qsName);
    } else {
        fprintf(stderr, "RemoteUser: Remote User still alive\n");
    }
}

RemoteUser::operator const QString() const {
    QString temp = qsName;
    temp.prepend("<");
    temp.append(",");
    temp.append(remoteUserPrefix);
    temp.append(">");
    return temp;
}

