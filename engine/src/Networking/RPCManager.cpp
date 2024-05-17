#include "RPCManager.h"

#include <iostream>
#include <memory>

void RPCManager::RunServer()
{
    mRPCServerHandler->run();
}

rpc::server* RPCManager::GetRPCServer() const
{
    return mRPCServerHandler.get();
}

void RPCManager::SetRPCServerInfo( std::unique_ptr<rpc::server>&& rpcServerHandler )
{
    mRPCServerHandler = move( rpcServerHandler );
}

void RPCManager::SetRPCClientInfo( RPCClientHandlers&& rpcClientHandlers )
{
    mRPCClientHandlers = move( rpcClientHandlers );
}
