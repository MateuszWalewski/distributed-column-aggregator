#include "RPCManager.h"

#include <iostream>
#include <memory>

void RPCManager::RunServer() {
    _rpcServerHandler->run();
}

rpc::server* RPCManager::GetRpcServer() const {
    return _rpcServerHandler.get();
}

void RPCManager::SetRpcServerInfo(std::unique_ptr<rpc::server>&& rpcServerHandler) {
    _rpcServerHandler = move(rpcServerHandler);
}

void RPCManager::SetRpcClientInfo(RpcClientHandlers&& rpcClientHandlers) {
    _rpcClientHandlers = move(rpcClientHandlers);
}
