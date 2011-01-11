// **********************************************************************
//
// Copyright (c) 2003-2008 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.3.0
// Generated from file `Murmur.ice'

#ifndef __Murmur_h__
#define __Murmur_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/IncomingAsync.h>
#include <Ice/Direct.h>
#include <Ice/UserExceptionFactory.h>
#include <Ice/FactoryTable.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 303
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 0
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace Murmur
{

class Tree;

class ServerCallback;

class ServerContextCallback;

class ServerAuthenticator;

class ServerUpdatingAuthenticator;

class Server;

class MetaCallback;

class Meta;

}

}

namespace Murmur
{

class Tree;
bool operator==(const Tree&, const Tree&);
bool operator<(const Tree&, const Tree&);

class ServerCallback;
bool operator==(const ServerCallback&, const ServerCallback&);
bool operator<(const ServerCallback&, const ServerCallback&);

class ServerContextCallback;
bool operator==(const ServerContextCallback&, const ServerContextCallback&);
bool operator<(const ServerContextCallback&, const ServerContextCallback&);

class ServerAuthenticator;
bool operator==(const ServerAuthenticator&, const ServerAuthenticator&);
bool operator<(const ServerAuthenticator&, const ServerAuthenticator&);

class ServerUpdatingAuthenticator;
bool operator==(const ServerUpdatingAuthenticator&, const ServerUpdatingAuthenticator&);
bool operator<(const ServerUpdatingAuthenticator&, const ServerUpdatingAuthenticator&);

class Server;
bool operator==(const Server&, const Server&);
bool operator<(const Server&, const Server&);

class MetaCallback;
bool operator==(const MetaCallback&, const MetaCallback&);
bool operator<(const MetaCallback&, const MetaCallback&);

class Meta;
bool operator==(const Meta&, const Meta&);
bool operator<(const Meta&, const Meta&);

}

namespace IceInternal
{

::Ice::Object* upCast(::Murmur::Tree*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::Tree*);

::Ice::Object* upCast(::Murmur::ServerCallback*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::ServerCallback*);

::Ice::Object* upCast(::Murmur::ServerContextCallback*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::ServerContextCallback*);

::Ice::Object* upCast(::Murmur::ServerAuthenticator*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::ServerAuthenticator*);

::Ice::Object* upCast(::Murmur::ServerUpdatingAuthenticator*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::ServerUpdatingAuthenticator*);

::Ice::Object* upCast(::Murmur::Server*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::Server*);

::Ice::Object* upCast(::Murmur::MetaCallback*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::MetaCallback*);

::Ice::Object* upCast(::Murmur::Meta*);
::IceProxy::Ice::Object* upCast(::IceProxy::Murmur::Meta*);

}

namespace Murmur
{

typedef ::IceInternal::Handle< ::Murmur::Tree> TreePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::Tree> TreePrx;

void __read(::IceInternal::BasicStream*, TreePrx&);
void __patch__TreePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::ServerCallback> ServerCallbackPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::ServerCallback> ServerCallbackPrx;

void __read(::IceInternal::BasicStream*, ServerCallbackPrx&);
void __patch__ServerCallbackPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::ServerContextCallback> ServerContextCallbackPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::ServerContextCallback> ServerContextCallbackPrx;

void __read(::IceInternal::BasicStream*, ServerContextCallbackPrx&);
void __patch__ServerContextCallbackPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::ServerAuthenticator> ServerAuthenticatorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::ServerAuthenticator> ServerAuthenticatorPrx;

void __read(::IceInternal::BasicStream*, ServerAuthenticatorPrx&);
void __patch__ServerAuthenticatorPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::ServerUpdatingAuthenticator> ServerUpdatingAuthenticatorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::ServerUpdatingAuthenticator> ServerUpdatingAuthenticatorPrx;

void __read(::IceInternal::BasicStream*, ServerUpdatingAuthenticatorPrx&);
void __patch__ServerUpdatingAuthenticatorPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::Server> ServerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::Server> ServerPrx;

void __read(::IceInternal::BasicStream*, ServerPrx&);
void __patch__ServerPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::MetaCallback> MetaCallbackPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::MetaCallback> MetaCallbackPrx;

void __read(::IceInternal::BasicStream*, MetaCallbackPrx&);
void __patch__MetaCallbackPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Murmur::Meta> MetaPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Murmur::Meta> MetaPrx;

void __read(::IceInternal::BasicStream*, MetaPrx&);
void __patch__MetaPtr(void*, ::Ice::ObjectPtr&);

}

namespace Murmur
{

typedef ::std::vector< ::Ice::Byte> NetAddress;

struct User
{
    ::Ice::Int session;
    ::Ice::Int userid;
    bool mute;
    bool deaf;
    bool suppress;
    bool selfMute;
    bool selfDeaf;
    ::Ice::Int channel;
    ::std::string name;
    ::Ice::Int onlinesecs;
    ::Ice::Int bytespersec;
    ::Ice::Int version;
    ::std::string release;
    ::std::string os;
    ::std::string osversion;
    ::std::string identity;
    ::std::string context;
    ::std::string comment;
    ::Murmur::NetAddress address;
    bool tcponly;
    ::Ice::Int idlesecs;

    bool operator==(const User&) const;
    bool operator<(const User&) const;
    bool operator!=(const User& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const User& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const User& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const User& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::Ice::Int> IntList;

struct Channel
{
    ::Ice::Int id;
    ::std::string name;
    ::Ice::Int parent;
    ::Murmur::IntList links;
    ::std::string description;
    bool temporary;
    ::Ice::Int position;

    bool operator==(const Channel&) const;
    bool operator<(const Channel&) const;
    bool operator!=(const Channel& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const Channel& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const Channel& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const Channel& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct Group
{
    ::std::string name;
    bool inherited;
    bool inherit;
    bool inheritable;
    ::Murmur::IntList add;
    ::Murmur::IntList remove;
    ::Murmur::IntList members;

    bool operator==(const Group&) const;
    bool operator<(const Group&) const;
    bool operator!=(const Group& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const Group& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const Group& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const Group& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

const ::Ice::Int PermissionWrite = 1;

const ::Ice::Int PermissionTraverse = 2;

const ::Ice::Int PermissionEnter = 4;

const ::Ice::Int PermissionSpeak = 8;

const ::Ice::Int PermissionWhisper = 256;

const ::Ice::Int PermissionMuteDeafen = 16;

const ::Ice::Int PermissionMove = 32;

const ::Ice::Int PermissionMakeChannel = 64;

const ::Ice::Int PermissionMakeTempChannel = 1024;

const ::Ice::Int PermissionLinkChannel = 128;

const ::Ice::Int PermissionTextMessage = 512;

const ::Ice::Int PermissionKick = 65536;

const ::Ice::Int PermissionBan = 131072;

const ::Ice::Int PermissionRegister = 262144;

const ::Ice::Int PermissionRegisterSelf = 524288;

struct ACL
{
    bool applyHere;
    bool applySubs;
    bool inherited;
    ::Ice::Int userid;
    ::std::string group;
    ::Ice::Int allow;
    ::Ice::Int deny;

    bool operator==(const ACL&) const;
    bool operator<(const ACL&) const;
    bool operator!=(const ACL& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const ACL& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const ACL& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const ACL& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct Ban
{
    ::Murmur::NetAddress address;
    ::Ice::Int bits;
    ::std::string name;
    ::std::string hash;
    ::std::string reason;
    ::Ice::Long start;
    ::Ice::Int duration;

    bool operator==(const Ban&) const;
    bool operator<(const Ban&) const;
    bool operator!=(const Ban& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const Ban& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const Ban& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const Ban& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct LogEntry
{
    ::Ice::Int timestamp;
    ::std::string txt;

    bool operator==(const LogEntry&) const;
    bool operator<(const LogEntry&) const;
    bool operator!=(const LogEntry& __rhs) const
    {
        return !operator==(__rhs);
    }
    bool operator<=(const LogEntry& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const LogEntry& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const LogEntry& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::Murmur::TreePtr> TreeList;
void __writeTreeList(::IceInternal::BasicStream*, const ::Murmur::TreePtr*, const ::Murmur::TreePtr*);
void __readTreeList(::IceInternal::BasicStream*, TreeList&);

enum ChannelInfo
{
    ChannelDescription,
    ChannelPosition
};

void __write(::IceInternal::BasicStream*, ChannelInfo);
void __read(::IceInternal::BasicStream*, ChannelInfo&);

enum UserInfo
{
    UserName,
    UserEmail,
    UserComment,
    UserHash,
    UserPassword
};

void __write(::IceInternal::BasicStream*, UserInfo);
void __read(::IceInternal::BasicStream*, UserInfo&);

typedef ::std::map< ::Ice::Int, ::Murmur::User> UserMap;
void __writeUserMap(::IceInternal::BasicStream*, const UserMap&);
void __readUserMap(::IceInternal::BasicStream*, UserMap&);

typedef ::std::map< ::Ice::Int, ::Murmur::Channel> ChannelMap;
void __writeChannelMap(::IceInternal::BasicStream*, const ChannelMap&);
void __readChannelMap(::IceInternal::BasicStream*, ChannelMap&);

typedef ::std::vector< ::Murmur::Channel> ChannelList;
void __writeChannelList(::IceInternal::BasicStream*, const ::Murmur::Channel*, const ::Murmur::Channel*);
void __readChannelList(::IceInternal::BasicStream*, ChannelList&);

typedef ::std::vector< ::Murmur::User> UserList;
void __writeUserList(::IceInternal::BasicStream*, const ::Murmur::User*, const ::Murmur::User*);
void __readUserList(::IceInternal::BasicStream*, UserList&);

typedef ::std::vector< ::Murmur::Group> GroupList;
void __writeGroupList(::IceInternal::BasicStream*, const ::Murmur::Group*, const ::Murmur::Group*);
void __readGroupList(::IceInternal::BasicStream*, GroupList&);

typedef ::std::vector< ::Murmur::ACL> ACLList;
void __writeACLList(::IceInternal::BasicStream*, const ::Murmur::ACL*, const ::Murmur::ACL*);
void __readACLList(::IceInternal::BasicStream*, ACLList&);

typedef ::std::vector< ::Murmur::LogEntry> LogList;
void __writeLogList(::IceInternal::BasicStream*, const ::Murmur::LogEntry*, const ::Murmur::LogEntry*);
void __readLogList(::IceInternal::BasicStream*, LogList&);

typedef ::std::vector< ::Murmur::Ban> BanList;
void __writeBanList(::IceInternal::BasicStream*, const ::Murmur::Ban*, const ::Murmur::Ban*);
void __readBanList(::IceInternal::BasicStream*, BanList&);

typedef ::std::vector< ::Ice::Int> IdList;

typedef ::std::vector< ::std::string> NameList;

typedef ::std::map< ::Ice::Int, ::std::string> NameMap;
void __writeNameMap(::IceInternal::BasicStream*, const NameMap&);
void __readNameMap(::IceInternal::BasicStream*, NameMap&);

typedef ::std::map< ::std::string, ::Ice::Int> IdMap;
void __writeIdMap(::IceInternal::BasicStream*, const IdMap&);
void __readIdMap(::IceInternal::BasicStream*, IdMap&);

typedef ::std::vector< ::Ice::Byte> Texture;

typedef ::std::map< ::std::string, ::std::string> ConfigMap;
void __writeConfigMap(::IceInternal::BasicStream*, const ConfigMap&);
void __readConfigMap(::IceInternal::BasicStream*, ConfigMap&);

typedef ::std::vector< ::std::string> GroupNameList;

typedef ::std::vector< ::Ice::Byte> CertificateDer;

typedef ::std::vector< ::Murmur::CertificateDer> CertificateList;
void __writeCertificateList(::IceInternal::BasicStream*, const ::Murmur::CertificateDer*, const ::Murmur::CertificateDer*);
void __readCertificateList(::IceInternal::BasicStream*, CertificateList&);

typedef ::std::map< ::Murmur::UserInfo, ::std::string> UserInfoMap;
void __writeUserInfoMap(::IceInternal::BasicStream*, const UserInfoMap&);
void __readUserInfoMap(::IceInternal::BasicStream*, UserInfoMap&);

class MurmurException : public ::Ice::UserException
{
public:

    MurmurException() {}
    virtual ~MurmurException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

static MurmurException __MurmurException_init;

class InvalidSessionException : public ::Murmur::MurmurException
{
public:

    InvalidSessionException() {}
    virtual ~InvalidSessionException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class InvalidChannelException : public ::Murmur::MurmurException
{
public:

    InvalidChannelException() {}
    virtual ~InvalidChannelException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class InvalidServerException : public ::Murmur::MurmurException
{
public:

    InvalidServerException() {}
    virtual ~InvalidServerException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ServerBootedException : public ::Murmur::MurmurException
{
public:

    ServerBootedException() {}
    virtual ~ServerBootedException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ServerFailureException : public ::Murmur::MurmurException
{
public:

    ServerFailureException() {}
    virtual ~ServerFailureException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class InvalidUserException : public ::Murmur::MurmurException
{
public:

    InvalidUserException() {}
    virtual ~InvalidUserException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class InvalidTextureException : public ::Murmur::MurmurException
{
public:

    InvalidTextureException() {}
    virtual ~InvalidTextureException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class InvalidCallbackException : public ::Murmur::MurmurException
{
public:

    InvalidCallbackException() {}
    virtual ~InvalidCallbackException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class InvalidSecretException : public ::Murmur::MurmurException
{
public:

    InvalidSecretException() {}
    virtual ~InvalidSecretException() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

const ::Ice::Int ContextServer = 1;

const ::Ice::Int ContextChannel = 2;

const ::Ice::Int ContextUser = 4;

typedef ::std::vector< ::Murmur::ServerPrx> ServerList;
void __writeServerList(::IceInternal::BasicStream*, const ::Murmur::ServerPrx*, const ::Murmur::ServerPrx*);
void __readServerList(::IceInternal::BasicStream*, ServerList&);

}

namespace Murmur
{

class AMD_Server_isRunning : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(bool) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_isRunning> AMD_Server_isRunningPtr;

class AMD_Server_start : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_start> AMD_Server_startPtr;

class AMD_Server_stop : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_stop> AMD_Server_stopPtr;

class AMD_Server_delete : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_delete> AMD_Server_deletePtr;

class AMD_Server_id : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_id> AMD_Server_idPtr;

class AMD_Server_addCallback : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_addCallback> AMD_Server_addCallbackPtr;

class AMD_Server_removeCallback : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_removeCallback> AMD_Server_removeCallbackPtr;

class AMD_Server_setAuthenticator : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setAuthenticator> AMD_Server_setAuthenticatorPtr;

class AMD_Server_getConf : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::std::string&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getConf> AMD_Server_getConfPtr;

class AMD_Server_getAllConf : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ConfigMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getAllConf> AMD_Server_getAllConfPtr;

class AMD_Server_setConf : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setConf> AMD_Server_setConfPtr;

class AMD_Server_setSuperuserPassword : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setSuperuserPassword> AMD_Server_setSuperuserPasswordPtr;

class AMD_Server_getLog : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::LogList&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getLog> AMD_Server_getLogPtr;

class AMD_Server_getUsers : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::UserMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getUsers> AMD_Server_getUsersPtr;

class AMD_Server_getChannels : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ChannelMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getChannels> AMD_Server_getChannelsPtr;

class AMD_Server_getCertificateList : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::CertificateList&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getCertificateList> AMD_Server_getCertificateListPtr;

class AMD_Server_getTree : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::TreePtr&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getTree> AMD_Server_getTreePtr;

class AMD_Server_getBans : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::BanList&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getBans> AMD_Server_getBansPtr;

class AMD_Server_setBans : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setBans> AMD_Server_setBansPtr;

class AMD_Server_kickUser : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_kickUser> AMD_Server_kickUserPtr;

class AMD_Server_getState : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::User&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getState> AMD_Server_getStatePtr;

class AMD_Server_setState : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setState> AMD_Server_setStatePtr;

class AMD_Server_sendMessage : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_sendMessage> AMD_Server_sendMessagePtr;

class AMD_Server_hasPermission : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(bool) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_hasPermission> AMD_Server_hasPermissionPtr;

class AMD_Server_addContextCallback : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_addContextCallback> AMD_Server_addContextCallbackPtr;

class AMD_Server_removeContextCallback : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_removeContextCallback> AMD_Server_removeContextCallbackPtr;

class AMD_Server_getChannelState : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::Channel&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getChannelState> AMD_Server_getChannelStatePtr;

class AMD_Server_setChannelState : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setChannelState> AMD_Server_setChannelStatePtr;

class AMD_Server_removeChannel : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_removeChannel> AMD_Server_removeChannelPtr;

class AMD_Server_addChannel : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_addChannel> AMD_Server_addChannelPtr;

class AMD_Server_sendMessageChannel : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_sendMessageChannel> AMD_Server_sendMessageChannelPtr;

class AMD_Server_getACL : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getACL> AMD_Server_getACLPtr;

class AMD_Server_setACL : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setACL> AMD_Server_setACLPtr;

class AMD_Server_addUserToGroup : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_addUserToGroup> AMD_Server_addUserToGroupPtr;

class AMD_Server_removeUserFromGroup : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_removeUserFromGroup> AMD_Server_removeUserFromGroupPtr;

class AMD_Server_redirectWhisperGroup : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_redirectWhisperGroup> AMD_Server_redirectWhisperGroupPtr;

class AMD_Server_getUserNames : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::NameMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getUserNames> AMD_Server_getUserNamesPtr;

class AMD_Server_getUserIds : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::IdMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getUserIds> AMD_Server_getUserIdsPtr;

class AMD_Server_registerUser : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_registerUser> AMD_Server_registerUserPtr;

class AMD_Server_unregisterUser : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_unregisterUser> AMD_Server_unregisterUserPtr;

class AMD_Server_updateRegistration : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_updateRegistration> AMD_Server_updateRegistrationPtr;

class AMD_Server_getRegistration : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::UserInfoMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getRegistration> AMD_Server_getRegistrationPtr;

class AMD_Server_getRegisteredUsers : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::NameMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getRegisteredUsers> AMD_Server_getRegisteredUsersPtr;

class AMD_Server_verifyPassword : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_verifyPassword> AMD_Server_verifyPasswordPtr;

class AMD_Server_getTexture : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::Texture&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getTexture> AMD_Server_getTexturePtr;

class AMD_Server_setTexture : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_setTexture> AMD_Server_setTexturePtr;

class AMD_Server_getUptime : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Server_getUptime> AMD_Server_getUptimePtr;

class AMD_Meta_getServer : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ServerPrx&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_getServer> AMD_Meta_getServerPtr;

class AMD_Meta_newServer : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ServerPrx&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_newServer> AMD_Meta_newServerPtr;

class AMD_Meta_getBootedServers : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ServerList&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_getBootedServers> AMD_Meta_getBootedServersPtr;

class AMD_Meta_getAllServers : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ServerList&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_getAllServers> AMD_Meta_getAllServersPtr;

class AMD_Meta_getDefaultConf : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Murmur::ConfigMap&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_getDefaultConf> AMD_Meta_getDefaultConfPtr;

class AMD_Meta_getVersion : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_getVersion> AMD_Meta_getVersionPtr;

class AMD_Meta_addCallback : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_addCallback> AMD_Meta_addCallbackPtr;

class AMD_Meta_removeCallback : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_removeCallback> AMD_Meta_removeCallbackPtr;

class AMD_Meta_getUptime : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::Murmur::AMD_Meta_getUptime> AMD_Meta_getUptimePtr;

}

namespace IceAsync
{

namespace Murmur
{

class AMD_Server_isRunning : public ::Murmur::AMD_Server_isRunning, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_isRunning(::IceInternal::Incoming&);

    virtual void ice_response(bool);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_start : public ::Murmur::AMD_Server_start, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_start(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_stop : public ::Murmur::AMD_Server_stop, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_stop(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_delete : public ::Murmur::AMD_Server_delete, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_delete(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_id : public ::Murmur::AMD_Server_id, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_id(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_addCallback : public ::Murmur::AMD_Server_addCallback, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_addCallback(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_removeCallback : public ::Murmur::AMD_Server_removeCallback, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_removeCallback(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setAuthenticator : public ::Murmur::AMD_Server_setAuthenticator, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setAuthenticator(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getConf : public ::Murmur::AMD_Server_getConf, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getConf(::IceInternal::Incoming&);

    virtual void ice_response(const ::std::string&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getAllConf : public ::Murmur::AMD_Server_getAllConf, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getAllConf(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ConfigMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setConf : public ::Murmur::AMD_Server_setConf, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setConf(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setSuperuserPassword : public ::Murmur::AMD_Server_setSuperuserPassword, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setSuperuserPassword(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getLog : public ::Murmur::AMD_Server_getLog, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getLog(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::LogList&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getUsers : public ::Murmur::AMD_Server_getUsers, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getUsers(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::UserMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getChannels : public ::Murmur::AMD_Server_getChannels, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getChannels(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ChannelMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getCertificateList : public ::Murmur::AMD_Server_getCertificateList, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getCertificateList(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::CertificateList&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getTree : public ::Murmur::AMD_Server_getTree, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getTree(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::TreePtr&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getBans : public ::Murmur::AMD_Server_getBans, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getBans(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::BanList&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setBans : public ::Murmur::AMD_Server_setBans, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setBans(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_kickUser : public ::Murmur::AMD_Server_kickUser, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_kickUser(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getState : public ::Murmur::AMD_Server_getState, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getState(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::User&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setState : public ::Murmur::AMD_Server_setState, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setState(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_sendMessage : public ::Murmur::AMD_Server_sendMessage, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_sendMessage(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_hasPermission : public ::Murmur::AMD_Server_hasPermission, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_hasPermission(::IceInternal::Incoming&);

    virtual void ice_response(bool);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_addContextCallback : public ::Murmur::AMD_Server_addContextCallback, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_addContextCallback(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_removeContextCallback : public ::Murmur::AMD_Server_removeContextCallback, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_removeContextCallback(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getChannelState : public ::Murmur::AMD_Server_getChannelState, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getChannelState(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::Channel&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setChannelState : public ::Murmur::AMD_Server_setChannelState, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setChannelState(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_removeChannel : public ::Murmur::AMD_Server_removeChannel, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_removeChannel(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_addChannel : public ::Murmur::AMD_Server_addChannel, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_addChannel(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_sendMessageChannel : public ::Murmur::AMD_Server_sendMessageChannel, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_sendMessageChannel(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getACL : public ::Murmur::AMD_Server_getACL, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getACL(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setACL : public ::Murmur::AMD_Server_setACL, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setACL(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_addUserToGroup : public ::Murmur::AMD_Server_addUserToGroup, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_addUserToGroup(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_removeUserFromGroup : public ::Murmur::AMD_Server_removeUserFromGroup, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_removeUserFromGroup(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_redirectWhisperGroup : public ::Murmur::AMD_Server_redirectWhisperGroup, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_redirectWhisperGroup(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getUserNames : public ::Murmur::AMD_Server_getUserNames, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getUserNames(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::NameMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getUserIds : public ::Murmur::AMD_Server_getUserIds, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getUserIds(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::IdMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_registerUser : public ::Murmur::AMD_Server_registerUser, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_registerUser(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_unregisterUser : public ::Murmur::AMD_Server_unregisterUser, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_unregisterUser(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_updateRegistration : public ::Murmur::AMD_Server_updateRegistration, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_updateRegistration(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getRegistration : public ::Murmur::AMD_Server_getRegistration, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getRegistration(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::UserInfoMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getRegisteredUsers : public ::Murmur::AMD_Server_getRegisteredUsers, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getRegisteredUsers(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::NameMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_verifyPassword : public ::Murmur::AMD_Server_verifyPassword, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_verifyPassword(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getTexture : public ::Murmur::AMD_Server_getTexture, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getTexture(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::Texture&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_setTexture : public ::Murmur::AMD_Server_setTexture, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_setTexture(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Server_getUptime : public ::Murmur::AMD_Server_getUptime, public ::IceInternal::IncomingAsync
{
public:

    AMD_Server_getUptime(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_getServer : public ::Murmur::AMD_Meta_getServer, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_getServer(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ServerPrx&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_newServer : public ::Murmur::AMD_Meta_newServer, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_newServer(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ServerPrx&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_getBootedServers : public ::Murmur::AMD_Meta_getBootedServers, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_getBootedServers(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ServerList&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_getAllServers : public ::Murmur::AMD_Meta_getAllServers, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_getAllServers(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ServerList&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_getDefaultConf : public ::Murmur::AMD_Meta_getDefaultConf, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_getDefaultConf(::IceInternal::Incoming&);

    virtual void ice_response(const ::Murmur::ConfigMap&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_getVersion : public ::Murmur::AMD_Meta_getVersion, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_getVersion(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_addCallback : public ::Murmur::AMD_Meta_addCallback, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_addCallback(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_removeCallback : public ::Murmur::AMD_Meta_removeCallback, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_removeCallback(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class AMD_Meta_getUptime : public ::Murmur::AMD_Meta_getUptime, public ::IceInternal::IncomingAsync
{
public:

    AMD_Meta_getUptime(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

}

}

namespace IceProxy
{

namespace Murmur
{

class Tree : virtual public ::IceProxy::Ice::Object
{
public:
    
    ::IceInternal::ProxyHandle<Tree> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Tree> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Tree*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<Tree*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class ServerCallback : virtual public ::IceProxy::Ice::Object
{
public:

    void userConnected(const ::Murmur::User& state)
    {
        userConnected(state, 0);
    }
    void userConnected(const ::Murmur::User& state, const ::Ice::Context& __ctx)
    {
        userConnected(state, &__ctx);
    }
    
private:

    void userConnected(const ::Murmur::User&, const ::Ice::Context*);
    
public:

    void userDisconnected(const ::Murmur::User& state)
    {
        userDisconnected(state, 0);
    }
    void userDisconnected(const ::Murmur::User& state, const ::Ice::Context& __ctx)
    {
        userDisconnected(state, &__ctx);
    }
    
private:

    void userDisconnected(const ::Murmur::User&, const ::Ice::Context*);
    
public:

    void userStateChanged(const ::Murmur::User& state)
    {
        userStateChanged(state, 0);
    }
    void userStateChanged(const ::Murmur::User& state, const ::Ice::Context& __ctx)
    {
        userStateChanged(state, &__ctx);
    }
    
private:

    void userStateChanged(const ::Murmur::User&, const ::Ice::Context*);
    
public:

    void channelCreated(const ::Murmur::Channel& state)
    {
        channelCreated(state, 0);
    }
    void channelCreated(const ::Murmur::Channel& state, const ::Ice::Context& __ctx)
    {
        channelCreated(state, &__ctx);
    }
    
private:

    void channelCreated(const ::Murmur::Channel&, const ::Ice::Context*);
    
public:

    void channelRemoved(const ::Murmur::Channel& state)
    {
        channelRemoved(state, 0);
    }
    void channelRemoved(const ::Murmur::Channel& state, const ::Ice::Context& __ctx)
    {
        channelRemoved(state, &__ctx);
    }
    
private:

    void channelRemoved(const ::Murmur::Channel&, const ::Ice::Context*);
    
public:

    void channelStateChanged(const ::Murmur::Channel& state)
    {
        channelStateChanged(state, 0);
    }
    void channelStateChanged(const ::Murmur::Channel& state, const ::Ice::Context& __ctx)
    {
        channelStateChanged(state, &__ctx);
    }
    
private:

    void channelStateChanged(const ::Murmur::Channel&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerCallback> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerCallback*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<ServerCallback*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class ServerContextCallback : virtual public ::IceProxy::Ice::Object
{
public:

    void contextAction(const ::std::string& action, const ::Murmur::User& usr, ::Ice::Int session, ::Ice::Int channelid)
    {
        contextAction(action, usr, session, channelid, 0);
    }
    void contextAction(const ::std::string& action, const ::Murmur::User& usr, ::Ice::Int session, ::Ice::Int channelid, const ::Ice::Context& __ctx)
    {
        contextAction(action, usr, session, channelid, &__ctx);
    }
    
private:

    void contextAction(const ::std::string&, const ::Murmur::User&, ::Ice::Int, ::Ice::Int, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerContextCallback> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerContextCallback*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<ServerContextCallback*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class ServerAuthenticator : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::Int authenticate(const ::std::string& name, const ::std::string& pw, const ::Murmur::CertificateList& certificates, const ::std::string& certhash, bool certstrong, ::std::string& newname, ::Murmur::GroupNameList& groups)
    {
        return authenticate(name, pw, certificates, certhash, certstrong, newname, groups, 0);
    }
    ::Ice::Int authenticate(const ::std::string& name, const ::std::string& pw, const ::Murmur::CertificateList& certificates, const ::std::string& certhash, bool certstrong, ::std::string& newname, ::Murmur::GroupNameList& groups, const ::Ice::Context& __ctx)
    {
        return authenticate(name, pw, certificates, certhash, certstrong, newname, groups, &__ctx);
    }
    
private:

    ::Ice::Int authenticate(const ::std::string&, const ::std::string&, const ::Murmur::CertificateList&, const ::std::string&, bool, ::std::string&, ::Murmur::GroupNameList&, const ::Ice::Context*);
    
public:

    bool getInfo(::Ice::Int id, ::Murmur::UserInfoMap& info)
    {
        return getInfo(id, info, 0);
    }
    bool getInfo(::Ice::Int id, ::Murmur::UserInfoMap& info, const ::Ice::Context& __ctx)
    {
        return getInfo(id, info, &__ctx);
    }
    
private:

    bool getInfo(::Ice::Int, ::Murmur::UserInfoMap&, const ::Ice::Context*);
    
public:

    ::Ice::Int nameToId(const ::std::string& name)
    {
        return nameToId(name, 0);
    }
    ::Ice::Int nameToId(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return nameToId(name, &__ctx);
    }
    
private:

    ::Ice::Int nameToId(const ::std::string&, const ::Ice::Context*);
    
public:

    ::std::string idToName(::Ice::Int id)
    {
        return idToName(id, 0);
    }
    ::std::string idToName(::Ice::Int id, const ::Ice::Context& __ctx)
    {
        return idToName(id, &__ctx);
    }
    
private:

    ::std::string idToName(::Ice::Int, const ::Ice::Context*);
    
public:

    ::Murmur::Texture idToTexture(::Ice::Int id)
    {
        return idToTexture(id, 0);
    }
    ::Murmur::Texture idToTexture(::Ice::Int id, const ::Ice::Context& __ctx)
    {
        return idToTexture(id, &__ctx);
    }
    
private:

    ::Murmur::Texture idToTexture(::Ice::Int, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerAuthenticator> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerAuthenticator*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<ServerAuthenticator*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class ServerUpdatingAuthenticator : virtual public ::IceProxy::Murmur::ServerAuthenticator
{
public:

    ::Ice::Int registerUser(const ::Murmur::UserInfoMap& info)
    {
        return registerUser(info, 0);
    }
    ::Ice::Int registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context& __ctx)
    {
        return registerUser(info, &__ctx);
    }
    
private:

    ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*);
    
public:

    ::Ice::Int unregisterUser(::Ice::Int id)
    {
        return unregisterUser(id, 0);
    }
    ::Ice::Int unregisterUser(::Ice::Int id, const ::Ice::Context& __ctx)
    {
        return unregisterUser(id, &__ctx);
    }
    
private:

    ::Ice::Int unregisterUser(::Ice::Int, const ::Ice::Context*);
    
public:

    ::Murmur::NameMap getRegisteredUsers(const ::std::string& filter)
    {
        return getRegisteredUsers(filter, 0);
    }
    ::Murmur::NameMap getRegisteredUsers(const ::std::string& filter, const ::Ice::Context& __ctx)
    {
        return getRegisteredUsers(filter, &__ctx);
    }
    
private:

    ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int setInfo(::Ice::Int id, const ::Murmur::UserInfoMap& info)
    {
        return setInfo(id, info, 0);
    }
    ::Ice::Int setInfo(::Ice::Int id, const ::Murmur::UserInfoMap& info, const ::Ice::Context& __ctx)
    {
        return setInfo(id, info, &__ctx);
    }
    
private:

    ::Ice::Int setInfo(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*);
    
public:

    ::Ice::Int setTexture(::Ice::Int id, const ::Murmur::Texture& tex)
    {
        return setTexture(id, tex, 0);
    }
    ::Ice::Int setTexture(::Ice::Int id, const ::Murmur::Texture& tex, const ::Ice::Context& __ctx)
    {
        return setTexture(id, tex, &__ctx);
    }
    
private:

    ::Ice::Int setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<ServerUpdatingAuthenticator> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<ServerUpdatingAuthenticator*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<ServerUpdatingAuthenticator*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class Server : virtual public ::IceProxy::Ice::Object
{
public:

    bool isRunning()
    {
        return isRunning(0);
    }
    bool isRunning(const ::Ice::Context& __ctx)
    {
        return isRunning(&__ctx);
    }
    
private:

    bool isRunning(const ::Ice::Context*);
    
public:

    void start()
    {
        start(0);
    }
    void start(const ::Ice::Context& __ctx)
    {
        start(&__ctx);
    }
    
private:

    void start(const ::Ice::Context*);
    
public:

    void stop()
    {
        stop(0);
    }
    void stop(const ::Ice::Context& __ctx)
    {
        stop(&__ctx);
    }
    
private:

    void stop(const ::Ice::Context*);
    
public:

    void _cpp_delete()
    {
        _cpp_delete(0);
    }
    void _cpp_delete(const ::Ice::Context& __ctx)
    {
        _cpp_delete(&__ctx);
    }
    
private:

    void _cpp_delete(const ::Ice::Context*);
    
public:

    ::Ice::Int id()
    {
        return id(0);
    }
    ::Ice::Int id(const ::Ice::Context& __ctx)
    {
        return id(&__ctx);
    }
    
private:

    ::Ice::Int id(const ::Ice::Context*);
    
public:

    void addCallback(const ::Murmur::ServerCallbackPrx& cb)
    {
        addCallback(cb, 0);
    }
    void addCallback(const ::Murmur::ServerCallbackPrx& cb, const ::Ice::Context& __ctx)
    {
        addCallback(cb, &__ctx);
    }
    
private:

    void addCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*);
    
public:

    void removeCallback(const ::Murmur::ServerCallbackPrx& cb)
    {
        removeCallback(cb, 0);
    }
    void removeCallback(const ::Murmur::ServerCallbackPrx& cb, const ::Ice::Context& __ctx)
    {
        removeCallback(cb, &__ctx);
    }
    
private:

    void removeCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*);
    
public:

    void setAuthenticator(const ::Murmur::ServerAuthenticatorPrx& auth)
    {
        setAuthenticator(auth, 0);
    }
    void setAuthenticator(const ::Murmur::ServerAuthenticatorPrx& auth, const ::Ice::Context& __ctx)
    {
        setAuthenticator(auth, &__ctx);
    }
    
private:

    void setAuthenticator(const ::Murmur::ServerAuthenticatorPrx&, const ::Ice::Context*);
    
public:

    ::std::string getConf(const ::std::string& key)
    {
        return getConf(key, 0);
    }
    ::std::string getConf(const ::std::string& key, const ::Ice::Context& __ctx)
    {
        return getConf(key, &__ctx);
    }
    
private:

    ::std::string getConf(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Murmur::ConfigMap getAllConf()
    {
        return getAllConf(0);
    }
    ::Murmur::ConfigMap getAllConf(const ::Ice::Context& __ctx)
    {
        return getAllConf(&__ctx);
    }
    
private:

    ::Murmur::ConfigMap getAllConf(const ::Ice::Context*);
    
public:

    void setConf(const ::std::string& key, const ::std::string& value)
    {
        setConf(key, value, 0);
    }
    void setConf(const ::std::string& key, const ::std::string& value, const ::Ice::Context& __ctx)
    {
        setConf(key, value, &__ctx);
    }
    
private:

    void setConf(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    void setSuperuserPassword(const ::std::string& pw)
    {
        setSuperuserPassword(pw, 0);
    }
    void setSuperuserPassword(const ::std::string& pw, const ::Ice::Context& __ctx)
    {
        setSuperuserPassword(pw, &__ctx);
    }
    
private:

    void setSuperuserPassword(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Murmur::LogList getLog(::Ice::Int first, ::Ice::Int last)
    {
        return getLog(first, last, 0);
    }
    ::Murmur::LogList getLog(::Ice::Int first, ::Ice::Int last, const ::Ice::Context& __ctx)
    {
        return getLog(first, last, &__ctx);
    }
    
private:

    ::Murmur::LogList getLog(::Ice::Int, ::Ice::Int, const ::Ice::Context*);
    
public:

    ::Murmur::UserMap getUsers()
    {
        return getUsers(0);
    }
    ::Murmur::UserMap getUsers(const ::Ice::Context& __ctx)
    {
        return getUsers(&__ctx);
    }
    
private:

    ::Murmur::UserMap getUsers(const ::Ice::Context*);
    
public:

    ::Murmur::ChannelMap getChannels()
    {
        return getChannels(0);
    }
    ::Murmur::ChannelMap getChannels(const ::Ice::Context& __ctx)
    {
        return getChannels(&__ctx);
    }
    
private:

    ::Murmur::ChannelMap getChannels(const ::Ice::Context*);
    
public:

    ::Murmur::CertificateList getCertificateList(::Ice::Int session)
    {
        return getCertificateList(session, 0);
    }
    ::Murmur::CertificateList getCertificateList(::Ice::Int session, const ::Ice::Context& __ctx)
    {
        return getCertificateList(session, &__ctx);
    }
    
private:

    ::Murmur::CertificateList getCertificateList(::Ice::Int, const ::Ice::Context*);
    
public:

    ::Murmur::TreePtr getTree()
    {
        return getTree(0);
    }
    ::Murmur::TreePtr getTree(const ::Ice::Context& __ctx)
    {
        return getTree(&__ctx);
    }
    
private:

    ::Murmur::TreePtr getTree(const ::Ice::Context*);
    
public:

    ::Murmur::BanList getBans()
    {
        return getBans(0);
    }
    ::Murmur::BanList getBans(const ::Ice::Context& __ctx)
    {
        return getBans(&__ctx);
    }
    
private:

    ::Murmur::BanList getBans(const ::Ice::Context*);
    
public:

    void setBans(const ::Murmur::BanList& bans)
    {
        setBans(bans, 0);
    }
    void setBans(const ::Murmur::BanList& bans, const ::Ice::Context& __ctx)
    {
        setBans(bans, &__ctx);
    }
    
private:

    void setBans(const ::Murmur::BanList&, const ::Ice::Context*);
    
public:

    void kickUser(::Ice::Int session, const ::std::string& reason)
    {
        kickUser(session, reason, 0);
    }
    void kickUser(::Ice::Int session, const ::std::string& reason, const ::Ice::Context& __ctx)
    {
        kickUser(session, reason, &__ctx);
    }
    
private:

    void kickUser(::Ice::Int, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Murmur::User getState(::Ice::Int session)
    {
        return getState(session, 0);
    }
    ::Murmur::User getState(::Ice::Int session, const ::Ice::Context& __ctx)
    {
        return getState(session, &__ctx);
    }
    
private:

    ::Murmur::User getState(::Ice::Int, const ::Ice::Context*);
    
public:

    void setState(const ::Murmur::User& state)
    {
        setState(state, 0);
    }
    void setState(const ::Murmur::User& state, const ::Ice::Context& __ctx)
    {
        setState(state, &__ctx);
    }
    
private:

    void setState(const ::Murmur::User&, const ::Ice::Context*);
    
public:

    void sendMessage(::Ice::Int session, const ::std::string& text)
    {
        sendMessage(session, text, 0);
    }
    void sendMessage(::Ice::Int session, const ::std::string& text, const ::Ice::Context& __ctx)
    {
        sendMessage(session, text, &__ctx);
    }
    
private:

    void sendMessage(::Ice::Int, const ::std::string&, const ::Ice::Context*);
    
public:

    bool hasPermission(::Ice::Int session, ::Ice::Int channelid, ::Ice::Int perm)
    {
        return hasPermission(session, channelid, perm, 0);
    }
    bool hasPermission(::Ice::Int session, ::Ice::Int channelid, ::Ice::Int perm, const ::Ice::Context& __ctx)
    {
        return hasPermission(session, channelid, perm, &__ctx);
    }
    
private:

    bool hasPermission(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context*);
    
public:

    void addContextCallback(::Ice::Int session, const ::std::string& action, const ::std::string& text, const ::Murmur::ServerContextCallbackPrx& cb, ::Ice::Int ctx)
    {
        addContextCallback(session, action, text, cb, ctx, 0);
    }
    void addContextCallback(::Ice::Int session, const ::std::string& action, const ::std::string& text, const ::Murmur::ServerContextCallbackPrx& cb, ::Ice::Int ctx, const ::Ice::Context& __ctx)
    {
        addContextCallback(session, action, text, cb, ctx, &__ctx);
    }
    
private:

    void addContextCallback(::Ice::Int, const ::std::string&, const ::std::string&, const ::Murmur::ServerContextCallbackPrx&, ::Ice::Int, const ::Ice::Context*);
    
public:

    void removeContextCallback(const ::Murmur::ServerContextCallbackPrx& cb)
    {
        removeContextCallback(cb, 0);
    }
    void removeContextCallback(const ::Murmur::ServerContextCallbackPrx& cb, const ::Ice::Context& __ctx)
    {
        removeContextCallback(cb, &__ctx);
    }
    
private:

    void removeContextCallback(const ::Murmur::ServerContextCallbackPrx&, const ::Ice::Context*);
    
public:

    ::Murmur::Channel getChannelState(::Ice::Int channelid)
    {
        return getChannelState(channelid, 0);
    }
    ::Murmur::Channel getChannelState(::Ice::Int channelid, const ::Ice::Context& __ctx)
    {
        return getChannelState(channelid, &__ctx);
    }
    
private:

    ::Murmur::Channel getChannelState(::Ice::Int, const ::Ice::Context*);
    
public:

    void setChannelState(const ::Murmur::Channel& state)
    {
        setChannelState(state, 0);
    }
    void setChannelState(const ::Murmur::Channel& state, const ::Ice::Context& __ctx)
    {
        setChannelState(state, &__ctx);
    }
    
private:

    void setChannelState(const ::Murmur::Channel&, const ::Ice::Context*);
    
public:

    void removeChannel(::Ice::Int channelid)
    {
        removeChannel(channelid, 0);
    }
    void removeChannel(::Ice::Int channelid, const ::Ice::Context& __ctx)
    {
        removeChannel(channelid, &__ctx);
    }
    
private:

    void removeChannel(::Ice::Int, const ::Ice::Context*);
    
public:

    ::Ice::Int addChannel(const ::std::string& name, ::Ice::Int parent)
    {
        return addChannel(name, parent, 0);
    }
    ::Ice::Int addChannel(const ::std::string& name, ::Ice::Int parent, const ::Ice::Context& __ctx)
    {
        return addChannel(name, parent, &__ctx);
    }
    
private:

    ::Ice::Int addChannel(const ::std::string&, ::Ice::Int, const ::Ice::Context*);
    
public:

    void sendMessageChannel(::Ice::Int channelid, bool tree, const ::std::string& text)
    {
        sendMessageChannel(channelid, tree, text, 0);
    }
    void sendMessageChannel(::Ice::Int channelid, bool tree, const ::std::string& text, const ::Ice::Context& __ctx)
    {
        sendMessageChannel(channelid, tree, text, &__ctx);
    }
    
private:

    void sendMessageChannel(::Ice::Int, bool, const ::std::string&, const ::Ice::Context*);
    
public:

    void getACL(::Ice::Int channelid, ::Murmur::ACLList& acls, ::Murmur::GroupList& groups, bool& inherit)
    {
        getACL(channelid, acls, groups, inherit, 0);
    }
    void getACL(::Ice::Int channelid, ::Murmur::ACLList& acls, ::Murmur::GroupList& groups, bool& inherit, const ::Ice::Context& __ctx)
    {
        getACL(channelid, acls, groups, inherit, &__ctx);
    }
    
private:

    void getACL(::Ice::Int, ::Murmur::ACLList&, ::Murmur::GroupList&, bool&, const ::Ice::Context*);
    
public:

    void setACL(::Ice::Int channelid, const ::Murmur::ACLList& acls, const ::Murmur::GroupList& groups, bool inherit)
    {
        setACL(channelid, acls, groups, inherit, 0);
    }
    void setACL(::Ice::Int channelid, const ::Murmur::ACLList& acls, const ::Murmur::GroupList& groups, bool inherit, const ::Ice::Context& __ctx)
    {
        setACL(channelid, acls, groups, inherit, &__ctx);
    }
    
private:

    void setACL(::Ice::Int, const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool, const ::Ice::Context*);
    
public:

    void addUserToGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group)
    {
        addUserToGroup(channelid, session, group, 0);
    }
    void addUserToGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group, const ::Ice::Context& __ctx)
    {
        addUserToGroup(channelid, session, group, &__ctx);
    }
    
private:

    void addUserToGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*);
    
public:

    void removeUserFromGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group)
    {
        removeUserFromGroup(channelid, session, group, 0);
    }
    void removeUserFromGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group, const ::Ice::Context& __ctx)
    {
        removeUserFromGroup(channelid, session, group, &__ctx);
    }
    
private:

    void removeUserFromGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*);
    
public:

    void redirectWhisperGroup(::Ice::Int session, const ::std::string& source, const ::std::string& target)
    {
        redirectWhisperGroup(session, source, target, 0);
    }
    void redirectWhisperGroup(::Ice::Int session, const ::std::string& source, const ::std::string& target, const ::Ice::Context& __ctx)
    {
        redirectWhisperGroup(session, source, target, &__ctx);
    }
    
private:

    void redirectWhisperGroup(::Ice::Int, const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Murmur::NameMap getUserNames(const ::Murmur::IdList& ids)
    {
        return getUserNames(ids, 0);
    }
    ::Murmur::NameMap getUserNames(const ::Murmur::IdList& ids, const ::Ice::Context& __ctx)
    {
        return getUserNames(ids, &__ctx);
    }
    
private:

    ::Murmur::NameMap getUserNames(const ::Murmur::IdList&, const ::Ice::Context*);
    
public:

    ::Murmur::IdMap getUserIds(const ::Murmur::NameList& names)
    {
        return getUserIds(names, 0);
    }
    ::Murmur::IdMap getUserIds(const ::Murmur::NameList& names, const ::Ice::Context& __ctx)
    {
        return getUserIds(names, &__ctx);
    }
    
private:

    ::Murmur::IdMap getUserIds(const ::Murmur::NameList&, const ::Ice::Context*);
    
public:

    ::Ice::Int registerUser(const ::Murmur::UserInfoMap& info)
    {
        return registerUser(info, 0);
    }
    ::Ice::Int registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context& __ctx)
    {
        return registerUser(info, &__ctx);
    }
    
private:

    ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*);
    
public:

    void unregisterUser(::Ice::Int userid)
    {
        unregisterUser(userid, 0);
    }
    void unregisterUser(::Ice::Int userid, const ::Ice::Context& __ctx)
    {
        unregisterUser(userid, &__ctx);
    }
    
private:

    void unregisterUser(::Ice::Int, const ::Ice::Context*);
    
public:

    void updateRegistration(::Ice::Int userid, const ::Murmur::UserInfoMap& info)
    {
        updateRegistration(userid, info, 0);
    }
    void updateRegistration(::Ice::Int userid, const ::Murmur::UserInfoMap& info, const ::Ice::Context& __ctx)
    {
        updateRegistration(userid, info, &__ctx);
    }
    
private:

    void updateRegistration(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*);
    
public:

    ::Murmur::UserInfoMap getRegistration(::Ice::Int userid)
    {
        return getRegistration(userid, 0);
    }
    ::Murmur::UserInfoMap getRegistration(::Ice::Int userid, const ::Ice::Context& __ctx)
    {
        return getRegistration(userid, &__ctx);
    }
    
private:

    ::Murmur::UserInfoMap getRegistration(::Ice::Int, const ::Ice::Context*);
    
public:

    ::Murmur::NameMap getRegisteredUsers(const ::std::string& filter)
    {
        return getRegisteredUsers(filter, 0);
    }
    ::Murmur::NameMap getRegisteredUsers(const ::std::string& filter, const ::Ice::Context& __ctx)
    {
        return getRegisteredUsers(filter, &__ctx);
    }
    
private:

    ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Ice::Int verifyPassword(const ::std::string& name, const ::std::string& pw)
    {
        return verifyPassword(name, pw, 0);
    }
    ::Ice::Int verifyPassword(const ::std::string& name, const ::std::string& pw, const ::Ice::Context& __ctx)
    {
        return verifyPassword(name, pw, &__ctx);
    }
    
private:

    ::Ice::Int verifyPassword(const ::std::string&, const ::std::string&, const ::Ice::Context*);
    
public:

    ::Murmur::Texture getTexture(::Ice::Int userid)
    {
        return getTexture(userid, 0);
    }
    ::Murmur::Texture getTexture(::Ice::Int userid, const ::Ice::Context& __ctx)
    {
        return getTexture(userid, &__ctx);
    }
    
private:

    ::Murmur::Texture getTexture(::Ice::Int, const ::Ice::Context*);
    
public:

    void setTexture(::Ice::Int userid, const ::Murmur::Texture& tex)
    {
        setTexture(userid, tex, 0);
    }
    void setTexture(::Ice::Int userid, const ::Murmur::Texture& tex, const ::Ice::Context& __ctx)
    {
        setTexture(userid, tex, &__ctx);
    }
    
private:

    void setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*);
    
public:

    ::Ice::Int getUptime()
    {
        return getUptime(0);
    }
    ::Ice::Int getUptime(const ::Ice::Context& __ctx)
    {
        return getUptime(&__ctx);
    }
    
private:

    ::Ice::Int getUptime(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Server> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Server> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Server*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<Server*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class MetaCallback : virtual public ::IceProxy::Ice::Object
{
public:

    void started(const ::Murmur::ServerPrx& srv)
    {
        started(srv, 0);
    }
    void started(const ::Murmur::ServerPrx& srv, const ::Ice::Context& __ctx)
    {
        started(srv, &__ctx);
    }
    
private:

    void started(const ::Murmur::ServerPrx&, const ::Ice::Context*);
    
public:

    void stopped(const ::Murmur::ServerPrx& srv)
    {
        stopped(srv, 0);
    }
    void stopped(const ::Murmur::ServerPrx& srv, const ::Ice::Context& __ctx)
    {
        stopped(srv, &__ctx);
    }
    
private:

    void stopped(const ::Murmur::ServerPrx&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<MetaCallback> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<MetaCallback*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<MetaCallback*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class Meta : virtual public ::IceProxy::Ice::Object
{
public:

    ::Murmur::ServerPrx getServer(::Ice::Int id)
    {
        return getServer(id, 0);
    }
    ::Murmur::ServerPrx getServer(::Ice::Int id, const ::Ice::Context& __ctx)
    {
        return getServer(id, &__ctx);
    }
    
private:

    ::Murmur::ServerPrx getServer(::Ice::Int, const ::Ice::Context*);
    
public:

    ::Murmur::ServerPrx newServer()
    {
        return newServer(0);
    }
    ::Murmur::ServerPrx newServer(const ::Ice::Context& __ctx)
    {
        return newServer(&__ctx);
    }
    
private:

    ::Murmur::ServerPrx newServer(const ::Ice::Context*);
    
public:

    ::Murmur::ServerList getBootedServers()
    {
        return getBootedServers(0);
    }
    ::Murmur::ServerList getBootedServers(const ::Ice::Context& __ctx)
    {
        return getBootedServers(&__ctx);
    }
    
private:

    ::Murmur::ServerList getBootedServers(const ::Ice::Context*);
    
public:

    ::Murmur::ServerList getAllServers()
    {
        return getAllServers(0);
    }
    ::Murmur::ServerList getAllServers(const ::Ice::Context& __ctx)
    {
        return getAllServers(&__ctx);
    }
    
private:

    ::Murmur::ServerList getAllServers(const ::Ice::Context*);
    
public:

    ::Murmur::ConfigMap getDefaultConf()
    {
        return getDefaultConf(0);
    }
    ::Murmur::ConfigMap getDefaultConf(const ::Ice::Context& __ctx)
    {
        return getDefaultConf(&__ctx);
    }
    
private:

    ::Murmur::ConfigMap getDefaultConf(const ::Ice::Context*);
    
public:

    void getVersion(::Ice::Int& major, ::Ice::Int& minor, ::Ice::Int& patch, ::std::string& text)
    {
        getVersion(major, minor, patch, text, 0);
    }
    void getVersion(::Ice::Int& major, ::Ice::Int& minor, ::Ice::Int& patch, ::std::string& text, const ::Ice::Context& __ctx)
    {
        getVersion(major, minor, patch, text, &__ctx);
    }
    
private:

    void getVersion(::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::std::string&, const ::Ice::Context*);
    
public:

    void addCallback(const ::Murmur::MetaCallbackPrx& cb)
    {
        addCallback(cb, 0);
    }
    void addCallback(const ::Murmur::MetaCallbackPrx& cb, const ::Ice::Context& __ctx)
    {
        addCallback(cb, &__ctx);
    }
    
private:

    void addCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*);
    
public:

    void removeCallback(const ::Murmur::MetaCallbackPrx& cb)
    {
        removeCallback(cb, 0);
    }
    void removeCallback(const ::Murmur::MetaCallbackPrx& cb, const ::Ice::Context& __ctx)
    {
        removeCallback(cb, &__ctx);
    }
    
private:

    void removeCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*);
    
public:

    ::Ice::Int getUptime()
    {
        return getUptime(0);
    }
    ::Ice::Int getUptime(const ::Ice::Context& __ctx)
    {
        return getUptime(&__ctx);
    }
    
private:

    ::Ice::Int getUptime(const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Meta> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<Meta> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<Meta*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<Meta*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace Murmur
{

class Tree : virtual public ::IceDelegate::Ice::Object
{
public:
};

class ServerCallback : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void userConnected(const ::Murmur::User&, const ::Ice::Context*) = 0;

    virtual void userDisconnected(const ::Murmur::User&, const ::Ice::Context*) = 0;

    virtual void userStateChanged(const ::Murmur::User&, const ::Ice::Context*) = 0;

    virtual void channelCreated(const ::Murmur::Channel&, const ::Ice::Context*) = 0;

    virtual void channelRemoved(const ::Murmur::Channel&, const ::Ice::Context*) = 0;

    virtual void channelStateChanged(const ::Murmur::Channel&, const ::Ice::Context*) = 0;
};

class ServerContextCallback : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void contextAction(const ::std::string&, const ::Murmur::User&, ::Ice::Int, ::Ice::Int, const ::Ice::Context*) = 0;
};

class ServerAuthenticator : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::Int authenticate(const ::std::string&, const ::std::string&, const ::Murmur::CertificateList&, const ::std::string&, bool, ::std::string&, ::Murmur::GroupNameList&, const ::Ice::Context*) = 0;

    virtual bool getInfo(::Ice::Int, ::Murmur::UserInfoMap&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int nameToId(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::std::string idToName(::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Murmur::Texture idToTexture(::Ice::Int, const ::Ice::Context*) = 0;
};

class ServerUpdatingAuthenticator : virtual public ::IceDelegate::Murmur::ServerAuthenticator
{
public:

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int unregisterUser(::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int setInfo(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*) = 0;
};

class Server : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual bool isRunning(const ::Ice::Context*) = 0;

    virtual void start(const ::Ice::Context*) = 0;

    virtual void stop(const ::Ice::Context*) = 0;

    virtual void _cpp_delete(const ::Ice::Context*) = 0;

    virtual ::Ice::Int id(const ::Ice::Context*) = 0;

    virtual void addCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*) = 0;

    virtual void removeCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*) = 0;

    virtual void setAuthenticator(const ::Murmur::ServerAuthenticatorPrx&, const ::Ice::Context*) = 0;

    virtual ::std::string getConf(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Murmur::ConfigMap getAllConf(const ::Ice::Context*) = 0;

    virtual void setConf(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void setSuperuserPassword(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Murmur::LogList getLog(::Ice::Int, ::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Murmur::UserMap getUsers(const ::Ice::Context*) = 0;

    virtual ::Murmur::ChannelMap getChannels(const ::Ice::Context*) = 0;

    virtual ::Murmur::CertificateList getCertificateList(::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Murmur::TreePtr getTree(const ::Ice::Context*) = 0;

    virtual ::Murmur::BanList getBans(const ::Ice::Context*) = 0;

    virtual void setBans(const ::Murmur::BanList&, const ::Ice::Context*) = 0;

    virtual void kickUser(::Ice::Int, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Murmur::User getState(::Ice::Int, const ::Ice::Context*) = 0;

    virtual void setState(const ::Murmur::User&, const ::Ice::Context*) = 0;

    virtual void sendMessage(::Ice::Int, const ::std::string&, const ::Ice::Context*) = 0;

    virtual bool hasPermission(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context*) = 0;

    virtual void addContextCallback(::Ice::Int, const ::std::string&, const ::std::string&, const ::Murmur::ServerContextCallbackPrx&, ::Ice::Int, const ::Ice::Context*) = 0;

    virtual void removeContextCallback(const ::Murmur::ServerContextCallbackPrx&, const ::Ice::Context*) = 0;

    virtual ::Murmur::Channel getChannelState(::Ice::Int, const ::Ice::Context*) = 0;

    virtual void setChannelState(const ::Murmur::Channel&, const ::Ice::Context*) = 0;

    virtual void removeChannel(::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Ice::Int addChannel(const ::std::string&, ::Ice::Int, const ::Ice::Context*) = 0;

    virtual void sendMessageChannel(::Ice::Int, bool, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void getACL(::Ice::Int, ::Murmur::ACLList&, ::Murmur::GroupList&, bool&, const ::Ice::Context*) = 0;

    virtual void setACL(::Ice::Int, const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool, const ::Ice::Context*) = 0;

    virtual void addUserToGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void removeUserFromGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void redirectWhisperGroup(::Ice::Int, const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Murmur::NameMap getUserNames(const ::Murmur::IdList&, const ::Ice::Context*) = 0;

    virtual ::Murmur::IdMap getUserIds(const ::Murmur::NameList&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*) = 0;

    virtual void unregisterUser(::Ice::Int, const ::Ice::Context*) = 0;

    virtual void updateRegistration(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*) = 0;

    virtual ::Murmur::UserInfoMap getRegistration(::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int verifyPassword(const ::std::string&, const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Murmur::Texture getTexture(::Ice::Int, const ::Ice::Context*) = 0;

    virtual void setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getUptime(const ::Ice::Context*) = 0;
};

class MetaCallback : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void started(const ::Murmur::ServerPrx&, const ::Ice::Context*) = 0;

    virtual void stopped(const ::Murmur::ServerPrx&, const ::Ice::Context*) = 0;
};

class Meta : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Murmur::ServerPrx getServer(::Ice::Int, const ::Ice::Context*) = 0;

    virtual ::Murmur::ServerPrx newServer(const ::Ice::Context*) = 0;

    virtual ::Murmur::ServerList getBootedServers(const ::Ice::Context*) = 0;

    virtual ::Murmur::ServerList getAllServers(const ::Ice::Context*) = 0;

    virtual ::Murmur::ConfigMap getDefaultConf(const ::Ice::Context*) = 0;

    virtual void getVersion(::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::std::string&, const ::Ice::Context*) = 0;

    virtual void addCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*) = 0;

    virtual void removeCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*) = 0;

    virtual ::Ice::Int getUptime(const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace Murmur
{

class Tree : virtual public ::IceDelegate::Murmur::Tree,
             virtual public ::IceDelegateM::Ice::Object
{
public:
};

class ServerCallback : virtual public ::IceDelegate::Murmur::ServerCallback,
                       virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void userConnected(const ::Murmur::User&, const ::Ice::Context*);

    virtual void userDisconnected(const ::Murmur::User&, const ::Ice::Context*);

    virtual void userStateChanged(const ::Murmur::User&, const ::Ice::Context*);

    virtual void channelCreated(const ::Murmur::Channel&, const ::Ice::Context*);

    virtual void channelRemoved(const ::Murmur::Channel&, const ::Ice::Context*);

    virtual void channelStateChanged(const ::Murmur::Channel&, const ::Ice::Context*);
};

class ServerContextCallback : virtual public ::IceDelegate::Murmur::ServerContextCallback,
                              virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void contextAction(const ::std::string&, const ::Murmur::User&, ::Ice::Int, ::Ice::Int, const ::Ice::Context*);
};

class ServerAuthenticator : virtual public ::IceDelegate::Murmur::ServerAuthenticator,
                            virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::Int authenticate(const ::std::string&, const ::std::string&, const ::Murmur::CertificateList&, const ::std::string&, bool, ::std::string&, ::Murmur::GroupNameList&, const ::Ice::Context*);

    virtual bool getInfo(::Ice::Int, ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Ice::Int nameToId(const ::std::string&, const ::Ice::Context*);

    virtual ::std::string idToName(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::Texture idToTexture(::Ice::Int, const ::Ice::Context*);
};

class ServerUpdatingAuthenticator : virtual public ::IceDelegate::Murmur::ServerUpdatingAuthenticator,
                                    virtual public ::IceDelegateM::Murmur::ServerAuthenticator
{
public:

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Ice::Int unregisterUser(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int setInfo(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Ice::Int setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*);
};

class Server : virtual public ::IceDelegate::Murmur::Server,
               virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual bool isRunning(const ::Ice::Context*);

    virtual void start(const ::Ice::Context*);

    virtual void stop(const ::Ice::Context*);

    virtual void _cpp_delete(const ::Ice::Context*);

    virtual ::Ice::Int id(const ::Ice::Context*);

    virtual void addCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*);

    virtual void removeCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*);

    virtual void setAuthenticator(const ::Murmur::ServerAuthenticatorPrx&, const ::Ice::Context*);

    virtual ::std::string getConf(const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::ConfigMap getAllConf(const ::Ice::Context*);

    virtual void setConf(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setSuperuserPassword(const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::LogList getLog(::Ice::Int, ::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::UserMap getUsers(const ::Ice::Context*);

    virtual ::Murmur::ChannelMap getChannels(const ::Ice::Context*);

    virtual ::Murmur::CertificateList getCertificateList(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::TreePtr getTree(const ::Ice::Context*);

    virtual ::Murmur::BanList getBans(const ::Ice::Context*);

    virtual void setBans(const ::Murmur::BanList&, const ::Ice::Context*);

    virtual void kickUser(::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::User getState(::Ice::Int, const ::Ice::Context*);

    virtual void setState(const ::Murmur::User&, const ::Ice::Context*);

    virtual void sendMessage(::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual bool hasPermission(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context*);

    virtual void addContextCallback(::Ice::Int, const ::std::string&, const ::std::string&, const ::Murmur::ServerContextCallbackPrx&, ::Ice::Int, const ::Ice::Context*);

    virtual void removeContextCallback(const ::Murmur::ServerContextCallbackPrx&, const ::Ice::Context*);

    virtual ::Murmur::Channel getChannelState(::Ice::Int, const ::Ice::Context*);

    virtual void setChannelState(const ::Murmur::Channel&, const ::Ice::Context*);

    virtual void removeChannel(::Ice::Int, const ::Ice::Context*);

    virtual ::Ice::Int addChannel(const ::std::string&, ::Ice::Int, const ::Ice::Context*);

    virtual void sendMessageChannel(::Ice::Int, bool, const ::std::string&, const ::Ice::Context*);

    virtual void getACL(::Ice::Int, ::Murmur::ACLList&, ::Murmur::GroupList&, bool&, const ::Ice::Context*);

    virtual void setACL(::Ice::Int, const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool, const ::Ice::Context*);

    virtual void addUserToGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual void removeUserFromGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual void redirectWhisperGroup(::Ice::Int, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::NameMap getUserNames(const ::Murmur::IdList&, const ::Ice::Context*);

    virtual ::Murmur::IdMap getUserIds(const ::Murmur::NameList&, const ::Ice::Context*);

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual void unregisterUser(::Ice::Int, const ::Ice::Context*);

    virtual void updateRegistration(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Murmur::UserInfoMap getRegistration(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int verifyPassword(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::Texture getTexture(::Ice::Int, const ::Ice::Context*);

    virtual void setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*);

    virtual ::Ice::Int getUptime(const ::Ice::Context*);
};

class MetaCallback : virtual public ::IceDelegate::Murmur::MetaCallback,
                     virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void started(const ::Murmur::ServerPrx&, const ::Ice::Context*);

    virtual void stopped(const ::Murmur::ServerPrx&, const ::Ice::Context*);
};

class Meta : virtual public ::IceDelegate::Murmur::Meta,
             virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Murmur::ServerPrx getServer(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::ServerPrx newServer(const ::Ice::Context*);

    virtual ::Murmur::ServerList getBootedServers(const ::Ice::Context*);

    virtual ::Murmur::ServerList getAllServers(const ::Ice::Context*);

    virtual ::Murmur::ConfigMap getDefaultConf(const ::Ice::Context*);

    virtual void getVersion(::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::std::string&, const ::Ice::Context*);

    virtual void addCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*);

    virtual void removeCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*);

    virtual ::Ice::Int getUptime(const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace Murmur
{

class Tree : virtual public ::IceDelegate::Murmur::Tree,
             virtual public ::IceDelegateD::Ice::Object
{
public:
};

class ServerCallback : virtual public ::IceDelegate::Murmur::ServerCallback,
                       virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void userConnected(const ::Murmur::User&, const ::Ice::Context*);

    virtual void userDisconnected(const ::Murmur::User&, const ::Ice::Context*);

    virtual void userStateChanged(const ::Murmur::User&, const ::Ice::Context*);

    virtual void channelCreated(const ::Murmur::Channel&, const ::Ice::Context*);

    virtual void channelRemoved(const ::Murmur::Channel&, const ::Ice::Context*);

    virtual void channelStateChanged(const ::Murmur::Channel&, const ::Ice::Context*);
};

class ServerContextCallback : virtual public ::IceDelegate::Murmur::ServerContextCallback,
                              virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void contextAction(const ::std::string&, const ::Murmur::User&, ::Ice::Int, ::Ice::Int, const ::Ice::Context*);
};

class ServerAuthenticator : virtual public ::IceDelegate::Murmur::ServerAuthenticator,
                            virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::Int authenticate(const ::std::string&, const ::std::string&, const ::Murmur::CertificateList&, const ::std::string&, bool, ::std::string&, ::Murmur::GroupNameList&, const ::Ice::Context*);

    virtual bool getInfo(::Ice::Int, ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Ice::Int nameToId(const ::std::string&, const ::Ice::Context*);

    virtual ::std::string idToName(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::Texture idToTexture(::Ice::Int, const ::Ice::Context*);
};

class ServerUpdatingAuthenticator : virtual public ::IceDelegate::Murmur::ServerUpdatingAuthenticator,
                                    virtual public ::IceDelegateD::Murmur::ServerAuthenticator
{
public:

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Ice::Int unregisterUser(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int setInfo(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Ice::Int setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*);
};

class Server : virtual public ::IceDelegate::Murmur::Server,
               virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual bool isRunning(const ::Ice::Context*);

    virtual void start(const ::Ice::Context*);

    virtual void stop(const ::Ice::Context*);

    virtual void _cpp_delete(const ::Ice::Context*);

    virtual ::Ice::Int id(const ::Ice::Context*);

    virtual void addCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*);

    virtual void removeCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*);

    virtual void setAuthenticator(const ::Murmur::ServerAuthenticatorPrx&, const ::Ice::Context*);

    virtual ::std::string getConf(const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::ConfigMap getAllConf(const ::Ice::Context*);

    virtual void setConf(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual void setSuperuserPassword(const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::LogList getLog(::Ice::Int, ::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::UserMap getUsers(const ::Ice::Context*);

    virtual ::Murmur::ChannelMap getChannels(const ::Ice::Context*);

    virtual ::Murmur::CertificateList getCertificateList(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::TreePtr getTree(const ::Ice::Context*);

    virtual ::Murmur::BanList getBans(const ::Ice::Context*);

    virtual void setBans(const ::Murmur::BanList&, const ::Ice::Context*);

    virtual void kickUser(::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::User getState(::Ice::Int, const ::Ice::Context*);

    virtual void setState(const ::Murmur::User&, const ::Ice::Context*);

    virtual void sendMessage(::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual bool hasPermission(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context*);

    virtual void addContextCallback(::Ice::Int, const ::std::string&, const ::std::string&, const ::Murmur::ServerContextCallbackPrx&, ::Ice::Int, const ::Ice::Context*);

    virtual void removeContextCallback(const ::Murmur::ServerContextCallbackPrx&, const ::Ice::Context*);

    virtual ::Murmur::Channel getChannelState(::Ice::Int, const ::Ice::Context*);

    virtual void setChannelState(const ::Murmur::Channel&, const ::Ice::Context*);

    virtual void removeChannel(::Ice::Int, const ::Ice::Context*);

    virtual ::Ice::Int addChannel(const ::std::string&, ::Ice::Int, const ::Ice::Context*);

    virtual void sendMessageChannel(::Ice::Int, bool, const ::std::string&, const ::Ice::Context*);

    virtual void getACL(::Ice::Int, ::Murmur::ACLList&, ::Murmur::GroupList&, bool&, const ::Ice::Context*);

    virtual void setACL(::Ice::Int, const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool, const ::Ice::Context*);

    virtual void addUserToGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual void removeUserFromGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual void redirectWhisperGroup(::Ice::Int, const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::NameMap getUserNames(const ::Murmur::IdList&, const ::Ice::Context*);

    virtual ::Murmur::IdMap getUserIds(const ::Murmur::NameList&, const ::Ice::Context*);

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual void unregisterUser(::Ice::Int, const ::Ice::Context*);

    virtual void updateRegistration(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*);

    virtual ::Murmur::UserInfoMap getRegistration(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Context*);

    virtual ::Ice::Int verifyPassword(const ::std::string&, const ::std::string&, const ::Ice::Context*);

    virtual ::Murmur::Texture getTexture(::Ice::Int, const ::Ice::Context*);

    virtual void setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*);

    virtual ::Ice::Int getUptime(const ::Ice::Context*);
};

class MetaCallback : virtual public ::IceDelegate::Murmur::MetaCallback,
                     virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void started(const ::Murmur::ServerPrx&, const ::Ice::Context*);

    virtual void stopped(const ::Murmur::ServerPrx&, const ::Ice::Context*);
};

class Meta : virtual public ::IceDelegate::Murmur::Meta,
             virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Murmur::ServerPrx getServer(::Ice::Int, const ::Ice::Context*);

    virtual ::Murmur::ServerPrx newServer(const ::Ice::Context*);

    virtual ::Murmur::ServerList getBootedServers(const ::Ice::Context*);

    virtual ::Murmur::ServerList getAllServers(const ::Ice::Context*);

    virtual ::Murmur::ConfigMap getDefaultConf(const ::Ice::Context*);

    virtual void getVersion(::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::std::string&, const ::Ice::Context*);

    virtual void addCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*);

    virtual void removeCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*);

    virtual ::Ice::Int getUptime(const ::Ice::Context*);
};

}

}

namespace Murmur
{

class Tree : virtual public ::Ice::Object
{
public:

    typedef TreePrx ProxyType;
    typedef TreePtr PointerType;
    
    Tree() {}
    Tree(const ::Murmur::Channel&, const ::Murmur::TreeList&, const ::Murmur::UserList&);
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void __incRef();
    virtual void __decRef();
    virtual void __addObject(::IceInternal::GCCountMap&);
    virtual bool __usesClasses();
    virtual void __gcReachable(::IceInternal::GCCountMap&) const;
    virtual void __gcClear();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);

    static const ::Ice::ObjectFactoryPtr& ice_factory();

protected:

    virtual ~Tree() {}

    friend class Tree__staticInit;

public:

    ::Murmur::Channel c;

    ::Murmur::TreeList children;

    ::Murmur::UserList users;
};

class Tree__staticInit
{
public:

    ::Murmur::Tree _init;
};

static ::Murmur::Tree__staticInit _Tree_init;

class ServerCallback : virtual public ::Ice::Object
{
public:

    typedef ServerCallbackPrx ProxyType;
    typedef ServerCallbackPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void userConnected(const ::Murmur::User&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___userConnected(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void userDisconnected(const ::Murmur::User&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___userDisconnected(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void userStateChanged(const ::Murmur::User&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___userStateChanged(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void channelCreated(const ::Murmur::Channel&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___channelCreated(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void channelRemoved(const ::Murmur::Channel&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___channelRemoved(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void channelStateChanged(const ::Murmur::Channel&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___channelStateChanged(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ServerContextCallback : virtual public ::Ice::Object
{
public:

    typedef ServerContextCallbackPrx ProxyType;
    typedef ServerContextCallbackPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void contextAction(const ::std::string&, const ::Murmur::User&, ::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___contextAction(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ServerAuthenticator : virtual public ::Ice::Object
{
public:

    typedef ServerAuthenticatorPrx ProxyType;
    typedef ServerAuthenticatorPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::Int authenticate(const ::std::string&, const ::std::string&, const ::Murmur::CertificateList&, const ::std::string&, bool, ::std::string&, ::Murmur::GroupNameList&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___authenticate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool getInfo(::Ice::Int, ::Murmur::UserInfoMap&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getInfo(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int nameToId(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___nameToId(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string idToName(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___idToName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Murmur::Texture idToTexture(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___idToTexture(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ServerUpdatingAuthenticator : virtual public ::Murmur::ServerAuthenticator
{
public:

    typedef ServerUpdatingAuthenticatorPrx ProxyType;
    typedef ServerUpdatingAuthenticatorPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::Int registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___registerUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int unregisterUser(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___unregisterUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Murmur::NameMap getRegisteredUsers(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getRegisteredUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int setInfo(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setInfo(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setTexture(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class Server : virtual public ::Ice::Object
{
public:

    typedef ServerPrx ProxyType;
    typedef ServerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void isRunning_async(const ::Murmur::AMD_Server_isRunningPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___isRunning(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void start_async(const ::Murmur::AMD_Server_startPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___start(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void stop_async(const ::Murmur::AMD_Server_stopPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___stop(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void delete_async(const ::Murmur::AMD_Server_deletePtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___delete(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void id_async(const ::Murmur::AMD_Server_idPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___id(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addCallback_async(const ::Murmur::AMD_Server_addCallbackPtr&, const ::Murmur::ServerCallbackPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addCallback(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeCallback_async(const ::Murmur::AMD_Server_removeCallbackPtr&, const ::Murmur::ServerCallbackPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeCallback(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setAuthenticator_async(const ::Murmur::AMD_Server_setAuthenticatorPtr&, const ::Murmur::ServerAuthenticatorPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setAuthenticator(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getConf_async(const ::Murmur::AMD_Server_getConfPtr&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getConf(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getAllConf_async(const ::Murmur::AMD_Server_getAllConfPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getAllConf(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setConf_async(const ::Murmur::AMD_Server_setConfPtr&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setConf(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setSuperuserPassword_async(const ::Murmur::AMD_Server_setSuperuserPasswordPtr&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setSuperuserPassword(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getLog_async(const ::Murmur::AMD_Server_getLogPtr&, ::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getLog(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getUsers_async(const ::Murmur::AMD_Server_getUsersPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getChannels_async(const ::Murmur::AMD_Server_getChannelsPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getChannels(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getCertificateList_async(const ::Murmur::AMD_Server_getCertificateListPtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getCertificateList(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getTree_async(const ::Murmur::AMD_Server_getTreePtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getTree(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getBans_async(const ::Murmur::AMD_Server_getBansPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getBans(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setBans_async(const ::Murmur::AMD_Server_setBansPtr&, const ::Murmur::BanList&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setBans(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void kickUser_async(const ::Murmur::AMD_Server_kickUserPtr&, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___kickUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getState_async(const ::Murmur::AMD_Server_getStatePtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getState(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setState_async(const ::Murmur::AMD_Server_setStatePtr&, const ::Murmur::User&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setState(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void sendMessage_async(const ::Murmur::AMD_Server_sendMessagePtr&, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___sendMessage(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void hasPermission_async(const ::Murmur::AMD_Server_hasPermissionPtr&, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___hasPermission(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addContextCallback_async(const ::Murmur::AMD_Server_addContextCallbackPtr&, ::Ice::Int, const ::std::string&, const ::std::string&, const ::Murmur::ServerContextCallbackPrx&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addContextCallback(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeContextCallback_async(const ::Murmur::AMD_Server_removeContextCallbackPtr&, const ::Murmur::ServerContextCallbackPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeContextCallback(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getChannelState_async(const ::Murmur::AMD_Server_getChannelStatePtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getChannelState(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setChannelState_async(const ::Murmur::AMD_Server_setChannelStatePtr&, const ::Murmur::Channel&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setChannelState(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeChannel_async(const ::Murmur::AMD_Server_removeChannelPtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeChannel(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addChannel_async(const ::Murmur::AMD_Server_addChannelPtr&, const ::std::string&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addChannel(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void sendMessageChannel_async(const ::Murmur::AMD_Server_sendMessageChannelPtr&, ::Ice::Int, bool, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___sendMessageChannel(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getACL_async(const ::Murmur::AMD_Server_getACLPtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getACL(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setACL_async(const ::Murmur::AMD_Server_setACLPtr&, ::Ice::Int, const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setACL(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addUserToGroup_async(const ::Murmur::AMD_Server_addUserToGroupPtr&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addUserToGroup(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeUserFromGroup_async(const ::Murmur::AMD_Server_removeUserFromGroupPtr&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeUserFromGroup(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void redirectWhisperGroup_async(const ::Murmur::AMD_Server_redirectWhisperGroupPtr&, ::Ice::Int, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___redirectWhisperGroup(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getUserNames_async(const ::Murmur::AMD_Server_getUserNamesPtr&, const ::Murmur::IdList&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getUserNames(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getUserIds_async(const ::Murmur::AMD_Server_getUserIdsPtr&, const ::Murmur::NameList&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getUserIds(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void registerUser_async(const ::Murmur::AMD_Server_registerUserPtr&, const ::Murmur::UserInfoMap&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___registerUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void unregisterUser_async(const ::Murmur::AMD_Server_unregisterUserPtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___unregisterUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void updateRegistration_async(const ::Murmur::AMD_Server_updateRegistrationPtr&, ::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___updateRegistration(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getRegistration_async(const ::Murmur::AMD_Server_getRegistrationPtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getRegistration(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getRegisteredUsers_async(const ::Murmur::AMD_Server_getRegisteredUsersPtr&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getRegisteredUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void verifyPassword_async(const ::Murmur::AMD_Server_verifyPasswordPtr&, const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___verifyPassword(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getTexture_async(const ::Murmur::AMD_Server_getTexturePtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getTexture(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setTexture_async(const ::Murmur::AMD_Server_setTexturePtr&, ::Ice::Int, const ::Murmur::Texture&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___setTexture(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getUptime_async(const ::Murmur::AMD_Server_getUptimePtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getUptime(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class MetaCallback : virtual public ::Ice::Object
{
public:

    typedef MetaCallbackPrx ProxyType;
    typedef MetaCallbackPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void started(const ::Murmur::ServerPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___started(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void stopped(const ::Murmur::ServerPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___stopped(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class Meta : virtual public ::Ice::Object
{
public:

    typedef MetaPrx ProxyType;
    typedef MetaPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void getServer_async(const ::Murmur::AMD_Meta_getServerPtr&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void newServer_async(const ::Murmur::AMD_Meta_newServerPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___newServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getBootedServers_async(const ::Murmur::AMD_Meta_getBootedServersPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getBootedServers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getAllServers_async(const ::Murmur::AMD_Meta_getAllServersPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getAllServers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getDefaultConf_async(const ::Murmur::AMD_Meta_getDefaultConfPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getDefaultConf(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getVersion_async(const ::Murmur::AMD_Meta_getVersionPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getVersion(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addCallback_async(const ::Murmur::AMD_Meta_addCallbackPtr&, const ::Murmur::MetaCallbackPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___addCallback(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeCallback_async(const ::Murmur::AMD_Meta_removeCallbackPtr&, const ::Murmur::MetaCallbackPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___removeCallback(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getUptime_async(const ::Murmur::AMD_Meta_getUptimePtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___getUptime(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

#endif
