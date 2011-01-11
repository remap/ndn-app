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

#include <Murmur.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

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

static const ::std::string __Murmur__ServerCallback__userConnected_name = "userConnected";

static const ::std::string __Murmur__ServerCallback__userDisconnected_name = "userDisconnected";

static const ::std::string __Murmur__ServerCallback__userStateChanged_name = "userStateChanged";

static const ::std::string __Murmur__ServerCallback__channelCreated_name = "channelCreated";

static const ::std::string __Murmur__ServerCallback__channelRemoved_name = "channelRemoved";

static const ::std::string __Murmur__ServerCallback__channelStateChanged_name = "channelStateChanged";

static const ::std::string __Murmur__ServerContextCallback__contextAction_name = "contextAction";

static const ::std::string __Murmur__ServerAuthenticator__authenticate_name = "authenticate";

static const ::std::string __Murmur__ServerAuthenticator__getInfo_name = "getInfo";

static const ::std::string __Murmur__ServerAuthenticator__nameToId_name = "nameToId";

static const ::std::string __Murmur__ServerAuthenticator__idToName_name = "idToName";

static const ::std::string __Murmur__ServerAuthenticator__idToTexture_name = "idToTexture";

static const ::std::string __Murmur__ServerUpdatingAuthenticator__registerUser_name = "registerUser";

static const ::std::string __Murmur__ServerUpdatingAuthenticator__unregisterUser_name = "unregisterUser";

static const ::std::string __Murmur__ServerUpdatingAuthenticator__getRegisteredUsers_name = "getRegisteredUsers";

static const ::std::string __Murmur__ServerUpdatingAuthenticator__setInfo_name = "setInfo";

static const ::std::string __Murmur__ServerUpdatingAuthenticator__setTexture_name = "setTexture";

static const ::std::string __Murmur__Server__isRunning_name = "isRunning";

static const ::std::string __Murmur__Server__start_name = "start";

static const ::std::string __Murmur__Server__stop_name = "stop";

static const ::std::string __Murmur__Server__delete_name = "delete";

static const ::std::string __Murmur__Server__id_name = "id";

static const ::std::string __Murmur__Server__addCallback_name = "addCallback";

static const ::std::string __Murmur__Server__removeCallback_name = "removeCallback";

static const ::std::string __Murmur__Server__setAuthenticator_name = "setAuthenticator";

static const ::std::string __Murmur__Server__getConf_name = "getConf";

static const ::std::string __Murmur__Server__getAllConf_name = "getAllConf";

static const ::std::string __Murmur__Server__setConf_name = "setConf";

static const ::std::string __Murmur__Server__setSuperuserPassword_name = "setSuperuserPassword";

static const ::std::string __Murmur__Server__getLog_name = "getLog";

static const ::std::string __Murmur__Server__getUsers_name = "getUsers";

static const ::std::string __Murmur__Server__getChannels_name = "getChannels";

static const ::std::string __Murmur__Server__getCertificateList_name = "getCertificateList";

static const ::std::string __Murmur__Server__getTree_name = "getTree";

static const ::std::string __Murmur__Server__getBans_name = "getBans";

static const ::std::string __Murmur__Server__setBans_name = "setBans";

static const ::std::string __Murmur__Server__kickUser_name = "kickUser";

static const ::std::string __Murmur__Server__getState_name = "getState";

static const ::std::string __Murmur__Server__setState_name = "setState";

static const ::std::string __Murmur__Server__sendMessage_name = "sendMessage";

static const ::std::string __Murmur__Server__hasPermission_name = "hasPermission";

static const ::std::string __Murmur__Server__addContextCallback_name = "addContextCallback";

static const ::std::string __Murmur__Server__removeContextCallback_name = "removeContextCallback";

static const ::std::string __Murmur__Server__getChannelState_name = "getChannelState";

static const ::std::string __Murmur__Server__setChannelState_name = "setChannelState";

static const ::std::string __Murmur__Server__removeChannel_name = "removeChannel";

static const ::std::string __Murmur__Server__addChannel_name = "addChannel";

static const ::std::string __Murmur__Server__sendMessageChannel_name = "sendMessageChannel";

static const ::std::string __Murmur__Server__getACL_name = "getACL";

static const ::std::string __Murmur__Server__setACL_name = "setACL";

static const ::std::string __Murmur__Server__addUserToGroup_name = "addUserToGroup";

static const ::std::string __Murmur__Server__removeUserFromGroup_name = "removeUserFromGroup";

static const ::std::string __Murmur__Server__redirectWhisperGroup_name = "redirectWhisperGroup";

static const ::std::string __Murmur__Server__getUserNames_name = "getUserNames";

static const ::std::string __Murmur__Server__getUserIds_name = "getUserIds";

static const ::std::string __Murmur__Server__registerUser_name = "registerUser";

static const ::std::string __Murmur__Server__unregisterUser_name = "unregisterUser";

static const ::std::string __Murmur__Server__updateRegistration_name = "updateRegistration";

static const ::std::string __Murmur__Server__getRegistration_name = "getRegistration";

static const ::std::string __Murmur__Server__getRegisteredUsers_name = "getRegisteredUsers";

static const ::std::string __Murmur__Server__verifyPassword_name = "verifyPassword";

static const ::std::string __Murmur__Server__getTexture_name = "getTexture";

static const ::std::string __Murmur__Server__setTexture_name = "setTexture";

static const ::std::string __Murmur__Server__getUptime_name = "getUptime";

static const ::std::string __Murmur__MetaCallback__started_name = "started";

static const ::std::string __Murmur__MetaCallback__stopped_name = "stopped";

static const ::std::string __Murmur__Meta__getServer_name = "getServer";

static const ::std::string __Murmur__Meta__newServer_name = "newServer";

static const ::std::string __Murmur__Meta__getBootedServers_name = "getBootedServers";

static const ::std::string __Murmur__Meta__getAllServers_name = "getAllServers";

static const ::std::string __Murmur__Meta__getDefaultConf_name = "getDefaultConf";

static const ::std::string __Murmur__Meta__getVersion_name = "getVersion";

static const ::std::string __Murmur__Meta__addCallback_name = "addCallback";

static const ::std::string __Murmur__Meta__removeCallback_name = "removeCallback";

static const ::std::string __Murmur__Meta__getUptime_name = "getUptime";

::Ice::Object* IceInternal::upCast(::Murmur::Tree* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::Tree* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::ServerCallback* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::ServerCallback* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::ServerContextCallback* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::ServerContextCallback* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::ServerAuthenticator* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::ServerAuthenticator* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::ServerUpdatingAuthenticator* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::ServerUpdatingAuthenticator* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::Server* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::Server* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::MetaCallback* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::MetaCallback* p) { return p; }

::Ice::Object* IceInternal::upCast(::Murmur::Meta* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Murmur::Meta* p) { return p; }

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::TreePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::Tree;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::ServerCallbackPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::ServerCallback;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::ServerContextCallbackPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::ServerContextCallback;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::ServerAuthenticatorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::ServerAuthenticator;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::ServerUpdatingAuthenticatorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::ServerUpdatingAuthenticator;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::ServerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::Server;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::MetaCallbackPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::MetaCallback;
        v->__copyFrom(proxy);
    }
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::MetaPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Murmur::Meta;
        v->__copyFrom(proxy);
    }
}

bool
Murmur::User::operator==(const User& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(session != __rhs.session)
    {
        return false;
    }
    if(userid != __rhs.userid)
    {
        return false;
    }
    if(mute != __rhs.mute)
    {
        return false;
    }
    if(deaf != __rhs.deaf)
    {
        return false;
    }
    if(suppress != __rhs.suppress)
    {
        return false;
    }
    if(selfMute != __rhs.selfMute)
    {
        return false;
    }
    if(selfDeaf != __rhs.selfDeaf)
    {
        return false;
    }
    if(channel != __rhs.channel)
    {
        return false;
    }
    if(name != __rhs.name)
    {
        return false;
    }
    if(onlinesecs != __rhs.onlinesecs)
    {
        return false;
    }
    if(bytespersec != __rhs.bytespersec)
    {
        return false;
    }
    if(version != __rhs.version)
    {
        return false;
    }
    if(release != __rhs.release)
    {
        return false;
    }
    if(os != __rhs.os)
    {
        return false;
    }
    if(osversion != __rhs.osversion)
    {
        return false;
    }
    if(identity != __rhs.identity)
    {
        return false;
    }
    if(context != __rhs.context)
    {
        return false;
    }
    if(comment != __rhs.comment)
    {
        return false;
    }
    if(address != __rhs.address)
    {
        return false;
    }
    if(tcponly != __rhs.tcponly)
    {
        return false;
    }
    if(idlesecs != __rhs.idlesecs)
    {
        return false;
    }
    return true;
}

bool
Murmur::User::operator<(const User& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(session < __rhs.session)
    {
        return true;
    }
    else if(__rhs.session < session)
    {
        return false;
    }
    if(userid < __rhs.userid)
    {
        return true;
    }
    else if(__rhs.userid < userid)
    {
        return false;
    }
    if(mute < __rhs.mute)
    {
        return true;
    }
    else if(__rhs.mute < mute)
    {
        return false;
    }
    if(deaf < __rhs.deaf)
    {
        return true;
    }
    else if(__rhs.deaf < deaf)
    {
        return false;
    }
    if(suppress < __rhs.suppress)
    {
        return true;
    }
    else if(__rhs.suppress < suppress)
    {
        return false;
    }
    if(selfMute < __rhs.selfMute)
    {
        return true;
    }
    else if(__rhs.selfMute < selfMute)
    {
        return false;
    }
    if(selfDeaf < __rhs.selfDeaf)
    {
        return true;
    }
    else if(__rhs.selfDeaf < selfDeaf)
    {
        return false;
    }
    if(channel < __rhs.channel)
    {
        return true;
    }
    else if(__rhs.channel < channel)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(onlinesecs < __rhs.onlinesecs)
    {
        return true;
    }
    else if(__rhs.onlinesecs < onlinesecs)
    {
        return false;
    }
    if(bytespersec < __rhs.bytespersec)
    {
        return true;
    }
    else if(__rhs.bytespersec < bytespersec)
    {
        return false;
    }
    if(version < __rhs.version)
    {
        return true;
    }
    else if(__rhs.version < version)
    {
        return false;
    }
    if(release < __rhs.release)
    {
        return true;
    }
    else if(__rhs.release < release)
    {
        return false;
    }
    if(os < __rhs.os)
    {
        return true;
    }
    else if(__rhs.os < os)
    {
        return false;
    }
    if(osversion < __rhs.osversion)
    {
        return true;
    }
    else if(__rhs.osversion < osversion)
    {
        return false;
    }
    if(identity < __rhs.identity)
    {
        return true;
    }
    else if(__rhs.identity < identity)
    {
        return false;
    }
    if(context < __rhs.context)
    {
        return true;
    }
    else if(__rhs.context < context)
    {
        return false;
    }
    if(comment < __rhs.comment)
    {
        return true;
    }
    else if(__rhs.comment < comment)
    {
        return false;
    }
    if(address < __rhs.address)
    {
        return true;
    }
    else if(__rhs.address < address)
    {
        return false;
    }
    if(tcponly < __rhs.tcponly)
    {
        return true;
    }
    else if(__rhs.tcponly < tcponly)
    {
        return false;
    }
    if(idlesecs < __rhs.idlesecs)
    {
        return true;
    }
    else if(__rhs.idlesecs < idlesecs)
    {
        return false;
    }
    return false;
}

void
Murmur::User::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(session);
    __os->write(userid);
    __os->write(mute);
    __os->write(deaf);
    __os->write(suppress);
    __os->write(selfMute);
    __os->write(selfDeaf);
    __os->write(channel);
    __os->write(name);
    __os->write(onlinesecs);
    __os->write(bytespersec);
    __os->write(version);
    __os->write(release);
    __os->write(os);
    __os->write(osversion);
    __os->write(identity);
    __os->write(context);
    __os->write(comment);
    if(address.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&address[0], &address[0] + address.size());
    }
    __os->write(tcponly);
    __os->write(idlesecs);
}

void
Murmur::User::__read(::IceInternal::BasicStream* __is)
{
    __is->read(session);
    __is->read(userid);
    __is->read(mute);
    __is->read(deaf);
    __is->read(suppress);
    __is->read(selfMute);
    __is->read(selfDeaf);
    __is->read(channel);
    __is->read(name);
    __is->read(onlinesecs);
    __is->read(bytespersec);
    __is->read(version);
    __is->read(release);
    __is->read(os);
    __is->read(osversion);
    __is->read(identity);
    __is->read(context);
    __is->read(comment);
    ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___address;
    __is->read(___address);
    ::std::vector< ::Ice::Byte>(___address.first, ___address.second).swap(address);
    __is->read(tcponly);
    __is->read(idlesecs);
}

bool
Murmur::Channel::operator==(const Channel& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(id != __rhs.id)
    {
        return false;
    }
    if(name != __rhs.name)
    {
        return false;
    }
    if(parent != __rhs.parent)
    {
        return false;
    }
    if(links != __rhs.links)
    {
        return false;
    }
    if(description != __rhs.description)
    {
        return false;
    }
    if(temporary != __rhs.temporary)
    {
        return false;
    }
    if(position != __rhs.position)
    {
        return false;
    }
    return true;
}

bool
Murmur::Channel::operator<(const Channel& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(id < __rhs.id)
    {
        return true;
    }
    else if(__rhs.id < id)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(parent < __rhs.parent)
    {
        return true;
    }
    else if(__rhs.parent < parent)
    {
        return false;
    }
    if(links < __rhs.links)
    {
        return true;
    }
    else if(__rhs.links < links)
    {
        return false;
    }
    if(description < __rhs.description)
    {
        return true;
    }
    else if(__rhs.description < description)
    {
        return false;
    }
    if(temporary < __rhs.temporary)
    {
        return true;
    }
    else if(__rhs.temporary < temporary)
    {
        return false;
    }
    if(position < __rhs.position)
    {
        return true;
    }
    else if(__rhs.position < position)
    {
        return false;
    }
    return false;
}

void
Murmur::Channel::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(id);
    __os->write(name);
    __os->write(parent);
    if(links.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&links[0], &links[0] + links.size());
    }
    __os->write(description);
    __os->write(temporary);
    __os->write(position);
}

void
Murmur::Channel::__read(::IceInternal::BasicStream* __is)
{
    __is->read(id);
    __is->read(name);
    __is->read(parent);
    __is->read(links);
    __is->read(description);
    __is->read(temporary);
    __is->read(position);
}

bool
Murmur::Group::operator==(const Group& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(name != __rhs.name)
    {
        return false;
    }
    if(inherited != __rhs.inherited)
    {
        return false;
    }
    if(inherit != __rhs.inherit)
    {
        return false;
    }
    if(inheritable != __rhs.inheritable)
    {
        return false;
    }
    if(add != __rhs.add)
    {
        return false;
    }
    if(remove != __rhs.remove)
    {
        return false;
    }
    if(members != __rhs.members)
    {
        return false;
    }
    return true;
}

bool
Murmur::Group::operator<(const Group& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(inherited < __rhs.inherited)
    {
        return true;
    }
    else if(__rhs.inherited < inherited)
    {
        return false;
    }
    if(inherit < __rhs.inherit)
    {
        return true;
    }
    else if(__rhs.inherit < inherit)
    {
        return false;
    }
    if(inheritable < __rhs.inheritable)
    {
        return true;
    }
    else if(__rhs.inheritable < inheritable)
    {
        return false;
    }
    if(add < __rhs.add)
    {
        return true;
    }
    else if(__rhs.add < add)
    {
        return false;
    }
    if(remove < __rhs.remove)
    {
        return true;
    }
    else if(__rhs.remove < remove)
    {
        return false;
    }
    if(members < __rhs.members)
    {
        return true;
    }
    else if(__rhs.members < members)
    {
        return false;
    }
    return false;
}

void
Murmur::Group::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(name);
    __os->write(inherited);
    __os->write(inherit);
    __os->write(inheritable);
    if(add.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&add[0], &add[0] + add.size());
    }
    if(remove.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&remove[0], &remove[0] + remove.size());
    }
    if(members.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&members[0], &members[0] + members.size());
    }
}

void
Murmur::Group::__read(::IceInternal::BasicStream* __is)
{
    __is->read(name);
    __is->read(inherited);
    __is->read(inherit);
    __is->read(inheritable);
    __is->read(add);
    __is->read(remove);
    __is->read(members);
}

bool
Murmur::ACL::operator==(const ACL& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(applyHere != __rhs.applyHere)
    {
        return false;
    }
    if(applySubs != __rhs.applySubs)
    {
        return false;
    }
    if(inherited != __rhs.inherited)
    {
        return false;
    }
    if(userid != __rhs.userid)
    {
        return false;
    }
    if(group != __rhs.group)
    {
        return false;
    }
    if(allow != __rhs.allow)
    {
        return false;
    }
    if(deny != __rhs.deny)
    {
        return false;
    }
    return true;
}

bool
Murmur::ACL::operator<(const ACL& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(applyHere < __rhs.applyHere)
    {
        return true;
    }
    else if(__rhs.applyHere < applyHere)
    {
        return false;
    }
    if(applySubs < __rhs.applySubs)
    {
        return true;
    }
    else if(__rhs.applySubs < applySubs)
    {
        return false;
    }
    if(inherited < __rhs.inherited)
    {
        return true;
    }
    else if(__rhs.inherited < inherited)
    {
        return false;
    }
    if(userid < __rhs.userid)
    {
        return true;
    }
    else if(__rhs.userid < userid)
    {
        return false;
    }
    if(group < __rhs.group)
    {
        return true;
    }
    else if(__rhs.group < group)
    {
        return false;
    }
    if(allow < __rhs.allow)
    {
        return true;
    }
    else if(__rhs.allow < allow)
    {
        return false;
    }
    if(deny < __rhs.deny)
    {
        return true;
    }
    else if(__rhs.deny < deny)
    {
        return false;
    }
    return false;
}

void
Murmur::ACL::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(applyHere);
    __os->write(applySubs);
    __os->write(inherited);
    __os->write(userid);
    __os->write(group);
    __os->write(allow);
    __os->write(deny);
}

void
Murmur::ACL::__read(::IceInternal::BasicStream* __is)
{
    __is->read(applyHere);
    __is->read(applySubs);
    __is->read(inherited);
    __is->read(userid);
    __is->read(group);
    __is->read(allow);
    __is->read(deny);
}

bool
Murmur::Ban::operator==(const Ban& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(address != __rhs.address)
    {
        return false;
    }
    if(bits != __rhs.bits)
    {
        return false;
    }
    if(name != __rhs.name)
    {
        return false;
    }
    if(hash != __rhs.hash)
    {
        return false;
    }
    if(reason != __rhs.reason)
    {
        return false;
    }
    if(start != __rhs.start)
    {
        return false;
    }
    if(duration != __rhs.duration)
    {
        return false;
    }
    return true;
}

bool
Murmur::Ban::operator<(const Ban& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(address < __rhs.address)
    {
        return true;
    }
    else if(__rhs.address < address)
    {
        return false;
    }
    if(bits < __rhs.bits)
    {
        return true;
    }
    else if(__rhs.bits < bits)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(hash < __rhs.hash)
    {
        return true;
    }
    else if(__rhs.hash < hash)
    {
        return false;
    }
    if(reason < __rhs.reason)
    {
        return true;
    }
    else if(__rhs.reason < reason)
    {
        return false;
    }
    if(start < __rhs.start)
    {
        return true;
    }
    else if(__rhs.start < start)
    {
        return false;
    }
    if(duration < __rhs.duration)
    {
        return true;
    }
    else if(__rhs.duration < duration)
    {
        return false;
    }
    return false;
}

void
Murmur::Ban::__write(::IceInternal::BasicStream* __os) const
{
    if(address.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&address[0], &address[0] + address.size());
    }
    __os->write(bits);
    __os->write(name);
    __os->write(hash);
    __os->write(reason);
    __os->write(start);
    __os->write(duration);
}

void
Murmur::Ban::__read(::IceInternal::BasicStream* __is)
{
    ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___address;
    __is->read(___address);
    ::std::vector< ::Ice::Byte>(___address.first, ___address.second).swap(address);
    __is->read(bits);
    __is->read(name);
    __is->read(hash);
    __is->read(reason);
    __is->read(start);
    __is->read(duration);
}

bool
Murmur::LogEntry::operator==(const LogEntry& __rhs) const
{
    if(this == &__rhs)
    {
        return true;
    }
    if(timestamp != __rhs.timestamp)
    {
        return false;
    }
    if(txt != __rhs.txt)
    {
        return false;
    }
    return true;
}

bool
Murmur::LogEntry::operator<(const LogEntry& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(timestamp < __rhs.timestamp)
    {
        return true;
    }
    else if(__rhs.timestamp < timestamp)
    {
        return false;
    }
    if(txt < __rhs.txt)
    {
        return true;
    }
    else if(__rhs.txt < txt)
    {
        return false;
    }
    return false;
}

void
Murmur::LogEntry::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(timestamp);
    __os->write(txt);
}

void
Murmur::LogEntry::__read(::IceInternal::BasicStream* __is)
{
    __is->read(timestamp);
    __is->read(txt);
}

void
Murmur::__writeTreeList(::IceInternal::BasicStream* __os, const ::Murmur::TreePtr* begin, const ::Murmur::TreePtr* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        __os->write(::Ice::ObjectPtr(::IceInternal::upCast(begin[i].get())));
    }
}

void
Murmur::__readTreeList(::IceInternal::BasicStream* __is, ::Murmur::TreeList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 4);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        __is->read(::Murmur::__patch__TreePtr, &v[i]);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__write(::IceInternal::BasicStream* __os, ::Murmur::ChannelInfo v)
{
    __os->write(static_cast< ::Ice::Byte>(v), 2);
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::ChannelInfo& v)
{
    ::Ice::Byte val;
    __is->read(val, 2);
    v = static_cast< ::Murmur::ChannelInfo>(val);
}

void
Murmur::__write(::IceInternal::BasicStream* __os, ::Murmur::UserInfo v)
{
    __os->write(static_cast< ::Ice::Byte>(v), 5);
}

void
Murmur::__read(::IceInternal::BasicStream* __is, ::Murmur::UserInfo& v)
{
    ::Ice::Byte val;
    __is->read(val, 5);
    v = static_cast< ::Murmur::UserInfo>(val);
}

void
Murmur::__writeUserMap(::IceInternal::BasicStream* __os, const ::Murmur::UserMap& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::Murmur::UserMap::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        p->second.__write(__os);
    }
}

void
Murmur::__readUserMap(::IceInternal::BasicStream* __is, ::Murmur::UserMap& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::Ice::Int, ::Murmur::User> pair;
        __is->read(const_cast< ::Ice::Int&>(pair.first));
        ::Murmur::UserMap::iterator __i = v.insert(v.end(), pair);
        __i->second.__read(__is);
    }
}

void
Murmur::__writeChannelMap(::IceInternal::BasicStream* __os, const ::Murmur::ChannelMap& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::Murmur::ChannelMap::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        p->second.__write(__os);
    }
}

void
Murmur::__readChannelMap(::IceInternal::BasicStream* __is, ::Murmur::ChannelMap& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::Ice::Int, ::Murmur::Channel> pair;
        __is->read(const_cast< ::Ice::Int&>(pair.first));
        ::Murmur::ChannelMap::iterator __i = v.insert(v.end(), pair);
        __i->second.__read(__is);
    }
}

void
Murmur::__writeChannelList(::IceInternal::BasicStream* __os, const ::Murmur::Channel* begin, const ::Murmur::Channel* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Murmur::__readChannelList(::IceInternal::BasicStream* __is, ::Murmur::ChannelList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 16);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeUserList(::IceInternal::BasicStream* __os, const ::Murmur::User* begin, const ::Murmur::User* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Murmur::__readUserList(::IceInternal::BasicStream* __is, ::Murmur::UserList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 42);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeGroupList(::IceInternal::BasicStream* __os, const ::Murmur::Group* begin, const ::Murmur::Group* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Murmur::__readGroupList(::IceInternal::BasicStream* __is, ::Murmur::GroupList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 7);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeACLList(::IceInternal::BasicStream* __os, const ::Murmur::ACL* begin, const ::Murmur::ACL* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Murmur::__readACLList(::IceInternal::BasicStream* __is, ::Murmur::ACLList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 16);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeLogList(::IceInternal::BasicStream* __os, const ::Murmur::LogEntry* begin, const ::Murmur::LogEntry* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Murmur::__readLogList(::IceInternal::BasicStream* __is, ::Murmur::LogList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 5);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeBanList(::IceInternal::BasicStream* __os, const ::Murmur::Ban* begin, const ::Murmur::Ban* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Murmur::__readBanList(::IceInternal::BasicStream* __is, ::Murmur::BanList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 20);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeNameMap(::IceInternal::BasicStream* __os, const ::Murmur::NameMap& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::Murmur::NameMap::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
Murmur::__readNameMap(::IceInternal::BasicStream* __is, ::Murmur::NameMap& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::Ice::Int, ::std::string> pair;
        __is->read(const_cast< ::Ice::Int&>(pair.first));
        ::Murmur::NameMap::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
Murmur::__writeIdMap(::IceInternal::BasicStream* __os, const ::Murmur::IdMap& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::Murmur::IdMap::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
Murmur::__readIdMap(::IceInternal::BasicStream* __is, ::Murmur::IdMap& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::Ice::Int> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::Murmur::IdMap::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
Murmur::__writeConfigMap(::IceInternal::BasicStream* __os, const ::Murmur::ConfigMap& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::Murmur::ConfigMap::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        __os->write(p->first);
        __os->write(p->second);
    }
}

void
Murmur::__readConfigMap(::IceInternal::BasicStream* __is, ::Murmur::ConfigMap& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::std::string, ::std::string> pair;
        __is->read(const_cast< ::std::string&>(pair.first));
        ::Murmur::ConfigMap::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

void
Murmur::__writeCertificateList(::IceInternal::BasicStream* __os, const ::Murmur::CertificateDer* begin, const ::Murmur::CertificateDer* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        if(begin[i].size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&begin[i][0], &begin[i][0] + begin[i].size());
        }
    }
}

void
Murmur::__readCertificateList(::IceInternal::BasicStream* __is, ::Murmur::CertificateList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 1);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___v;
        __is->read(___v);
        ::std::vector< ::Ice::Byte>(___v.first, ___v.second).swap(v[i]);
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Murmur::__writeUserInfoMap(::IceInternal::BasicStream* __os, const ::Murmur::UserInfoMap& v)
{
    __os->writeSize(::Ice::Int(v.size()));
    ::Murmur::UserInfoMap::const_iterator p;
    for(p = v.begin(); p != v.end(); ++p)
    {
        ::Murmur::__write(__os, p->first);
        __os->write(p->second);
    }
}

void
Murmur::__readUserInfoMap(::IceInternal::BasicStream* __is, ::Murmur::UserInfoMap& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    while(sz--)
    {
        ::std::pair<const  ::Murmur::UserInfo, ::std::string> pair;
        ::Murmur::__read(__is, const_cast< ::Murmur::UserInfo&>(pair.first));
        ::Murmur::UserInfoMap::iterator __i = v.insert(v.end(), pair);
        __is->read(__i->second);
    }
}

Murmur::MurmurException::~MurmurException() throw()
{
}

static const char* __Murmur__MurmurException_name = "Murmur::MurmurException";

::std::string
Murmur::MurmurException::ice_name() const
{
    return __Murmur__MurmurException_name;
}

::Ice::Exception*
Murmur::MurmurException::ice_clone() const
{
    return new MurmurException(*this);
}

void
Murmur::MurmurException::ice_throw() const
{
    throw *this;
}

void
Murmur::MurmurException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::MurmurException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
Murmur::MurmurException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
Murmur::MurmurException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::MurmurException was not generated with stream support";
    throw ex;
}

void
Murmur::MurmurException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::MurmurException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__MurmurException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::MurmurException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__MurmurException__Ptr = new __F__Murmur__MurmurException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::MurmurException::ice_factory()
{
    return __F__Murmur__MurmurException__Ptr;
}

class __F__Murmur__MurmurException__Init
{
public:

    __F__Murmur__MurmurException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::MurmurException", ::Murmur::MurmurException::ice_factory());
    }

    ~__F__Murmur__MurmurException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::MurmurException");
    }
};

static __F__Murmur__MurmurException__Init __F__Murmur__MurmurException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__MurmurException__initializer() {} }
#endif

Murmur::InvalidSessionException::~InvalidSessionException() throw()
{
}

static const char* __Murmur__InvalidSessionException_name = "Murmur::InvalidSessionException";

::std::string
Murmur::InvalidSessionException::ice_name() const
{
    return __Murmur__InvalidSessionException_name;
}

::Ice::Exception*
Murmur::InvalidSessionException::ice_clone() const
{
    return new InvalidSessionException(*this);
}

void
Murmur::InvalidSessionException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidSessionException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidSessionException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidSessionException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidSessionException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidSessionException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidSessionException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidSessionException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidSessionException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidSessionException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidSessionException__Ptr = new __F__Murmur__InvalidSessionException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidSessionException::ice_factory()
{
    return __F__Murmur__InvalidSessionException__Ptr;
}

class __F__Murmur__InvalidSessionException__Init
{
public:

    __F__Murmur__InvalidSessionException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidSessionException", ::Murmur::InvalidSessionException::ice_factory());
    }

    ~__F__Murmur__InvalidSessionException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidSessionException");
    }
};

static __F__Murmur__InvalidSessionException__Init __F__Murmur__InvalidSessionException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidSessionException__initializer() {} }
#endif

Murmur::InvalidChannelException::~InvalidChannelException() throw()
{
}

static const char* __Murmur__InvalidChannelException_name = "Murmur::InvalidChannelException";

::std::string
Murmur::InvalidChannelException::ice_name() const
{
    return __Murmur__InvalidChannelException_name;
}

::Ice::Exception*
Murmur::InvalidChannelException::ice_clone() const
{
    return new InvalidChannelException(*this);
}

void
Murmur::InvalidChannelException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidChannelException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidChannelException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidChannelException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidChannelException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidChannelException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidChannelException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidChannelException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidChannelException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidChannelException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidChannelException__Ptr = new __F__Murmur__InvalidChannelException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidChannelException::ice_factory()
{
    return __F__Murmur__InvalidChannelException__Ptr;
}

class __F__Murmur__InvalidChannelException__Init
{
public:

    __F__Murmur__InvalidChannelException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidChannelException", ::Murmur::InvalidChannelException::ice_factory());
    }

    ~__F__Murmur__InvalidChannelException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidChannelException");
    }
};

static __F__Murmur__InvalidChannelException__Init __F__Murmur__InvalidChannelException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidChannelException__initializer() {} }
#endif

Murmur::InvalidServerException::~InvalidServerException() throw()
{
}

static const char* __Murmur__InvalidServerException_name = "Murmur::InvalidServerException";

::std::string
Murmur::InvalidServerException::ice_name() const
{
    return __Murmur__InvalidServerException_name;
}

::Ice::Exception*
Murmur::InvalidServerException::ice_clone() const
{
    return new InvalidServerException(*this);
}

void
Murmur::InvalidServerException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidServerException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidServerException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidServerException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidServerException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidServerException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidServerException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidServerException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidServerException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidServerException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidServerException__Ptr = new __F__Murmur__InvalidServerException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidServerException::ice_factory()
{
    return __F__Murmur__InvalidServerException__Ptr;
}

class __F__Murmur__InvalidServerException__Init
{
public:

    __F__Murmur__InvalidServerException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidServerException", ::Murmur::InvalidServerException::ice_factory());
    }

    ~__F__Murmur__InvalidServerException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidServerException");
    }
};

static __F__Murmur__InvalidServerException__Init __F__Murmur__InvalidServerException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidServerException__initializer() {} }
#endif

Murmur::ServerBootedException::~ServerBootedException() throw()
{
}

static const char* __Murmur__ServerBootedException_name = "Murmur::ServerBootedException";

::std::string
Murmur::ServerBootedException::ice_name() const
{
    return __Murmur__ServerBootedException_name;
}

::Ice::Exception*
Murmur::ServerBootedException::ice_clone() const
{
    return new ServerBootedException(*this);
}

void
Murmur::ServerBootedException::ice_throw() const
{
    throw *this;
}

void
Murmur::ServerBootedException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::ServerBootedException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::ServerBootedException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::ServerBootedException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::ServerBootedException was not generated with stream support";
    throw ex;
}

void
Murmur::ServerBootedException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::ServerBootedException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__ServerBootedException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::ServerBootedException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__ServerBootedException__Ptr = new __F__Murmur__ServerBootedException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::ServerBootedException::ice_factory()
{
    return __F__Murmur__ServerBootedException__Ptr;
}

class __F__Murmur__ServerBootedException__Init
{
public:

    __F__Murmur__ServerBootedException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::ServerBootedException", ::Murmur::ServerBootedException::ice_factory());
    }

    ~__F__Murmur__ServerBootedException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::ServerBootedException");
    }
};

static __F__Murmur__ServerBootedException__Init __F__Murmur__ServerBootedException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__ServerBootedException__initializer() {} }
#endif

Murmur::ServerFailureException::~ServerFailureException() throw()
{
}

static const char* __Murmur__ServerFailureException_name = "Murmur::ServerFailureException";

::std::string
Murmur::ServerFailureException::ice_name() const
{
    return __Murmur__ServerFailureException_name;
}

::Ice::Exception*
Murmur::ServerFailureException::ice_clone() const
{
    return new ServerFailureException(*this);
}

void
Murmur::ServerFailureException::ice_throw() const
{
    throw *this;
}

void
Murmur::ServerFailureException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::ServerFailureException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::ServerFailureException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::ServerFailureException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::ServerFailureException was not generated with stream support";
    throw ex;
}

void
Murmur::ServerFailureException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::ServerFailureException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__ServerFailureException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::ServerFailureException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__ServerFailureException__Ptr = new __F__Murmur__ServerFailureException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::ServerFailureException::ice_factory()
{
    return __F__Murmur__ServerFailureException__Ptr;
}

class __F__Murmur__ServerFailureException__Init
{
public:

    __F__Murmur__ServerFailureException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::ServerFailureException", ::Murmur::ServerFailureException::ice_factory());
    }

    ~__F__Murmur__ServerFailureException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::ServerFailureException");
    }
};

static __F__Murmur__ServerFailureException__Init __F__Murmur__ServerFailureException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__ServerFailureException__initializer() {} }
#endif

Murmur::InvalidUserException::~InvalidUserException() throw()
{
}

static const char* __Murmur__InvalidUserException_name = "Murmur::InvalidUserException";

::std::string
Murmur::InvalidUserException::ice_name() const
{
    return __Murmur__InvalidUserException_name;
}

::Ice::Exception*
Murmur::InvalidUserException::ice_clone() const
{
    return new InvalidUserException(*this);
}

void
Murmur::InvalidUserException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidUserException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidUserException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidUserException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidUserException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidUserException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidUserException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidUserException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidUserException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidUserException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidUserException__Ptr = new __F__Murmur__InvalidUserException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidUserException::ice_factory()
{
    return __F__Murmur__InvalidUserException__Ptr;
}

class __F__Murmur__InvalidUserException__Init
{
public:

    __F__Murmur__InvalidUserException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidUserException", ::Murmur::InvalidUserException::ice_factory());
    }

    ~__F__Murmur__InvalidUserException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidUserException");
    }
};

static __F__Murmur__InvalidUserException__Init __F__Murmur__InvalidUserException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidUserException__initializer() {} }
#endif

Murmur::InvalidTextureException::~InvalidTextureException() throw()
{
}

static const char* __Murmur__InvalidTextureException_name = "Murmur::InvalidTextureException";

::std::string
Murmur::InvalidTextureException::ice_name() const
{
    return __Murmur__InvalidTextureException_name;
}

::Ice::Exception*
Murmur::InvalidTextureException::ice_clone() const
{
    return new InvalidTextureException(*this);
}

void
Murmur::InvalidTextureException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidTextureException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidTextureException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidTextureException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidTextureException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidTextureException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidTextureException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidTextureException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidTextureException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidTextureException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidTextureException__Ptr = new __F__Murmur__InvalidTextureException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidTextureException::ice_factory()
{
    return __F__Murmur__InvalidTextureException__Ptr;
}

class __F__Murmur__InvalidTextureException__Init
{
public:

    __F__Murmur__InvalidTextureException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidTextureException", ::Murmur::InvalidTextureException::ice_factory());
    }

    ~__F__Murmur__InvalidTextureException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidTextureException");
    }
};

static __F__Murmur__InvalidTextureException__Init __F__Murmur__InvalidTextureException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidTextureException__initializer() {} }
#endif

Murmur::InvalidCallbackException::~InvalidCallbackException() throw()
{
}

static const char* __Murmur__InvalidCallbackException_name = "Murmur::InvalidCallbackException";

::std::string
Murmur::InvalidCallbackException::ice_name() const
{
    return __Murmur__InvalidCallbackException_name;
}

::Ice::Exception*
Murmur::InvalidCallbackException::ice_clone() const
{
    return new InvalidCallbackException(*this);
}

void
Murmur::InvalidCallbackException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidCallbackException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidCallbackException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidCallbackException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidCallbackException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidCallbackException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidCallbackException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidCallbackException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidCallbackException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidCallbackException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidCallbackException__Ptr = new __F__Murmur__InvalidCallbackException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidCallbackException::ice_factory()
{
    return __F__Murmur__InvalidCallbackException__Ptr;
}

class __F__Murmur__InvalidCallbackException__Init
{
public:

    __F__Murmur__InvalidCallbackException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidCallbackException", ::Murmur::InvalidCallbackException::ice_factory());
    }

    ~__F__Murmur__InvalidCallbackException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidCallbackException");
    }
};

static __F__Murmur__InvalidCallbackException__Init __F__Murmur__InvalidCallbackException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidCallbackException__initializer() {} }
#endif

Murmur::InvalidSecretException::~InvalidSecretException() throw()
{
}

static const char* __Murmur__InvalidSecretException_name = "Murmur::InvalidSecretException";

::std::string
Murmur::InvalidSecretException::ice_name() const
{
    return __Murmur__InvalidSecretException_name;
}

::Ice::Exception*
Murmur::InvalidSecretException::ice_clone() const
{
    return new InvalidSecretException(*this);
}

void
Murmur::InvalidSecretException::ice_throw() const
{
    throw *this;
}

void
Murmur::InvalidSecretException::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Murmur::InvalidSecretException"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__write(__os);
#else
    ::Murmur::MurmurException::__write(__os);
#endif
}

void
Murmur::InvalidSecretException::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    MurmurException::__read(__is, true);
#else
    ::Murmur::MurmurException::__read(__is, true);
#endif
}

void
Murmur::InvalidSecretException::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidSecretException was not generated with stream support";
    throw ex;
}

void
Murmur::InvalidSecretException::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Murmur::InvalidSecretException was not generated with stream support";
    throw ex;
}

struct __F__Murmur__InvalidSecretException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Murmur::InvalidSecretException();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Murmur__InvalidSecretException__Ptr = new __F__Murmur__InvalidSecretException;

const ::IceInternal::UserExceptionFactoryPtr&
Murmur::InvalidSecretException::ice_factory()
{
    return __F__Murmur__InvalidSecretException__Ptr;
}

class __F__Murmur__InvalidSecretException__Init
{
public:

    __F__Murmur__InvalidSecretException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Murmur::InvalidSecretException", ::Murmur::InvalidSecretException::ice_factory());
    }

    ~__F__Murmur__InvalidSecretException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Murmur::InvalidSecretException");
    }
};

static __F__Murmur__InvalidSecretException__Init __F__Murmur__InvalidSecretException__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__InvalidSecretException__initializer() {} }
#endif

void
Murmur::__writeServerList(::IceInternal::BasicStream* __os, const ::Murmur::ServerPrx* begin, const ::Murmur::ServerPrx* end)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(begin[i].get())));
    }
}

void
Murmur::__readServerList(::IceInternal::BasicStream* __is, ::Murmur::ServerList& v)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 2);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        ::Murmur::__read(__is, v[i]);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

IceAsync::Murmur::AMD_Server_isRunning::AMD_Server_isRunning(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_isRunning::ice_response(bool __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_isRunning::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_isRunning::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_start::AMD_Server_start(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_start::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_start::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerFailureException* __ex = dynamic_cast<const ::Murmur::ServerFailureException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_start::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_stop::AMD_Server_stop(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_stop::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_stop::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_stop::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_delete::AMD_Server_delete(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_delete::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_delete::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_delete::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_id::AMD_Server_id(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_id::ice_response(::Ice::Int __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_id::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_id::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_addCallback::AMD_Server_addCallback(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_addCallback::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_addCallback::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_addCallback::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_removeCallback::AMD_Server_removeCallback(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_removeCallback::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_removeCallback::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_removeCallback::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setAuthenticator::AMD_Server_setAuthenticator(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setAuthenticator::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setAuthenticator::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_setAuthenticator::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getConf::AMD_Server_getConf(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getConf::ice_response(const ::std::string& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getConf::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_getConf::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getAllConf::AMD_Server_getAllConf(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getAllConf::ice_response(const ::Murmur::ConfigMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeConfigMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getAllConf::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_getAllConf::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setConf::AMD_Server_setConf(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setConf::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setConf::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_setConf::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setSuperuserPassword::AMD_Server_setSuperuserPassword(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setSuperuserPassword::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setSuperuserPassword::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_setSuperuserPassword::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getLog::AMD_Server_getLog(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getLog::ice_response(const ::Murmur::LogList& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(__ret.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeLogList(__os, &__ret[0], &__ret[0] + __ret.size());
            }
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getLog::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Server_getLog::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getUsers::AMD_Server_getUsers(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getUsers::ice_response(const ::Murmur::UserMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeUserMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getUsers::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getUsers::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getChannels::AMD_Server_getChannels(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getChannels::ice_response(const ::Murmur::ChannelMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeChannelMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getChannels::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getChannels::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getCertificateList::AMD_Server_getCertificateList(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getCertificateList::ice_response(const ::Murmur::CertificateList& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(__ret.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeCertificateList(__os, &__ret[0], &__ret[0] + __ret.size());
            }
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getCertificateList::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getCertificateList::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getTree::AMD_Server_getTree(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getTree::ice_response(const ::Murmur::TreePtr& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(::Ice::ObjectPtr(::IceInternal::upCast(__ret.get())));
            __os->writePendingObjects();
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getTree::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getTree::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getBans::AMD_Server_getBans(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getBans::ice_response(const ::Murmur::BanList& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(__ret.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeBanList(__os, &__ret[0], &__ret[0] + __ret.size());
            }
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getBans::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getBans::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setBans::AMD_Server_setBans(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setBans::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setBans::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_setBans::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_kickUser::AMD_Server_kickUser(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_kickUser::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_kickUser::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_kickUser::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getState::AMD_Server_getState(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getState::ice_response(const ::Murmur::User& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __ret.__write(__os);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getState::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getState::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setState::AMD_Server_setState(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setState::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setState::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_setState::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_sendMessage::AMD_Server_sendMessage(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_sendMessage::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_sendMessage::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_sendMessage::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_hasPermission::AMD_Server_hasPermission(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_hasPermission::ice_response(bool __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_hasPermission::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_hasPermission::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_addContextCallback::AMD_Server_addContextCallback(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_addContextCallback::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_addContextCallback::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_addContextCallback::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_removeContextCallback::AMD_Server_removeContextCallback(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_removeContextCallback::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_removeContextCallback::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_removeContextCallback::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getChannelState::AMD_Server_getChannelState(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getChannelState::ice_response(const ::Murmur::Channel& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __ret.__write(__os);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getChannelState::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getChannelState::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setChannelState::AMD_Server_setChannelState(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setChannelState::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setChannelState::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_setChannelState::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_removeChannel::AMD_Server_removeChannel(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_removeChannel::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_removeChannel::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_removeChannel::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_addChannel::AMD_Server_addChannel(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_addChannel::ice_response(::Ice::Int __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_addChannel::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_addChannel::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_sendMessageChannel::AMD_Server_sendMessageChannel(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_sendMessageChannel::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_sendMessageChannel::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_sendMessageChannel::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getACL::AMD_Server_getACL(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getACL::ice_response(const ::Murmur::ACLList& acls, const ::Murmur::GroupList& groups, bool inherit)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(acls.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeACLList(__os, &acls[0], &acls[0] + acls.size());
            }
            if(groups.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeGroupList(__os, &groups[0], &groups[0] + groups.size());
            }
            __os->write(inherit);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getACL::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getACL::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setACL::AMD_Server_setACL(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setACL::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setACL::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_setACL::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_addUserToGroup::AMD_Server_addUserToGroup(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_addUserToGroup::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_addUserToGroup::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_addUserToGroup::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_removeUserFromGroup::AMD_Server_removeUserFromGroup(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_removeUserFromGroup::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_removeUserFromGroup::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidChannelException* __ex = dynamic_cast<const ::Murmur::InvalidChannelException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_removeUserFromGroup::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_redirectWhisperGroup::AMD_Server_redirectWhisperGroup(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_redirectWhisperGroup::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_redirectWhisperGroup::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidSessionException* __ex = dynamic_cast<const ::Murmur::InvalidSessionException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_redirectWhisperGroup::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getUserNames::AMD_Server_getUserNames(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getUserNames::ice_response(const ::Murmur::NameMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeNameMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getUserNames::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getUserNames::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getUserIds::AMD_Server_getUserIds(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getUserIds::ice_response(const ::Murmur::IdMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeIdMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getUserIds::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getUserIds::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_registerUser::AMD_Server_registerUser(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_registerUser::ice_response(::Ice::Int __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_registerUser::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidUserException* __ex = dynamic_cast<const ::Murmur::InvalidUserException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_registerUser::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_unregisterUser::AMD_Server_unregisterUser(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_unregisterUser::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_unregisterUser::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidUserException* __ex = dynamic_cast<const ::Murmur::InvalidUserException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_unregisterUser::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_updateRegistration::AMD_Server_updateRegistration(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_updateRegistration::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_updateRegistration::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidUserException* __ex = dynamic_cast<const ::Murmur::InvalidUserException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_updateRegistration::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getRegistration::AMD_Server_getRegistration(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getRegistration::ice_response(const ::Murmur::UserInfoMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeUserInfoMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getRegistration::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidUserException* __ex = dynamic_cast<const ::Murmur::InvalidUserException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getRegistration::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getRegisteredUsers::AMD_Server_getRegisteredUsers(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getRegisteredUsers::ice_response(const ::Murmur::NameMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeNameMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getRegisteredUsers::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getRegisteredUsers::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_verifyPassword::AMD_Server_verifyPassword(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_verifyPassword::ice_response(::Ice::Int __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_verifyPassword::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_verifyPassword::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getTexture::AMD_Server_getTexture(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getTexture::ice_response(const ::Murmur::Texture& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(__ret.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                __os->write(&__ret[0], &__ret[0] + __ret.size());
            }
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getTexture::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidUserException* __ex = dynamic_cast<const ::Murmur::InvalidUserException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getTexture::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_setTexture::AMD_Server_setTexture(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_setTexture::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_setTexture::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidTextureException* __ex = dynamic_cast<const ::Murmur::InvalidTextureException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::InvalidUserException* __ex = dynamic_cast<const ::Murmur::InvalidUserException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_setTexture::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Server_getUptime::AMD_Server_getUptime(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Server_getUptime::ice_response(::Ice::Int __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Server_getUptime::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::ServerBootedException* __ex = dynamic_cast<const ::Murmur::ServerBootedException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Server_getUptime::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_getServer::AMD_Meta_getServer(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_getServer::ice_response(const ::Murmur::ServerPrx& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(::Ice::ObjectPrx(::IceInternal::upCast(__ret.get())));
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_getServer::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_getServer::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_newServer::AMD_Meta_newServer(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_newServer::ice_response(const ::Murmur::ServerPrx& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(::Ice::ObjectPrx(::IceInternal::upCast(__ret.get())));
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_newServer::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_newServer::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_getBootedServers::AMD_Meta_getBootedServers(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_getBootedServers::ice_response(const ::Murmur::ServerList& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(__ret.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeServerList(__os, &__ret[0], &__ret[0] + __ret.size());
            }
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_getBootedServers::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_getBootedServers::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_getAllServers::AMD_Meta_getAllServers(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_getAllServers::ice_response(const ::Murmur::ServerList& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            if(__ret.size() == 0)
            {
                __os->writeSize(0);
            }
            else
            {
                ::Murmur::__writeServerList(__os, &__ret[0], &__ret[0] + __ret.size());
            }
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_getAllServers::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_getAllServers::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_getDefaultConf::AMD_Meta_getDefaultConf(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_getDefaultConf::ice_response(const ::Murmur::ConfigMap& __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            ::Murmur::__writeConfigMap(__os, __ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_getDefaultConf::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_getDefaultConf::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_getVersion::AMD_Meta_getVersion(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_getVersion::ice_response(::Ice::Int major, ::Ice::Int minor, ::Ice::Int patch, const ::std::string& text)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(major);
            __os->write(minor);
            __os->write(patch);
            __os->write(text);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_getVersion::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_getVersion::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_addCallback::AMD_Meta_addCallback(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_addCallback::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_addCallback::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Meta_addCallback::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_removeCallback::AMD_Meta_removeCallback(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_removeCallback::ice_response()
{
    if(__validateResponse(true))
    {
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_removeCallback::ice_exception(const ::std::exception& ex)
{
    if(const ::Murmur::InvalidCallbackException* __ex = dynamic_cast<const ::Murmur::InvalidCallbackException*>(&ex))
    {
        if(__validateResponse(false))
        {
            __os()->write(*__ex);
            __response(false);
        }
    }
    else
    {
        if(__validateException(ex))
        {
            __exception(ex);
        }
    }
}

void
IceAsync::Murmur::AMD_Meta_removeCallback::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

IceAsync::Murmur::AMD_Meta_getUptime::AMD_Meta_getUptime(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Murmur::AMD_Meta_getUptime::ice_response(::Ice::Int __ret)
{
    if(__validateResponse(true))
    {
        try
        {
            ::IceInternal::BasicStream* __os = this->__os();
            __os->write(__ret);
        }
        catch(const ::Ice::Exception& __ex)
        {
            __exception(__ex);
            return;
        }
        __response(true);
    }
}

void
IceAsync::Murmur::AMD_Meta_getUptime::ice_exception(const ::std::exception& ex)
{
    if(__validateException(ex))
    {
        __exception(ex);
    }
}

void
IceAsync::Murmur::AMD_Meta_getUptime::ice_exception()
{
    if(__validateException())
    {
        __exception();
    }
}

const ::std::string&
IceProxy::Murmur::Tree::ice_staticId()
{
    return ::Murmur::Tree::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::Tree::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::Tree);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::Tree::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::Tree);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::Tree::__newInstance() const
{
    return new Tree;
}

void
IceProxy::Murmur::ServerCallback::userConnected(const ::Murmur::User& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerCallback*>(__delBase.get());
            __del->userConnected(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::ServerCallback::userDisconnected(const ::Murmur::User& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerCallback*>(__delBase.get());
            __del->userDisconnected(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::ServerCallback::userStateChanged(const ::Murmur::User& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerCallback*>(__delBase.get());
            __del->userStateChanged(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::ServerCallback::channelCreated(const ::Murmur::Channel& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerCallback*>(__delBase.get());
            __del->channelCreated(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::ServerCallback::channelRemoved(const ::Murmur::Channel& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerCallback*>(__delBase.get());
            __del->channelRemoved(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::ServerCallback::channelStateChanged(const ::Murmur::Channel& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerCallback*>(__delBase.get());
            __del->channelStateChanged(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::ServerCallback::ice_staticId()
{
    return ::Murmur::ServerCallback::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::ServerCallback::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::ServerCallback);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::ServerCallback::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::ServerCallback);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::ServerCallback::__newInstance() const
{
    return new ServerCallback;
}

void
IceProxy::Murmur::ServerContextCallback::contextAction(const ::std::string& action, const ::Murmur::User& usr, ::Ice::Int session, ::Ice::Int channelid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerContextCallback* __del = dynamic_cast< ::IceDelegate::Murmur::ServerContextCallback*>(__delBase.get());
            __del->contextAction(action, usr, session, channelid, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::ServerContextCallback::ice_staticId()
{
    return ::Murmur::ServerContextCallback::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::ServerContextCallback::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::ServerContextCallback);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::ServerContextCallback::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::ServerContextCallback);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::ServerContextCallback::__newInstance() const
{
    return new ServerContextCallback;
}

::Ice::Int
IceProxy::Murmur::ServerAuthenticator::authenticate(const ::std::string& name, const ::std::string& pw, const ::Murmur::CertificateList& certificates, const ::std::string& certhash, bool certstrong, ::std::string& newname, ::Murmur::GroupNameList& groups, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerAuthenticator__authenticate_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerAuthenticator*>(__delBase.get());
            return __del->authenticate(name, pw, certificates, certhash, certstrong, newname, groups, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

bool
IceProxy::Murmur::ServerAuthenticator::getInfo(::Ice::Int id, ::Murmur::UserInfoMap& info, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerAuthenticator__getInfo_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerAuthenticator*>(__delBase.get());
            return __del->getInfo(id, info, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::ServerAuthenticator::nameToId(const ::std::string& name, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerAuthenticator__nameToId_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerAuthenticator*>(__delBase.get());
            return __del->nameToId(name, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::std::string
IceProxy::Murmur::ServerAuthenticator::idToName(::Ice::Int id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerAuthenticator__idToName_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerAuthenticator*>(__delBase.get());
            return __del->idToName(id, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::Texture
IceProxy::Murmur::ServerAuthenticator::idToTexture(::Ice::Int id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerAuthenticator__idToTexture_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerAuthenticator*>(__delBase.get());
            return __del->idToTexture(id, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::ServerAuthenticator::ice_staticId()
{
    return ::Murmur::ServerAuthenticator::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::ServerAuthenticator::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::ServerAuthenticator);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::ServerAuthenticator::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::ServerAuthenticator);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::ServerAuthenticator::__newInstance() const
{
    return new ServerAuthenticator;
}

::Ice::Int
IceProxy::Murmur::ServerUpdatingAuthenticator::registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerUpdatingAuthenticator__registerUser_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerUpdatingAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerUpdatingAuthenticator*>(__delBase.get());
            return __del->registerUser(info, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::ServerUpdatingAuthenticator::unregisterUser(::Ice::Int id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerUpdatingAuthenticator__unregisterUser_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerUpdatingAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerUpdatingAuthenticator*>(__delBase.get());
            return __del->unregisterUser(id, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::NameMap
IceProxy::Murmur::ServerUpdatingAuthenticator::getRegisteredUsers(const ::std::string& filter, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerUpdatingAuthenticator__getRegisteredUsers_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerUpdatingAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerUpdatingAuthenticator*>(__delBase.get());
            return __del->getRegisteredUsers(filter, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::ServerUpdatingAuthenticator::setInfo(::Ice::Int id, const ::Murmur::UserInfoMap& info, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerUpdatingAuthenticator__setInfo_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerUpdatingAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerUpdatingAuthenticator*>(__delBase.get());
            return __del->setInfo(id, info, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::ServerUpdatingAuthenticator::setTexture(::Ice::Int id, const ::Murmur::Texture& tex, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__ServerUpdatingAuthenticator__setTexture_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::ServerUpdatingAuthenticator* __del = dynamic_cast< ::IceDelegate::Murmur::ServerUpdatingAuthenticator*>(__delBase.get());
            return __del->setTexture(id, tex, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::ServerUpdatingAuthenticator::ice_staticId()
{
    return ::Murmur::ServerUpdatingAuthenticator::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::ServerUpdatingAuthenticator::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::ServerUpdatingAuthenticator);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::ServerUpdatingAuthenticator::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::ServerUpdatingAuthenticator);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::ServerUpdatingAuthenticator::__newInstance() const
{
    return new ServerUpdatingAuthenticator;
}

bool
IceProxy::Murmur::Server::isRunning(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__isRunning_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->isRunning(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::start(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__start_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->start(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::stop(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__stop_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->stop(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::_cpp_delete(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__delete_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->_cpp_delete(__ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::Server::id(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__id_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->id(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::addCallback(const ::Murmur::ServerCallbackPrx& cb, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__addCallback_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->addCallback(cb, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::removeCallback(const ::Murmur::ServerCallbackPrx& cb, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__removeCallback_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->removeCallback(cb, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setAuthenticator(const ::Murmur::ServerAuthenticatorPrx& auth, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__setAuthenticator_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setAuthenticator(auth, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::std::string
IceProxy::Murmur::Server::getConf(const ::std::string& key, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getConf_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getConf(key, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::ConfigMap
IceProxy::Murmur::Server::getAllConf(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getAllConf_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getAllConf(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setConf(const ::std::string& key, const ::std::string& value, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setConf(key, value, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setSuperuserPassword(const ::std::string& pw, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setSuperuserPassword(pw, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::LogList
IceProxy::Murmur::Server::getLog(::Ice::Int first, ::Ice::Int last, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getLog_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getLog(first, last, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::UserMap
IceProxy::Murmur::Server::getUsers(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getUsers_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getUsers(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::ChannelMap
IceProxy::Murmur::Server::getChannels(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getChannels_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getChannels(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::CertificateList
IceProxy::Murmur::Server::getCertificateList(::Ice::Int session, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getCertificateList_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getCertificateList(session, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::TreePtr
IceProxy::Murmur::Server::getTree(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getTree_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getTree(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::BanList
IceProxy::Murmur::Server::getBans(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getBans_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getBans(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setBans(const ::Murmur::BanList& bans, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__setBans_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setBans(bans, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::kickUser(::Ice::Int session, const ::std::string& reason, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__kickUser_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->kickUser(session, reason, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::User
IceProxy::Murmur::Server::getState(::Ice::Int session, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getState_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getState(session, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setState(const ::Murmur::User& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__setState_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setState(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::sendMessage(::Ice::Int session, const ::std::string& text, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__sendMessage_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->sendMessage(session, text, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

bool
IceProxy::Murmur::Server::hasPermission(::Ice::Int session, ::Ice::Int channelid, ::Ice::Int perm, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__hasPermission_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->hasPermission(session, channelid, perm, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::addContextCallback(::Ice::Int session, const ::std::string& action, const ::std::string& text, const ::Murmur::ServerContextCallbackPrx& cb, ::Ice::Int ctx, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__addContextCallback_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->addContextCallback(session, action, text, cb, ctx, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::removeContextCallback(const ::Murmur::ServerContextCallbackPrx& cb, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__removeContextCallback_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->removeContextCallback(cb, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::Channel
IceProxy::Murmur::Server::getChannelState(::Ice::Int channelid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getChannelState_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getChannelState(channelid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setChannelState(const ::Murmur::Channel& state, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__setChannelState_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setChannelState(state, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::removeChannel(::Ice::Int channelid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__removeChannel_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->removeChannel(channelid, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::Server::addChannel(const ::std::string& name, ::Ice::Int parent, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__addChannel_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->addChannel(name, parent, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::sendMessageChannel(::Ice::Int channelid, bool tree, const ::std::string& text, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__sendMessageChannel_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->sendMessageChannel(channelid, tree, text, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::getACL(::Ice::Int channelid, ::Murmur::ACLList& acls, ::Murmur::GroupList& groups, bool& inherit, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getACL_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->getACL(channelid, acls, groups, inherit, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setACL(::Ice::Int channelid, const ::Murmur::ACLList& acls, const ::Murmur::GroupList& groups, bool inherit, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__setACL_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setACL(channelid, acls, groups, inherit, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::addUserToGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__addUserToGroup_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->addUserToGroup(channelid, session, group, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::removeUserFromGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__removeUserFromGroup_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->removeUserFromGroup(channelid, session, group, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::redirectWhisperGroup(::Ice::Int session, const ::std::string& source, const ::std::string& target, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__redirectWhisperGroup_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->redirectWhisperGroup(session, source, target, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::NameMap
IceProxy::Murmur::Server::getUserNames(const ::Murmur::IdList& ids, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getUserNames_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getUserNames(ids, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::IdMap
IceProxy::Murmur::Server::getUserIds(const ::Murmur::NameList& names, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getUserIds_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getUserIds(names, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::Server::registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__registerUser_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->registerUser(info, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::unregisterUser(::Ice::Int userid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__unregisterUser_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->unregisterUser(userid, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::updateRegistration(::Ice::Int userid, const ::Murmur::UserInfoMap& info, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__updateRegistration_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->updateRegistration(userid, info, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::UserInfoMap
IceProxy::Murmur::Server::getRegistration(::Ice::Int userid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getRegistration_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getRegistration(userid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::NameMap
IceProxy::Murmur::Server::getRegisteredUsers(const ::std::string& filter, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getRegisteredUsers_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getRegisteredUsers(filter, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::Server::verifyPassword(const ::std::string& name, const ::std::string& pw, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__verifyPassword_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->verifyPassword(name, pw, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::Texture
IceProxy::Murmur::Server::getTexture(::Ice::Int userid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getTexture_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getTexture(userid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Server::setTexture(::Ice::Int userid, const ::Murmur::Texture& tex, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__setTexture_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            __del->setTexture(userid, tex, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::Server::getUptime(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Server__getUptime_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Server* __del = dynamic_cast< ::IceDelegate::Murmur::Server*>(__delBase.get());
            return __del->getUptime(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::Server::ice_staticId()
{
    return ::Murmur::Server::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::Server::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::Server);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::Server::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::Server);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::Server::__newInstance() const
{
    return new Server;
}

void
IceProxy::Murmur::MetaCallback::started(const ::Murmur::ServerPrx& srv, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::MetaCallback* __del = dynamic_cast< ::IceDelegate::Murmur::MetaCallback*>(__delBase.get());
            __del->started(srv, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::MetaCallback::stopped(const ::Murmur::ServerPrx& srv, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::MetaCallback* __del = dynamic_cast< ::IceDelegate::Murmur::MetaCallback*>(__delBase.get());
            __del->stopped(srv, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::MetaCallback::ice_staticId()
{
    return ::Murmur::MetaCallback::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::MetaCallback::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::MetaCallback);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::MetaCallback::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::MetaCallback);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::MetaCallback::__newInstance() const
{
    return new MetaCallback;
}

::Murmur::ServerPrx
IceProxy::Murmur::Meta::getServer(::Ice::Int id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__getServer_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            return __del->getServer(id, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::ServerPrx
IceProxy::Murmur::Meta::newServer(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__newServer_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            return __del->newServer(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::ServerList
IceProxy::Murmur::Meta::getBootedServers(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__getBootedServers_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            return __del->getBootedServers(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::ServerList
IceProxy::Murmur::Meta::getAllServers(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__getAllServers_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            return __del->getAllServers(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Murmur::ConfigMap
IceProxy::Murmur::Meta::getDefaultConf(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__getDefaultConf_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            return __del->getDefaultConf(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Meta::getVersion(::Ice::Int& major, ::Ice::Int& minor, ::Ice::Int& patch, ::std::string& text, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__getVersion_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            __del->getVersion(major, minor, patch, text, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Meta::addCallback(const ::Murmur::MetaCallbackPrx& cb, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__addCallback_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            __del->addCallback(cb, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

void
IceProxy::Murmur::Meta::removeCallback(const ::Murmur::MetaCallbackPrx& cb, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__removeCallback_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            __del->removeCallback(cb, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, 0);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

::Ice::Int
IceProxy::Murmur::Meta::getUptime(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Murmur__Meta__getUptime_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::Murmur::Meta* __del = dynamic_cast< ::IceDelegate::Murmur::Meta*>(__delBase.get());
            return __del->getUptime(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, 0, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, 0, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Murmur::Meta::ice_staticId()
{
    return ::Murmur::Meta::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Murmur::Meta::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Murmur::Meta);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Murmur::Meta::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Murmur::Meta);
}

::IceProxy::Ice::Object*
IceProxy::Murmur::Meta::__newInstance() const
{
    return new Meta;
}

void
IceDelegateM::Murmur::ServerCallback::userConnected(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerCallback__userConnected_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::ServerCallback::userDisconnected(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerCallback__userDisconnected_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::ServerCallback::userStateChanged(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerCallback__userStateChanged_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::ServerCallback::channelCreated(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerCallback__channelCreated_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::ServerCallback::channelRemoved(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerCallback__channelRemoved_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::ServerCallback::channelStateChanged(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerCallback__channelStateChanged_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::ServerContextCallback::contextAction(const ::std::string& action, const ::Murmur::User& usr, ::Ice::Int session, ::Ice::Int channelid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerContextCallback__contextAction_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(action);
        usr.__write(__os);
        __os->write(session);
        __os->write(channelid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::Ice::Int
IceDelegateM::Murmur::ServerAuthenticator::authenticate(const ::std::string& name, const ::std::string& pw, const ::Murmur::CertificateList& certificates, const ::std::string& certhash, bool certstrong, ::std::string& newname, ::Murmur::GroupNameList& groups, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerAuthenticator__authenticate_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(pw);
        if(certificates.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Murmur::__writeCertificateList(__os, &certificates[0], &certificates[0] + certificates.size());
        }
        __os->write(certhash);
        __os->write(certstrong);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(newname);
        __is->read(groups);
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::Murmur::ServerAuthenticator::getInfo(::Ice::Int id, ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerAuthenticator__getInfo_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        bool __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readUserInfoMap(__is, info);
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::ServerAuthenticator::nameToId(const ::std::string& name, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerAuthenticator__nameToId_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::Murmur::ServerAuthenticator::idToName(::Ice::Int id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerAuthenticator__idToName_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::std::string __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::Texture
IceDelegateM::Murmur::ServerAuthenticator::idToTexture(::Ice::Int id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerAuthenticator__idToTexture_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::Texture __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> _____ret;
        __is->read(_____ret);
        ::std::vector< ::Ice::Byte>(_____ret.first, _____ret.second).swap(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::ServerUpdatingAuthenticator::registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerUpdatingAuthenticator__registerUser_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::Murmur::__writeUserInfoMap(__os, info);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::ServerUpdatingAuthenticator::unregisterUser(::Ice::Int id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerUpdatingAuthenticator__unregisterUser_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::NameMap
IceDelegateM::Murmur::ServerUpdatingAuthenticator::getRegisteredUsers(const ::std::string& filter, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerUpdatingAuthenticator__getRegisteredUsers_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(filter);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::NameMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readNameMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::ServerUpdatingAuthenticator::setInfo(::Ice::Int id, const ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerUpdatingAuthenticator__setInfo_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
        ::Murmur::__writeUserInfoMap(__os, info);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::ServerUpdatingAuthenticator::setTexture(::Ice::Int id, const ::Murmur::Texture& tex, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__ServerUpdatingAuthenticator__setTexture_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
        if(tex.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&tex[0], &tex[0] + tex.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::Murmur::Server::isRunning(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__isRunning_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        bool __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::start(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__start_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerFailureException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::stop(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__stop_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::_cpp_delete(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__delete_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::Server::id(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__id_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::addCallback(const ::Murmur::ServerCallbackPrx& cb, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__addCallback_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(cb.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::removeCallback(const ::Murmur::ServerCallbackPrx& cb, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__removeCallback_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(cb.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setAuthenticator(const ::Murmur::ServerAuthenticatorPrx& auth, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setAuthenticator_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(auth.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::std::string
IceDelegateM::Murmur::Server::getConf(const ::std::string& key, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getConf_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(key);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::std::string __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::ConfigMap
IceDelegateM::Murmur::Server::getAllConf(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getAllConf_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ConfigMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readConfigMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setConf(const ::std::string& key, const ::std::string& value, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setConf_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(key);
        __os->write(value);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::Server::setSuperuserPassword(const ::std::string& pw, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setSuperuserPassword_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(pw);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::Murmur::LogList
IceDelegateM::Murmur::Server::getLog(::Ice::Int first, ::Ice::Int last, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getLog_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(first);
        __os->write(last);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::LogList __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readLogList(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::UserMap
IceDelegateM::Murmur::Server::getUsers(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getUsers_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::UserMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readUserMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::ChannelMap
IceDelegateM::Murmur::Server::getChannels(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getChannels_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ChannelMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readChannelMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::CertificateList
IceDelegateM::Murmur::Server::getCertificateList(::Ice::Int session, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getCertificateList_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::CertificateList __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readCertificateList(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::TreePtr
IceDelegateM::Murmur::Server::getTree(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getTree_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::TreePtr __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(::Murmur::__patch__TreePtr, &__ret);
        __is->readPendingObjects();
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::BanList
IceDelegateM::Murmur::Server::getBans(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getBans_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::BanList __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readBanList(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setBans(const ::Murmur::BanList& bans, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setBans_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        if(bans.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Murmur::__writeBanList(__os, &bans[0], &bans[0] + bans.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::kickUser(::Ice::Int session, const ::std::string& reason, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__kickUser_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
        __os->write(reason);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::User
IceDelegateM::Murmur::Server::getState(::Ice::Int session, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getState_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::User __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __ret.__read(__is);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setState(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setState_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::sendMessage(::Ice::Int session, const ::std::string& text, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__sendMessage_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
        __os->write(text);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::Murmur::Server::hasPermission(::Ice::Int session, ::Ice::Int channelid, ::Ice::Int perm, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__hasPermission_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
        __os->write(channelid);
        __os->write(perm);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        bool __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::addContextCallback(::Ice::Int session, const ::std::string& action, const ::std::string& text, const ::Murmur::ServerContextCallbackPrx& cb, ::Ice::Int ctx, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__addContextCallback_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
        __os->write(action);
        __os->write(text);
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(cb.get())));
        __os->write(ctx);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::removeContextCallback(const ::Murmur::ServerContextCallbackPrx& cb, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__removeContextCallback_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(cb.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::Channel
IceDelegateM::Murmur::Server::getChannelState(::Ice::Int channelid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getChannelState_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::Channel __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __ret.__read(__is);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setChannelState(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setChannelState_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        state.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::removeChannel(::Ice::Int channelid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__removeChannel_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::Server::addChannel(const ::std::string& name, ::Ice::Int parent, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__addChannel_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(parent);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::sendMessageChannel(::Ice::Int channelid, bool tree, const ::std::string& text, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__sendMessageChannel_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
        __os->write(tree);
        __os->write(text);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::getACL(::Ice::Int channelid, ::Murmur::ACLList& acls, ::Murmur::GroupList& groups, bool& inherit, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getACL_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readACLList(__is, acls);
        ::Murmur::__readGroupList(__is, groups);
        __is->read(inherit);
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setACL(::Ice::Int channelid, const ::Murmur::ACLList& acls, const ::Murmur::GroupList& groups, bool inherit, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setACL_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
        if(acls.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Murmur::__writeACLList(__os, &acls[0], &acls[0] + acls.size());
        }
        if(groups.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Murmur::__writeGroupList(__os, &groups[0], &groups[0] + groups.size());
        }
        __os->write(inherit);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::addUserToGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__addUserToGroup_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
        __os->write(session);
        __os->write(group);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::removeUserFromGroup(::Ice::Int channelid, ::Ice::Int session, const ::std::string& group, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__removeUserFromGroup_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(channelid);
        __os->write(session);
        __os->write(group);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidChannelException&)
            {
                throw;
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::redirectWhisperGroup(::Ice::Int session, const ::std::string& source, const ::std::string& target, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__redirectWhisperGroup_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(session);
        __os->write(source);
        __os->write(target);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidSessionException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::NameMap
IceDelegateM::Murmur::Server::getUserNames(const ::Murmur::IdList& ids, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getUserNames_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        if(ids.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&ids[0], &ids[0] + ids.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::NameMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readNameMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::IdMap
IceDelegateM::Murmur::Server::getUserIds(const ::Murmur::NameList& names, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getUserIds_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        if(names.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&names[0], &names[0] + names.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::IdMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readIdMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::Server::registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__registerUser_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        ::Murmur::__writeUserInfoMap(__os, info);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidUserException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::unregisterUser(::Ice::Int userid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__unregisterUser_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidUserException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::updateRegistration(::Ice::Int userid, const ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__updateRegistration_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userid);
        ::Murmur::__writeUserInfoMap(__os, info);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidUserException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::UserInfoMap
IceDelegateM::Murmur::Server::getRegistration(::Ice::Int userid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getRegistration_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidUserException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::UserInfoMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readUserInfoMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::NameMap
IceDelegateM::Murmur::Server::getRegisteredUsers(const ::std::string& filter, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getRegisteredUsers_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(filter);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::NameMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readNameMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::Server::verifyPassword(const ::std::string& name, const ::std::string& pw, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__verifyPassword_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
        __os->write(pw);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::Texture
IceDelegateM::Murmur::Server::getTexture(::Ice::Int userid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getTexture_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidUserException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::Texture __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> _____ret;
        __is->read(_____ret);
        ::std::vector< ::Ice::Byte>(_____ret.first, _____ret.second).swap(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Server::setTexture(::Ice::Int userid, const ::Murmur::Texture& tex, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__setTexture_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(userid);
        if(tex.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&tex[0], &tex[0] + tex.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidTextureException&)
            {
                throw;
            }
            catch(const ::Murmur::InvalidUserException&)
            {
                throw;
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::Server::getUptime(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Server__getUptime_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::ServerBootedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::MetaCallback::started(const ::Murmur::ServerPrx& srv, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__MetaCallback__started_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(srv.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateM::Murmur::MetaCallback::stopped(const ::Murmur::ServerPrx& srv, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__MetaCallback__stopped_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(srv.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

::Murmur::ServerPrx
IceDelegateM::Murmur::Meta::getServer(::Ice::Int id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__getServer_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ServerPrx __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__read(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::ServerPrx
IceDelegateM::Murmur::Meta::newServer(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__newServer_name, ::Ice::Normal, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ServerPrx __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__read(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::ServerList
IceDelegateM::Murmur::Meta::getBootedServers(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__getBootedServers_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ServerList __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readServerList(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::ServerList
IceDelegateM::Murmur::Meta::getAllServers(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__getAllServers_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ServerList __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readServerList(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Murmur::ConfigMap
IceDelegateM::Murmur::Meta::getDefaultConf(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__getDefaultConf_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Murmur::ConfigMap __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        ::Murmur::__readConfigMap(__is, __ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Meta::getVersion(::Ice::Int& major, ::Ice::Int& minor, ::Ice::Int& patch, ::std::string& text, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__getVersion_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(major);
        __is->read(minor);
        __is->read(patch);
        __is->read(text);
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Meta::addCallback(const ::Murmur::MetaCallbackPrx& cb, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__addCallback_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(cb.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Murmur::Meta::removeCallback(const ::Murmur::MetaCallbackPrx& cb, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__removeCallback_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPrx(::IceInternal::upCast(cb.get())));
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Murmur::InvalidCallbackException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->endReadEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::Murmur::Meta::getUptime(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __Murmur__Meta__getUptime_name, ::Ice::Idempotent, __context);
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::Ice::Int __ret;
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateD::Murmur::ServerCallback::userConnected(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::User& state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerCallback* servant = dynamic_cast< ::Murmur::ServerCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->userConnected(_m_state, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::User& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerCallback__userConnected_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::ServerCallback::userDisconnected(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::User& state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerCallback* servant = dynamic_cast< ::Murmur::ServerCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->userDisconnected(_m_state, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::User& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerCallback__userDisconnected_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::ServerCallback::userStateChanged(const ::Murmur::User& state, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::User& state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerCallback* servant = dynamic_cast< ::Murmur::ServerCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->userStateChanged(_m_state, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::User& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerCallback__userStateChanged_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::ServerCallback::channelCreated(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::Channel& state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerCallback* servant = dynamic_cast< ::Murmur::ServerCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->channelCreated(_m_state, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::Channel& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerCallback__channelCreated_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::ServerCallback::channelRemoved(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::Channel& state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerCallback* servant = dynamic_cast< ::Murmur::ServerCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->channelRemoved(_m_state, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::Channel& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerCallback__channelRemoved_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::ServerCallback::channelStateChanged(const ::Murmur::Channel& state, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::Channel& state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerCallback* servant = dynamic_cast< ::Murmur::ServerCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->channelStateChanged(_m_state, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::Channel& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerCallback__channelStateChanged_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::ServerContextCallback::contextAction(const ::std::string& action, const ::Murmur::User& usr, ::Ice::Int session, ::Ice::Int channelid, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::std::string& action, const ::Murmur::User& usr, ::Ice::Int session, ::Ice::Int channelid, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_action(action),
            _m_usr(usr),
            _m_session(session),
            _m_channelid(channelid)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerContextCallback* servant = dynamic_cast< ::Murmur::ServerContextCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->contextAction(_m_action, _m_usr, _m_session, _m_channelid, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::std::string& _m_action;
        const ::Murmur::User& _m_usr;
        ::Ice::Int _m_session;
        ::Ice::Int _m_channelid;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerContextCallback__contextAction_name, ::Ice::Idempotent, __context);
    try
    {
        _DirectI __direct(action, usr, session, channelid, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Int
IceDelegateD::Murmur::ServerAuthenticator::authenticate(const ::std::string& name, const ::std::string& pw, const ::Murmur::CertificateList& certificates, const ::std::string& certhash, bool certstrong, ::std::string& newname, ::Murmur::GroupNameList& groups, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::std::string& name, const ::std::string& pw, const ::Murmur::CertificateList& certificates, const ::std::string& certhash, bool certstrong, ::std::string& newname, ::Murmur::GroupNameList& groups, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_name(name),
            _m_pw(pw),
            _m_certificates(certificates),
            _m_certhash(certhash),
            _m_certstrong(certstrong),
            _m_newname(newname),
            _m_groups(groups)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerAuthenticator* servant = dynamic_cast< ::Murmur::ServerAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->authenticate(_m_name, _m_pw, _m_certificates, _m_certhash, _m_certstrong, _m_newname, _m_groups, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        const ::std::string& _m_name;
        const ::std::string& _m_pw;
        const ::Murmur::CertificateList& _m_certificates;
        const ::std::string& _m_certhash;
        bool _m_certstrong;
        ::std::string& _m_newname;
        ::Murmur::GroupNameList& _m_groups;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerAuthenticator__authenticate_name, ::Ice::Idempotent, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, name, pw, certificates, certhash, certstrong, newname, groups, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

bool
IceDelegateD::Murmur::ServerAuthenticator::getInfo(::Ice::Int id, ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(bool& __result, ::Ice::Int id, ::Murmur::UserInfoMap& info, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_id(id),
            _m_info(info)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerAuthenticator* servant = dynamic_cast< ::Murmur::ServerAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getInfo(_m_id, _m_info, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        bool& _result;
        ::Ice::Int _m_id;
        ::Murmur::UserInfoMap& _m_info;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerAuthenticator__getInfo_name, ::Ice::Idempotent, __context);
    bool __result;
    try
    {
        _DirectI __direct(__result, id, info, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::Murmur::ServerAuthenticator::nameToId(const ::std::string& name, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::std::string& name, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_name(name)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerAuthenticator* servant = dynamic_cast< ::Murmur::ServerAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->nameToId(_m_name, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        const ::std::string& _m_name;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerAuthenticator__nameToId_name, ::Ice::Idempotent, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, name, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::std::string
IceDelegateD::Murmur::ServerAuthenticator::idToName(::Ice::Int id, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::std::string& __result, ::Ice::Int id, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_id(id)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerAuthenticator* servant = dynamic_cast< ::Murmur::ServerAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->idToName(_m_id, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::std::string& _result;
        ::Ice::Int _m_id;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerAuthenticator__idToName_name, ::Ice::Idempotent, __context);
    ::std::string __result;
    try
    {
        _DirectI __direct(__result, id, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Murmur::Texture
IceDelegateD::Murmur::ServerAuthenticator::idToTexture(::Ice::Int id, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Murmur::Texture& __result, ::Ice::Int id, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_id(id)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerAuthenticator* servant = dynamic_cast< ::Murmur::ServerAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->idToTexture(_m_id, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Murmur::Texture& _result;
        ::Ice::Int _m_id;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerAuthenticator__idToTexture_name, ::Ice::Idempotent, __context);
    ::Murmur::Texture __result;
    try
    {
        _DirectI __direct(__result, id, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::Murmur::ServerUpdatingAuthenticator::registerUser(const ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, const ::Murmur::UserInfoMap& info, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_info(info)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerUpdatingAuthenticator* servant = dynamic_cast< ::Murmur::ServerUpdatingAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->registerUser(_m_info, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        const ::Murmur::UserInfoMap& _m_info;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerUpdatingAuthenticator__registerUser_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, info, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::Murmur::ServerUpdatingAuthenticator::unregisterUser(::Ice::Int id, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, ::Ice::Int id, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_id(id)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerUpdatingAuthenticator* servant = dynamic_cast< ::Murmur::ServerUpdatingAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->unregisterUser(_m_id, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        ::Ice::Int _m_id;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerUpdatingAuthenticator__unregisterUser_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, id, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Murmur::NameMap
IceDelegateD::Murmur::ServerUpdatingAuthenticator::getRegisteredUsers(const ::std::string& filter, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Murmur::NameMap& __result, const ::std::string& filter, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_filter(filter)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerUpdatingAuthenticator* servant = dynamic_cast< ::Murmur::ServerUpdatingAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->getRegisteredUsers(_m_filter, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Murmur::NameMap& _result;
        const ::std::string& _m_filter;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerUpdatingAuthenticator__getRegisteredUsers_name, ::Ice::Idempotent, __context);
    ::Murmur::NameMap __result;
    try
    {
        _DirectI __direct(__result, filter, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::Murmur::ServerUpdatingAuthenticator::setInfo(::Ice::Int id, const ::Murmur::UserInfoMap& info, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, ::Ice::Int id, const ::Murmur::UserInfoMap& info, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_id(id),
            _m_info(info)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerUpdatingAuthenticator* servant = dynamic_cast< ::Murmur::ServerUpdatingAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->setInfo(_m_id, _m_info, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        ::Ice::Int _m_id;
        const ::Murmur::UserInfoMap& _m_info;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerUpdatingAuthenticator__setInfo_name, ::Ice::Idempotent, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, id, info, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::Murmur::ServerUpdatingAuthenticator::setTexture(::Ice::Int id, const ::Murmur::Texture& tex, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, ::Ice::Int id, const ::Murmur::Texture& tex, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_id(id),
            _m_tex(tex)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::ServerUpdatingAuthenticator* servant = dynamic_cast< ::Murmur::ServerUpdatingAuthenticator*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->setTexture(_m_id, _m_tex, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        ::Ice::Int _m_id;
        const ::Murmur::Texture& _m_tex;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__ServerUpdatingAuthenticator__setTexture_name, ::Ice::Idempotent, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, id, tex, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

bool
IceDelegateD::Murmur::Server::isRunning(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return bool(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::start(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::stop(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::_cpp_delete(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Ice::Int
IceDelegateD::Murmur::Server::id(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::addCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::removeCallback(const ::Murmur::ServerCallbackPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::setAuthenticator(const ::Murmur::ServerAuthenticatorPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::std::string
IceDelegateD::Murmur::Server::getConf(const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::std::string(); // to avoid a warning with some compilers;
}

::Murmur::ConfigMap
IceDelegateD::Murmur::Server::getAllConf(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ConfigMap(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::setConf(const ::std::string&, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::setSuperuserPassword(const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Murmur::LogList
IceDelegateD::Murmur::Server::getLog(::Ice::Int, ::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::LogList(); // to avoid a warning with some compilers;
}

::Murmur::UserMap
IceDelegateD::Murmur::Server::getUsers(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::UserMap(); // to avoid a warning with some compilers;
}

::Murmur::ChannelMap
IceDelegateD::Murmur::Server::getChannels(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ChannelMap(); // to avoid a warning with some compilers;
}

::Murmur::CertificateList
IceDelegateD::Murmur::Server::getCertificateList(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::CertificateList(); // to avoid a warning with some compilers;
}

::Murmur::TreePtr
IceDelegateD::Murmur::Server::getTree(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::TreePtr(); // to avoid a warning with some compilers;
}

::Murmur::BanList
IceDelegateD::Murmur::Server::getBans(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::BanList(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::setBans(const ::Murmur::BanList&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::kickUser(::Ice::Int, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Murmur::User
IceDelegateD::Murmur::Server::getState(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::User(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::setState(const ::Murmur::User&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::sendMessage(::Ice::Int, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

bool
IceDelegateD::Murmur::Server::hasPermission(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return bool(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::addContextCallback(::Ice::Int, const ::std::string&, const ::std::string&, const ::Murmur::ServerContextCallbackPrx&, ::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::removeContextCallback(const ::Murmur::ServerContextCallbackPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Murmur::Channel
IceDelegateD::Murmur::Server::getChannelState(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::Channel(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::setChannelState(const ::Murmur::Channel&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::removeChannel(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Ice::Int
IceDelegateD::Murmur::Server::addChannel(const ::std::string&, ::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::sendMessageChannel(::Ice::Int, bool, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::getACL(::Ice::Int, ::Murmur::ACLList&, ::Murmur::GroupList&, bool&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::setACL(::Ice::Int, const ::Murmur::ACLList&, const ::Murmur::GroupList&, bool, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::addUserToGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::removeUserFromGroup(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::redirectWhisperGroup(::Ice::Int, const ::std::string&, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Murmur::NameMap
IceDelegateD::Murmur::Server::getUserNames(const ::Murmur::IdList&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::NameMap(); // to avoid a warning with some compilers;
}

::Murmur::IdMap
IceDelegateD::Murmur::Server::getUserIds(const ::Murmur::NameList&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::IdMap(); // to avoid a warning with some compilers;
}

::Ice::Int
IceDelegateD::Murmur::Server::registerUser(const ::Murmur::UserInfoMap&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::unregisterUser(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Server::updateRegistration(::Ice::Int, const ::Murmur::UserInfoMap&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Murmur::UserInfoMap
IceDelegateD::Murmur::Server::getRegistration(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::UserInfoMap(); // to avoid a warning with some compilers;
}

::Murmur::NameMap
IceDelegateD::Murmur::Server::getRegisteredUsers(const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::NameMap(); // to avoid a warning with some compilers;
}

::Ice::Int
IceDelegateD::Murmur::Server::verifyPassword(const ::std::string&, const ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

::Murmur::Texture
IceDelegateD::Murmur::Server::getTexture(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::Texture(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Server::setTexture(::Ice::Int, const ::Murmur::Texture&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Ice::Int
IceDelegateD::Murmur::Server::getUptime(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::MetaCallback::started(const ::Murmur::ServerPrx& srv, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::ServerPrx& srv, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_srv(srv)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::MetaCallback* servant = dynamic_cast< ::Murmur::MetaCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->started(_m_srv, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::ServerPrx& _m_srv;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__MetaCallback__started_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(srv, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::Murmur::MetaCallback::stopped(const ::Murmur::ServerPrx& srv, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::Murmur::ServerPrx& srv, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_srv(srv)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::Murmur::MetaCallback* servant = dynamic_cast< ::Murmur::MetaCallback*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->stopped(_m_srv, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::Murmur::ServerPrx& _m_srv;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __Murmur__MetaCallback__stopped_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(srv, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Murmur::ServerPrx
IceDelegateD::Murmur::Meta::getServer(::Ice::Int, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ServerPrx(); // to avoid a warning with some compilers;
}

::Murmur::ServerPrx
IceDelegateD::Murmur::Meta::newServer(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ServerPrx(); // to avoid a warning with some compilers;
}

::Murmur::ServerList
IceDelegateD::Murmur::Meta::getBootedServers(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ServerList(); // to avoid a warning with some compilers;
}

::Murmur::ServerList
IceDelegateD::Murmur::Meta::getAllServers(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ServerList(); // to avoid a warning with some compilers;
}

::Murmur::ConfigMap
IceDelegateD::Murmur::Meta::getDefaultConf(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Murmur::ConfigMap(); // to avoid a warning with some compilers;
}

void
IceDelegateD::Murmur::Meta::getVersion(::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::std::string&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Meta::addCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

void
IceDelegateD::Murmur::Meta::removeCallback(const ::Murmur::MetaCallbackPrx&, const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
}

::Ice::Int
IceDelegateD::Murmur::Meta::getUptime(const ::Ice::Context*)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

Murmur::Tree::Tree(const ::Murmur::Channel& __ice_c, const ::Murmur::TreeList& __ice_children, const ::Murmur::UserList& __ice_users) :
    c(__ice_c),
    children(__ice_children),
    users(__ice_users)
{
}

::Ice::ObjectPtr
Murmur::Tree::ice_clone() const
{
    ::Murmur::TreePtr __p = new ::Murmur::Tree(*this);
    return __p;
}

static const ::std::string __Murmur__Tree_ids[2] =
{
    "::Ice::Object",
    "::Murmur::Tree"
};

bool
Murmur::Tree::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__Tree_ids, __Murmur__Tree_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::Tree::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__Tree_ids[0], &__Murmur__Tree_ids[2]);
}

const ::std::string&
Murmur::Tree::ice_id(const ::Ice::Current&) const
{
    return __Murmur__Tree_ids[1];
}

const ::std::string&
Murmur::Tree::ice_staticId()
{
    return __Murmur__Tree_ids[1];
}

void
Murmur::Tree::__incRef()
{
    __gcIncRef();
}

void
Murmur::Tree::__decRef()
{
    __gcDecRef();
}

void
Murmur::Tree::__addObject(::IceInternal::GCCountMap& _c)
{
    ::IceInternal::GCCountMap::iterator pos = _c.find(this);
    if(pos == _c.end())
    {
        _c[this] = 1;
    }
    else
    {
        ++pos->second;
    }
}

bool
Murmur::Tree::__usesClasses()
{
    return true;
}

void
Murmur::Tree::__gcReachable(::IceInternal::GCCountMap& _c) const
{
    {
        for(::Murmur::TreeList::const_iterator _i0 = children.begin(); _i0 != children.end(); ++_i0)
        {
            if((*_i0))
            {
                ::IceInternal::upCast((*_i0).get())->__addObject(_c);
            }
        }
    }
}

void
Murmur::Tree::__gcClear()
{
    {
        for(::Murmur::TreeList::iterator _i0 = children.begin(); _i0 != children.end(); ++_i0)
        {
            if((*_i0))
            {
                if(::IceInternal::upCast((*_i0).get())->__usesClasses())
                {
                    ::IceInternal::upCast((*_i0).get())->__decRefUnsafe();
                    (*_i0).__clearHandleUnsafe();
                }
                else
                {
                    (*_i0) = 0;
                }
            }
        }
    }
}

void
Murmur::Tree::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    c.__write(__os);
    if(children.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::Murmur::__writeTreeList(__os, &children[0], &children[0] + children.size());
    }
    if(users.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        ::Murmur::__writeUserList(__os, &users[0], &users[0] + users.size());
    }
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::Tree::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    c.__read(__is);
    ::Murmur::__readTreeList(__is, children);
    ::Murmur::__readUserList(__is, users);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::Tree::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::Tree was not generated with stream support";
    throw ex;
}

void
Murmur::Tree::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::Tree was not generated with stream support";
    throw ex;
}

class __F__Murmur__Tree : public ::Ice::ObjectFactory
{
public:

    virtual ::Ice::ObjectPtr
    create(const ::std::string& type)
    {
        assert(type == ::Murmur::Tree::ice_staticId());
        return new ::Murmur::Tree;
    }

    virtual void
    destroy()
    {
    }
};

static ::Ice::ObjectFactoryPtr __F__Murmur__Tree_Ptr = new __F__Murmur__Tree;

const ::Ice::ObjectFactoryPtr&
Murmur::Tree::ice_factory()
{
    return __F__Murmur__Tree_Ptr;
}

class __F__Murmur__Tree__Init
{
public:

    __F__Murmur__Tree__Init()
    {
        ::IceInternal::factoryTable->addObjectFactory(::Murmur::Tree::ice_staticId(), ::Murmur::Tree::ice_factory());
    }

    ~__F__Murmur__Tree__Init()
    {
        ::IceInternal::factoryTable->removeObjectFactory(::Murmur::Tree::ice_staticId());
    }
};

static __F__Murmur__Tree__Init __F__Murmur__Tree__i;

#ifdef __APPLE__
extern "C" { void __F__Murmur__Tree__initializer() {} }
#endif

void 
Murmur::__patch__TreePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::TreePtr* p = static_cast< ::Murmur::TreePtr*>(__addr);
    assert(p);
    *p = ::Murmur::TreePtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::Tree::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::Tree& l, const ::Murmur::Tree& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::Tree& l, const ::Murmur::Tree& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::ServerCallback::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__ServerCallback_ids[2] =
{
    "::Ice::Object",
    "::Murmur::ServerCallback"
};

bool
Murmur::ServerCallback::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__ServerCallback_ids, __Murmur__ServerCallback_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::ServerCallback::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__ServerCallback_ids[0], &__Murmur__ServerCallback_ids[2]);
}

const ::std::string&
Murmur::ServerCallback::ice_id(const ::Ice::Current&) const
{
    return __Murmur__ServerCallback_ids[1];
}

const ::std::string&
Murmur::ServerCallback::ice_staticId()
{
    return __Murmur__ServerCallback_ids[1];
}

::Ice::DispatchStatus
Murmur::ServerCallback::___userConnected(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::User state;
    state.__read(__is);
    __is->endReadEncaps();
    userConnected(state, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerCallback::___userDisconnected(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::User state;
    state.__read(__is);
    __is->endReadEncaps();
    userDisconnected(state, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerCallback::___userStateChanged(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::User state;
    state.__read(__is);
    __is->endReadEncaps();
    userStateChanged(state, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerCallback::___channelCreated(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::Channel state;
    state.__read(__is);
    __is->endReadEncaps();
    channelCreated(state, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerCallback::___channelRemoved(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::Channel state;
    state.__read(__is);
    __is->endReadEncaps();
    channelRemoved(state, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerCallback::___channelStateChanged(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::Channel state;
    state.__read(__is);
    __is->endReadEncaps();
    channelStateChanged(state, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __Murmur__ServerCallback_all[] =
{
    "channelCreated",
    "channelRemoved",
    "channelStateChanged",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "userConnected",
    "userDisconnected",
    "userStateChanged"
};

::Ice::DispatchStatus
Murmur::ServerCallback::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__ServerCallback_all, __Murmur__ServerCallback_all + 10, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__ServerCallback_all)
    {
        case 0:
        {
            return ___channelCreated(in, current);
        }
        case 1:
        {
            return ___channelRemoved(in, current);
        }
        case 2:
        {
            return ___channelStateChanged(in, current);
        }
        case 3:
        {
            return ___ice_id(in, current);
        }
        case 4:
        {
            return ___ice_ids(in, current);
        }
        case 5:
        {
            return ___ice_isA(in, current);
        }
        case 6:
        {
            return ___ice_ping(in, current);
        }
        case 7:
        {
            return ___userConnected(in, current);
        }
        case 8:
        {
            return ___userDisconnected(in, current);
        }
        case 9:
        {
            return ___userStateChanged(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::ServerCallback::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::ServerCallback::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::ServerCallback::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerCallback was not generated with stream support";
    throw ex;
}

void
Murmur::ServerCallback::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerCallback was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__ServerCallbackPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::ServerCallbackPtr* p = static_cast< ::Murmur::ServerCallbackPtr*>(__addr);
    assert(p);
    *p = ::Murmur::ServerCallbackPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::ServerCallback::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::ServerCallback& l, const ::Murmur::ServerCallback& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::ServerCallback& l, const ::Murmur::ServerCallback& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::ServerContextCallback::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__ServerContextCallback_ids[2] =
{
    "::Ice::Object",
    "::Murmur::ServerContextCallback"
};

bool
Murmur::ServerContextCallback::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__ServerContextCallback_ids, __Murmur__ServerContextCallback_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::ServerContextCallback::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__ServerContextCallback_ids[0], &__Murmur__ServerContextCallback_ids[2]);
}

const ::std::string&
Murmur::ServerContextCallback::ice_id(const ::Ice::Current&) const
{
    return __Murmur__ServerContextCallback_ids[1];
}

const ::std::string&
Murmur::ServerContextCallback::ice_staticId()
{
    return __Murmur__ServerContextCallback_ids[1];
}

::Ice::DispatchStatus
Murmur::ServerContextCallback::___contextAction(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string action;
    ::Murmur::User usr;
    ::Ice::Int session;
    ::Ice::Int channelid;
    __is->read(action);
    usr.__read(__is);
    __is->read(session);
    __is->read(channelid);
    __is->endReadEncaps();
    contextAction(action, usr, session, channelid, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __Murmur__ServerContextCallback_all[] =
{
    "contextAction",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
Murmur::ServerContextCallback::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__ServerContextCallback_all, __Murmur__ServerContextCallback_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__ServerContextCallback_all)
    {
        case 0:
        {
            return ___contextAction(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::ServerContextCallback::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::ServerContextCallback::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::ServerContextCallback::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerContextCallback was not generated with stream support";
    throw ex;
}

void
Murmur::ServerContextCallback::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerContextCallback was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__ServerContextCallbackPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::ServerContextCallbackPtr* p = static_cast< ::Murmur::ServerContextCallbackPtr*>(__addr);
    assert(p);
    *p = ::Murmur::ServerContextCallbackPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::ServerContextCallback::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::ServerContextCallback& l, const ::Murmur::ServerContextCallback& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::ServerContextCallback& l, const ::Murmur::ServerContextCallback& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::ServerAuthenticator::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__ServerAuthenticator_ids[2] =
{
    "::Ice::Object",
    "::Murmur::ServerAuthenticator"
};

bool
Murmur::ServerAuthenticator::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__ServerAuthenticator_ids, __Murmur__ServerAuthenticator_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::ServerAuthenticator::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__ServerAuthenticator_ids[0], &__Murmur__ServerAuthenticator_ids[2]);
}

const ::std::string&
Murmur::ServerAuthenticator::ice_id(const ::Ice::Current&) const
{
    return __Murmur__ServerAuthenticator_ids[1];
}

const ::std::string&
Murmur::ServerAuthenticator::ice_staticId()
{
    return __Murmur__ServerAuthenticator_ids[1];
}

::Ice::DispatchStatus
Murmur::ServerAuthenticator::___authenticate(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string name;
    ::std::string pw;
    ::Murmur::CertificateList certificates;
    ::std::string certhash;
    bool certstrong;
    __is->read(name);
    __is->read(pw);
    ::Murmur::__readCertificateList(__is, certificates);
    __is->read(certhash);
    __is->read(certstrong);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string newname;
    ::Murmur::GroupNameList groups;
    ::Ice::Int __ret = authenticate(name, pw, certificates, certhash, certstrong, newname, groups, __current);
    __os->write(newname);
    if(groups.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&groups[0], &groups[0] + groups.size());
    }
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerAuthenticator::___getInfo(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    __is->read(id);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Murmur::UserInfoMap info;
    bool __ret = getInfo(id, info, __current);
    ::Murmur::__writeUserInfoMap(__os, info);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerAuthenticator::___nameToId(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string name;
    __is->read(name);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = nameToId(name, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerAuthenticator::___idToName(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    __is->read(id);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string __ret = idToName(id, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerAuthenticator::___idToTexture(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    __is->read(id);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Murmur::Texture __ret = idToTexture(id, __current);
    if(__ret.size() == 0)
    {
        __os->writeSize(0);
    }
    else
    {
        __os->write(&__ret[0], &__ret[0] + __ret.size());
    }
    return ::Ice::DispatchOK;
}

static ::std::string __Murmur__ServerAuthenticator_all[] =
{
    "authenticate",
    "getInfo",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "idToName",
    "idToTexture",
    "nameToId"
};

::Ice::DispatchStatus
Murmur::ServerAuthenticator::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__ServerAuthenticator_all, __Murmur__ServerAuthenticator_all + 9, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__ServerAuthenticator_all)
    {
        case 0:
        {
            return ___authenticate(in, current);
        }
        case 1:
        {
            return ___getInfo(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
        case 6:
        {
            return ___idToName(in, current);
        }
        case 7:
        {
            return ___idToTexture(in, current);
        }
        case 8:
        {
            return ___nameToId(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::ServerAuthenticator::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::ServerAuthenticator::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::ServerAuthenticator::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerAuthenticator was not generated with stream support";
    throw ex;
}

void
Murmur::ServerAuthenticator::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerAuthenticator was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__ServerAuthenticatorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::ServerAuthenticatorPtr* p = static_cast< ::Murmur::ServerAuthenticatorPtr*>(__addr);
    assert(p);
    *p = ::Murmur::ServerAuthenticatorPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::ServerAuthenticator::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::ServerAuthenticator& l, const ::Murmur::ServerAuthenticator& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::ServerAuthenticator& l, const ::Murmur::ServerAuthenticator& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::ServerUpdatingAuthenticator::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__ServerUpdatingAuthenticator_ids[3] =
{
    "::Ice::Object",
    "::Murmur::ServerAuthenticator",
    "::Murmur::ServerUpdatingAuthenticator"
};

bool
Murmur::ServerUpdatingAuthenticator::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__ServerUpdatingAuthenticator_ids, __Murmur__ServerUpdatingAuthenticator_ids + 3, _s);
}

::std::vector< ::std::string>
Murmur::ServerUpdatingAuthenticator::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__ServerUpdatingAuthenticator_ids[0], &__Murmur__ServerUpdatingAuthenticator_ids[3]);
}

const ::std::string&
Murmur::ServerUpdatingAuthenticator::ice_id(const ::Ice::Current&) const
{
    return __Murmur__ServerUpdatingAuthenticator_ids[2];
}

const ::std::string&
Murmur::ServerUpdatingAuthenticator::ice_staticId()
{
    return __Murmur__ServerUpdatingAuthenticator_ids[2];
}

::Ice::DispatchStatus
Murmur::ServerUpdatingAuthenticator::___registerUser(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::UserInfoMap info;
    ::Murmur::__readUserInfoMap(__is, info);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = registerUser(info, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerUpdatingAuthenticator::___unregisterUser(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    __is->read(id);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = unregisterUser(id, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerUpdatingAuthenticator::___getRegisteredUsers(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string filter;
    __is->read(filter);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Murmur::NameMap __ret = getRegisteredUsers(filter, __current);
    ::Murmur::__writeNameMap(__os, __ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerUpdatingAuthenticator::___setInfo(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    ::Murmur::UserInfoMap info;
    __is->read(id);
    ::Murmur::__readUserInfoMap(__is, info);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = setInfo(id, info, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::ServerUpdatingAuthenticator::___setTexture(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    ::Murmur::Texture tex;
    __is->read(id);
    ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___tex;
    __is->read(___tex);
    ::std::vector< ::Ice::Byte>(___tex.first, ___tex.second).swap(tex);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = setTexture(id, tex, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

static ::std::string __Murmur__ServerUpdatingAuthenticator_all[] =
{
    "authenticate",
    "getInfo",
    "getRegisteredUsers",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "idToName",
    "idToTexture",
    "nameToId",
    "registerUser",
    "setInfo",
    "setTexture",
    "unregisterUser"
};

::Ice::DispatchStatus
Murmur::ServerUpdatingAuthenticator::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__ServerUpdatingAuthenticator_all, __Murmur__ServerUpdatingAuthenticator_all + 14, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__ServerUpdatingAuthenticator_all)
    {
        case 0:
        {
            return ___authenticate(in, current);
        }
        case 1:
        {
            return ___getInfo(in, current);
        }
        case 2:
        {
            return ___getRegisteredUsers(in, current);
        }
        case 3:
        {
            return ___ice_id(in, current);
        }
        case 4:
        {
            return ___ice_ids(in, current);
        }
        case 5:
        {
            return ___ice_isA(in, current);
        }
        case 6:
        {
            return ___ice_ping(in, current);
        }
        case 7:
        {
            return ___idToName(in, current);
        }
        case 8:
        {
            return ___idToTexture(in, current);
        }
        case 9:
        {
            return ___nameToId(in, current);
        }
        case 10:
        {
            return ___registerUser(in, current);
        }
        case 11:
        {
            return ___setInfo(in, current);
        }
        case 12:
        {
            return ___setTexture(in, current);
        }
        case 13:
        {
            return ___unregisterUser(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::ServerUpdatingAuthenticator::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::ServerUpdatingAuthenticator::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::ServerUpdatingAuthenticator::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerUpdatingAuthenticator was not generated with stream support";
    throw ex;
}

void
Murmur::ServerUpdatingAuthenticator::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::ServerUpdatingAuthenticator was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__ServerUpdatingAuthenticatorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::ServerUpdatingAuthenticatorPtr* p = static_cast< ::Murmur::ServerUpdatingAuthenticatorPtr*>(__addr);
    assert(p);
    *p = ::Murmur::ServerUpdatingAuthenticatorPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::ServerUpdatingAuthenticator::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::ServerUpdatingAuthenticator& l, const ::Murmur::ServerUpdatingAuthenticator& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::ServerUpdatingAuthenticator& l, const ::Murmur::ServerUpdatingAuthenticator& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::Server::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__Server_ids[2] =
{
    "::Ice::Object",
    "::Murmur::Server"
};

bool
Murmur::Server::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__Server_ids, __Murmur__Server_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::Server::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__Server_ids[0], &__Murmur__Server_ids[2]);
}

const ::std::string&
Murmur::Server::ice_id(const ::Ice::Current&) const
{
    return __Murmur__Server_ids[1];
}

const ::std::string&
Murmur::Server::ice_staticId()
{
    return __Murmur__Server_ids[1];
}

::Ice::DispatchStatus
Murmur::Server::___isRunning(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_isRunningPtr __cb = new IceAsync::Murmur::AMD_Server_isRunning(__inS);
    try
    {
        isRunning_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___start(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_startPtr __cb = new IceAsync::Murmur::AMD_Server_start(__inS);
    try
    {
        start_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___stop(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_stopPtr __cb = new IceAsync::Murmur::AMD_Server_stop(__inS);
    try
    {
        stop_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___delete(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_deletePtr __cb = new IceAsync::Murmur::AMD_Server_delete(__inS);
    try
    {
        delete_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___id(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_idPtr __cb = new IceAsync::Murmur::AMD_Server_id(__inS);
    try
    {
        id_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___addCallback(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::ServerCallbackPrx cb;
    ::Murmur::__read(__is, cb);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_addCallbackPtr __cb = new IceAsync::Murmur::AMD_Server_addCallback(__inS);
    try
    {
        addCallback_async(__cb, cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___removeCallback(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::ServerCallbackPrx cb;
    ::Murmur::__read(__is, cb);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_removeCallbackPtr __cb = new IceAsync::Murmur::AMD_Server_removeCallback(__inS);
    try
    {
        removeCallback_async(__cb, cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setAuthenticator(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::ServerAuthenticatorPrx auth;
    ::Murmur::__read(__is, auth);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setAuthenticatorPtr __cb = new IceAsync::Murmur::AMD_Server_setAuthenticator(__inS);
    try
    {
        setAuthenticator_async(__cb, auth, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getConf(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string key;
    __is->read(key);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getConfPtr __cb = new IceAsync::Murmur::AMD_Server_getConf(__inS);
    try
    {
        getConf_async(__cb, key, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getAllConf(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_getAllConfPtr __cb = new IceAsync::Murmur::AMD_Server_getAllConf(__inS);
    try
    {
        getAllConf_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setConf(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string key;
    ::std::string value;
    __is->read(key);
    __is->read(value);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setConfPtr __cb = new IceAsync::Murmur::AMD_Server_setConf(__inS);
    try
    {
        setConf_async(__cb, key, value, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setSuperuserPassword(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string pw;
    __is->read(pw);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setSuperuserPasswordPtr __cb = new IceAsync::Murmur::AMD_Server_setSuperuserPassword(__inS);
    try
    {
        setSuperuserPassword_async(__cb, pw, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getLog(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int first;
    ::Ice::Int last;
    __is->read(first);
    __is->read(last);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getLogPtr __cb = new IceAsync::Murmur::AMD_Server_getLog(__inS);
    try
    {
        getLog_async(__cb, first, last, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getUsers(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_getUsersPtr __cb = new IceAsync::Murmur::AMD_Server_getUsers(__inS);
    try
    {
        getUsers_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getChannels(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_getChannelsPtr __cb = new IceAsync::Murmur::AMD_Server_getChannels(__inS);
    try
    {
        getChannels_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getCertificateList(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    __is->read(session);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getCertificateListPtr __cb = new IceAsync::Murmur::AMD_Server_getCertificateList(__inS);
    try
    {
        getCertificateList_async(__cb, session, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getTree(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_getTreePtr __cb = new IceAsync::Murmur::AMD_Server_getTree(__inS);
    try
    {
        getTree_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getBans(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_getBansPtr __cb = new IceAsync::Murmur::AMD_Server_getBans(__inS);
    try
    {
        getBans_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setBans(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::BanList bans;
    ::Murmur::__readBanList(__is, bans);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setBansPtr __cb = new IceAsync::Murmur::AMD_Server_setBans(__inS);
    try
    {
        setBans_async(__cb, bans, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___kickUser(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    ::std::string reason;
    __is->read(session);
    __is->read(reason);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_kickUserPtr __cb = new IceAsync::Murmur::AMD_Server_kickUser(__inS);
    try
    {
        kickUser_async(__cb, session, reason, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getState(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    __is->read(session);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getStatePtr __cb = new IceAsync::Murmur::AMD_Server_getState(__inS);
    try
    {
        getState_async(__cb, session, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setState(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::User state;
    state.__read(__is);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setStatePtr __cb = new IceAsync::Murmur::AMD_Server_setState(__inS);
    try
    {
        setState_async(__cb, state, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___sendMessage(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    ::std::string text;
    __is->read(session);
    __is->read(text);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_sendMessagePtr __cb = new IceAsync::Murmur::AMD_Server_sendMessage(__inS);
    try
    {
        sendMessage_async(__cb, session, text, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___hasPermission(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    ::Ice::Int channelid;
    ::Ice::Int perm;
    __is->read(session);
    __is->read(channelid);
    __is->read(perm);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_hasPermissionPtr __cb = new IceAsync::Murmur::AMD_Server_hasPermission(__inS);
    try
    {
        hasPermission_async(__cb, session, channelid, perm, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___addContextCallback(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    ::std::string action;
    ::std::string text;
    ::Murmur::ServerContextCallbackPrx cb;
    ::Ice::Int ctx;
    __is->read(session);
    __is->read(action);
    __is->read(text);
    ::Murmur::__read(__is, cb);
    __is->read(ctx);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_addContextCallbackPtr __cb = new IceAsync::Murmur::AMD_Server_addContextCallback(__inS);
    try
    {
        addContextCallback_async(__cb, session, action, text, cb, ctx, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___removeContextCallback(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::ServerContextCallbackPrx cb;
    ::Murmur::__read(__is, cb);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_removeContextCallbackPtr __cb = new IceAsync::Murmur::AMD_Server_removeContextCallback(__inS);
    try
    {
        removeContextCallback_async(__cb, cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getChannelState(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    __is->read(channelid);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getChannelStatePtr __cb = new IceAsync::Murmur::AMD_Server_getChannelState(__inS);
    try
    {
        getChannelState_async(__cb, channelid, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setChannelState(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::Channel state;
    state.__read(__is);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setChannelStatePtr __cb = new IceAsync::Murmur::AMD_Server_setChannelState(__inS);
    try
    {
        setChannelState_async(__cb, state, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___removeChannel(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    __is->read(channelid);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_removeChannelPtr __cb = new IceAsync::Murmur::AMD_Server_removeChannel(__inS);
    try
    {
        removeChannel_async(__cb, channelid, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___addChannel(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string name;
    ::Ice::Int parent;
    __is->read(name);
    __is->read(parent);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_addChannelPtr __cb = new IceAsync::Murmur::AMD_Server_addChannel(__inS);
    try
    {
        addChannel_async(__cb, name, parent, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___sendMessageChannel(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    bool tree;
    ::std::string text;
    __is->read(channelid);
    __is->read(tree);
    __is->read(text);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_sendMessageChannelPtr __cb = new IceAsync::Murmur::AMD_Server_sendMessageChannel(__inS);
    try
    {
        sendMessageChannel_async(__cb, channelid, tree, text, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getACL(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    __is->read(channelid);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getACLPtr __cb = new IceAsync::Murmur::AMD_Server_getACL(__inS);
    try
    {
        getACL_async(__cb, channelid, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setACL(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    ::Murmur::ACLList acls;
    ::Murmur::GroupList groups;
    bool inherit;
    __is->read(channelid);
    ::Murmur::__readACLList(__is, acls);
    ::Murmur::__readGroupList(__is, groups);
    __is->read(inherit);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setACLPtr __cb = new IceAsync::Murmur::AMD_Server_setACL(__inS);
    try
    {
        setACL_async(__cb, channelid, acls, groups, inherit, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___addUserToGroup(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    ::Ice::Int session;
    ::std::string group;
    __is->read(channelid);
    __is->read(session);
    __is->read(group);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_addUserToGroupPtr __cb = new IceAsync::Murmur::AMD_Server_addUserToGroup(__inS);
    try
    {
        addUserToGroup_async(__cb, channelid, session, group, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___removeUserFromGroup(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int channelid;
    ::Ice::Int session;
    ::std::string group;
    __is->read(channelid);
    __is->read(session);
    __is->read(group);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_removeUserFromGroupPtr __cb = new IceAsync::Murmur::AMD_Server_removeUserFromGroup(__inS);
    try
    {
        removeUserFromGroup_async(__cb, channelid, session, group, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___redirectWhisperGroup(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int session;
    ::std::string source;
    ::std::string target;
    __is->read(session);
    __is->read(source);
    __is->read(target);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_redirectWhisperGroupPtr __cb = new IceAsync::Murmur::AMD_Server_redirectWhisperGroup(__inS);
    try
    {
        redirectWhisperGroup_async(__cb, session, source, target, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getUserNames(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::IdList ids;
    __is->read(ids);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getUserNamesPtr __cb = new IceAsync::Murmur::AMD_Server_getUserNames(__inS);
    try
    {
        getUserNames_async(__cb, ids, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getUserIds(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::NameList names;
    __is->read(names);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getUserIdsPtr __cb = new IceAsync::Murmur::AMD_Server_getUserIds(__inS);
    try
    {
        getUserIds_async(__cb, names, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___registerUser(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::UserInfoMap info;
    ::Murmur::__readUserInfoMap(__is, info);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_registerUserPtr __cb = new IceAsync::Murmur::AMD_Server_registerUser(__inS);
    try
    {
        registerUser_async(__cb, info, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___unregisterUser(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int userid;
    __is->read(userid);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_unregisterUserPtr __cb = new IceAsync::Murmur::AMD_Server_unregisterUser(__inS);
    try
    {
        unregisterUser_async(__cb, userid, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___updateRegistration(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int userid;
    ::Murmur::UserInfoMap info;
    __is->read(userid);
    ::Murmur::__readUserInfoMap(__is, info);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_updateRegistrationPtr __cb = new IceAsync::Murmur::AMD_Server_updateRegistration(__inS);
    try
    {
        updateRegistration_async(__cb, userid, info, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getRegistration(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int userid;
    __is->read(userid);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getRegistrationPtr __cb = new IceAsync::Murmur::AMD_Server_getRegistration(__inS);
    try
    {
        getRegistration_async(__cb, userid, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getRegisteredUsers(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string filter;
    __is->read(filter);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getRegisteredUsersPtr __cb = new IceAsync::Murmur::AMD_Server_getRegisteredUsers(__inS);
    try
    {
        getRegisteredUsers_async(__cb, filter, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___verifyPassword(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::std::string name;
    ::std::string pw;
    __is->read(name);
    __is->read(pw);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_verifyPasswordPtr __cb = new IceAsync::Murmur::AMD_Server_verifyPassword(__inS);
    try
    {
        verifyPassword_async(__cb, name, pw, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getTexture(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int userid;
    __is->read(userid);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_getTexturePtr __cb = new IceAsync::Murmur::AMD_Server_getTexture(__inS);
    try
    {
        getTexture_async(__cb, userid, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___setTexture(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int userid;
    ::Murmur::Texture tex;
    __is->read(userid);
    ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___tex;
    __is->read(___tex);
    ::std::vector< ::Ice::Byte>(___tex.first, ___tex.second).swap(tex);
    __is->endReadEncaps();
    ::Murmur::AMD_Server_setTexturePtr __cb = new IceAsync::Murmur::AMD_Server_setTexture(__inS);
    try
    {
        setTexture_async(__cb, userid, tex, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Server::___getUptime(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Server_getUptimePtr __cb = new IceAsync::Murmur::AMD_Server_getUptime(__inS);
    try
    {
        getUptime_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

static ::std::string __Murmur__Server_all[] =
{
    "addCallback",
    "addChannel",
    "addContextCallback",
    "addUserToGroup",
    "delete",
    "getACL",
    "getAllConf",
    "getBans",
    "getCertificateList",
    "getChannelState",
    "getChannels",
    "getConf",
    "getLog",
    "getRegisteredUsers",
    "getRegistration",
    "getState",
    "getTexture",
    "getTree",
    "getUptime",
    "getUserIds",
    "getUserNames",
    "getUsers",
    "hasPermission",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "id",
    "isRunning",
    "kickUser",
    "redirectWhisperGroup",
    "registerUser",
    "removeCallback",
    "removeChannel",
    "removeContextCallback",
    "removeUserFromGroup",
    "sendMessage",
    "sendMessageChannel",
    "setACL",
    "setAuthenticator",
    "setBans",
    "setChannelState",
    "setConf",
    "setState",
    "setSuperuserPassword",
    "setTexture",
    "start",
    "stop",
    "unregisterUser",
    "updateRegistration",
    "verifyPassword"
};

::Ice::DispatchStatus
Murmur::Server::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__Server_all, __Murmur__Server_all + 51, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__Server_all)
    {
        case 0:
        {
            return ___addCallback(in, current);
        }
        case 1:
        {
            return ___addChannel(in, current);
        }
        case 2:
        {
            return ___addContextCallback(in, current);
        }
        case 3:
        {
            return ___addUserToGroup(in, current);
        }
        case 4:
        {
            return ___delete(in, current);
        }
        case 5:
        {
            return ___getACL(in, current);
        }
        case 6:
        {
            return ___getAllConf(in, current);
        }
        case 7:
        {
            return ___getBans(in, current);
        }
        case 8:
        {
            return ___getCertificateList(in, current);
        }
        case 9:
        {
            return ___getChannelState(in, current);
        }
        case 10:
        {
            return ___getChannels(in, current);
        }
        case 11:
        {
            return ___getConf(in, current);
        }
        case 12:
        {
            return ___getLog(in, current);
        }
        case 13:
        {
            return ___getRegisteredUsers(in, current);
        }
        case 14:
        {
            return ___getRegistration(in, current);
        }
        case 15:
        {
            return ___getState(in, current);
        }
        case 16:
        {
            return ___getTexture(in, current);
        }
        case 17:
        {
            return ___getTree(in, current);
        }
        case 18:
        {
            return ___getUptime(in, current);
        }
        case 19:
        {
            return ___getUserIds(in, current);
        }
        case 20:
        {
            return ___getUserNames(in, current);
        }
        case 21:
        {
            return ___getUsers(in, current);
        }
        case 22:
        {
            return ___hasPermission(in, current);
        }
        case 23:
        {
            return ___ice_id(in, current);
        }
        case 24:
        {
            return ___ice_ids(in, current);
        }
        case 25:
        {
            return ___ice_isA(in, current);
        }
        case 26:
        {
            return ___ice_ping(in, current);
        }
        case 27:
        {
            return ___id(in, current);
        }
        case 28:
        {
            return ___isRunning(in, current);
        }
        case 29:
        {
            return ___kickUser(in, current);
        }
        case 30:
        {
            return ___redirectWhisperGroup(in, current);
        }
        case 31:
        {
            return ___registerUser(in, current);
        }
        case 32:
        {
            return ___removeCallback(in, current);
        }
        case 33:
        {
            return ___removeChannel(in, current);
        }
        case 34:
        {
            return ___removeContextCallback(in, current);
        }
        case 35:
        {
            return ___removeUserFromGroup(in, current);
        }
        case 36:
        {
            return ___sendMessage(in, current);
        }
        case 37:
        {
            return ___sendMessageChannel(in, current);
        }
        case 38:
        {
            return ___setACL(in, current);
        }
        case 39:
        {
            return ___setAuthenticator(in, current);
        }
        case 40:
        {
            return ___setBans(in, current);
        }
        case 41:
        {
            return ___setChannelState(in, current);
        }
        case 42:
        {
            return ___setConf(in, current);
        }
        case 43:
        {
            return ___setState(in, current);
        }
        case 44:
        {
            return ___setSuperuserPassword(in, current);
        }
        case 45:
        {
            return ___setTexture(in, current);
        }
        case 46:
        {
            return ___start(in, current);
        }
        case 47:
        {
            return ___stop(in, current);
        }
        case 48:
        {
            return ___unregisterUser(in, current);
        }
        case 49:
        {
            return ___updateRegistration(in, current);
        }
        case 50:
        {
            return ___verifyPassword(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::Server::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::Server::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::Server::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::Server was not generated with stream support";
    throw ex;
}

void
Murmur::Server::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::Server was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__ServerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::ServerPtr* p = static_cast< ::Murmur::ServerPtr*>(__addr);
    assert(p);
    *p = ::Murmur::ServerPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::Server::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::Server& l, const ::Murmur::Server& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::Server& l, const ::Murmur::Server& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::MetaCallback::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__MetaCallback_ids[2] =
{
    "::Ice::Object",
    "::Murmur::MetaCallback"
};

bool
Murmur::MetaCallback::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__MetaCallback_ids, __Murmur__MetaCallback_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::MetaCallback::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__MetaCallback_ids[0], &__Murmur__MetaCallback_ids[2]);
}

const ::std::string&
Murmur::MetaCallback::ice_id(const ::Ice::Current&) const
{
    return __Murmur__MetaCallback_ids[1];
}

const ::std::string&
Murmur::MetaCallback::ice_staticId()
{
    return __Murmur__MetaCallback_ids[1];
}

::Ice::DispatchStatus
Murmur::MetaCallback::___started(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::ServerPrx srv;
    ::Murmur::__read(__is, srv);
    __is->endReadEncaps();
    started(srv, __current);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
Murmur::MetaCallback::___stopped(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::ServerPrx srv;
    ::Murmur::__read(__is, srv);
    __is->endReadEncaps();
    stopped(srv, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __Murmur__MetaCallback_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "started",
    "stopped"
};

::Ice::DispatchStatus
Murmur::MetaCallback::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__MetaCallback_all, __Murmur__MetaCallback_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__MetaCallback_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___started(in, current);
        }
        case 5:
        {
            return ___stopped(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::MetaCallback::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::MetaCallback::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::MetaCallback::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::MetaCallback was not generated with stream support";
    throw ex;
}

void
Murmur::MetaCallback::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::MetaCallback was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__MetaCallbackPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::MetaCallbackPtr* p = static_cast< ::Murmur::MetaCallbackPtr*>(__addr);
    assert(p);
    *p = ::Murmur::MetaCallbackPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::MetaCallback::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::MetaCallback& l, const ::Murmur::MetaCallback& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::MetaCallback& l, const ::Murmur::MetaCallback& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

::Ice::ObjectPtr
Murmur::Meta::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Murmur__Meta_ids[2] =
{
    "::Ice::Object",
    "::Murmur::Meta"
};

bool
Murmur::Meta::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Murmur__Meta_ids, __Murmur__Meta_ids + 2, _s);
}

::std::vector< ::std::string>
Murmur::Meta::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Murmur__Meta_ids[0], &__Murmur__Meta_ids[2]);
}

const ::std::string&
Murmur::Meta::ice_id(const ::Ice::Current&) const
{
    return __Murmur__Meta_ids[1];
}

const ::std::string&
Murmur::Meta::ice_staticId()
{
    return __Murmur__Meta_ids[1];
}

::Ice::DispatchStatus
Murmur::Meta::___getServer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int id;
    __is->read(id);
    __is->endReadEncaps();
    ::Murmur::AMD_Meta_getServerPtr __cb = new IceAsync::Murmur::AMD_Meta_getServer(__inS);
    try
    {
        getServer_async(__cb, id, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___newServer(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Meta_newServerPtr __cb = new IceAsync::Murmur::AMD_Meta_newServer(__inS);
    try
    {
        newServer_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___getBootedServers(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Meta_getBootedServersPtr __cb = new IceAsync::Murmur::AMD_Meta_getBootedServers(__inS);
    try
    {
        getBootedServers_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___getAllServers(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Meta_getAllServersPtr __cb = new IceAsync::Murmur::AMD_Meta_getAllServers(__inS);
    try
    {
        getAllServers_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___getDefaultConf(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Meta_getDefaultConfPtr __cb = new IceAsync::Murmur::AMD_Meta_getDefaultConf(__inS);
    try
    {
        getDefaultConf_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___getVersion(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Meta_getVersionPtr __cb = new IceAsync::Murmur::AMD_Meta_getVersion(__inS);
    try
    {
        getVersion_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___addCallback(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::MetaCallbackPrx cb;
    ::Murmur::__read(__is, cb);
    __is->endReadEncaps();
    ::Murmur::AMD_Meta_addCallbackPtr __cb = new IceAsync::Murmur::AMD_Meta_addCallback(__inS);
    try
    {
        addCallback_async(__cb, cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___removeCallback(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Murmur::MetaCallbackPrx cb;
    ::Murmur::__read(__is, cb);
    __is->endReadEncaps();
    ::Murmur::AMD_Meta_removeCallbackPtr __cb = new IceAsync::Murmur::AMD_Meta_removeCallback(__inS);
    try
    {
        removeCallback_async(__cb, cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

::Ice::DispatchStatus
Murmur::Meta::___getUptime(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    __inS.is()->skipEmptyEncaps();
    ::Murmur::AMD_Meta_getUptimePtr __cb = new IceAsync::Murmur::AMD_Meta_getUptime(__inS);
    try
    {
        getUptime_async(__cb, __current);
    }
    catch(const ::std::exception& __ex)
    {
        __cb->ice_exception(__ex);
    }
    catch(...)
    {
        __cb->ice_exception();
    }
    return ::Ice::DispatchAsync;
}

static ::std::string __Murmur__Meta_all[] =
{
    "addCallback",
    "getAllServers",
    "getBootedServers",
    "getDefaultConf",
    "getServer",
    "getUptime",
    "getVersion",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "newServer",
    "removeCallback"
};

::Ice::DispatchStatus
Murmur::Meta::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Murmur__Meta_all, __Murmur__Meta_all + 13, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Murmur__Meta_all)
    {
        case 0:
        {
            return ___addCallback(in, current);
        }
        case 1:
        {
            return ___getAllServers(in, current);
        }
        case 2:
        {
            return ___getBootedServers(in, current);
        }
        case 3:
        {
            return ___getDefaultConf(in, current);
        }
        case 4:
        {
            return ___getServer(in, current);
        }
        case 5:
        {
            return ___getUptime(in, current);
        }
        case 6:
        {
            return ___getVersion(in, current);
        }
        case 7:
        {
            return ___ice_id(in, current);
        }
        case 8:
        {
            return ___ice_ids(in, current);
        }
        case 9:
        {
            return ___ice_isA(in, current);
        }
        case 10:
        {
            return ___ice_ping(in, current);
        }
        case 11:
        {
            return ___newServer(in, current);
        }
        case 12:
        {
            return ___removeCallback(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
Murmur::Meta::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Murmur::Meta::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Murmur::Meta::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::Meta was not generated with stream support";
    throw ex;
}

void
Murmur::Meta::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Murmur::Meta was not generated with stream support";
    throw ex;
}

void 
Murmur::__patch__MetaPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Murmur::MetaPtr* p = static_cast< ::Murmur::MetaPtr*>(__addr);
    assert(p);
    *p = ::Murmur::MetaPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Murmur::Meta::ice_staticId(), v->ice_id());
    }
}

bool
Murmur::operator==(const ::Murmur::Meta& l, const ::Murmur::Meta& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Murmur::operator<(const ::Murmur::Meta& l, const ::Murmur::Meta& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}
