#include "RPCManager.h"

#include <iostream>
#include <memory>

void RPCManager::RunServer()
{
    mRPCServerHandler->run();
}

std::shared_ptr<rpc::server> RPCManager::GetRPCServer()
{
    return mRPCServerHandler;
}

void RPCManager::SetRPCServerInfo( std::shared_ptr<rpc::server> rpcServerHandler )
{
    mRPCServerHandler = move( rpcServerHandler );
}

void RPCManager::SetRPCClientInfo( RPCClientHandlers rpcClientHandlers )
{
    mRPCClientHandlers = move( rpcClientHandlers );
}
