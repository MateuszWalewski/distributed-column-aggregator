#include "RPCManager.h"

#include <iostream>
#include <memory>

void RPCManager::RunServer()
{
    mRpcServerHandler->run();
}

rpc::server* RPCManager::GetRpcServer() const
{
    return mRpcServerHandler.get();
}

void RPCManager::SetRpcServerInfo( std::unique_ptr<rpc::server>&& rpcServerHandler )
{
    mRpcServerHandler = move( rpcServerHandler );
}

void RPCManager::SetRpcClientInfo( RpcClientHandlers&& rpcClientHandlers )
{
    mRpcClientHandlers = move( rpcClientHandlers );
}
