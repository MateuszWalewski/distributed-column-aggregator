#include "RPCManager.h"

#include <iostream>
#include <memory>

#include "rpc/client.h"
#include "rpc/server.h"

RPCManager::RPCManager( RPCClientHandlers rpcClientHandlers ) : mRPCClientHandlers( move( rpcClientHandlers ) )
{
}

RPCManager::RPCManager( std::shared_ptr<rpc::server> rpcServerHandler ) : mRPCServerHandler( move( rpcServerHandler ) )
{
}

void RPCManager::RunServer()
{
    mRPCServerHandler->run();
}

std::shared_ptr<rpc::server> RPCManager::GetRPCServer()
{
    return mRPCServerHandler;
}

void RPCManager::BindMethods()
{
}