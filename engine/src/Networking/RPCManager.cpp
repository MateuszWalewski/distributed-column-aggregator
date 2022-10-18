#include "RPCManager.h"

#include <iostream>
#include <memory>

#include "rpc/client.h"
#include "rpc/server.h"

//circual dependency should be removed. Move BindMethods to SimpleAgs or to implementation of rpc interface


void RPCManager::RunServer()
{
    mNode->run();
}

void RPCManager::SetRPCClients(std::vector<std::shared_ptr<rpc::client>> clients)
{
    mHub = move( clients );
}
void RPCManager::SetRPCServer(std::shared_ptr<rpc::server> srv)
{
    mNode = move( srv );
}

std::shared_ptr<rpc::server> RPCManager::GetRPCServer()
{
    return mNode;
}

void RPCManager::BindMethods()
{
}