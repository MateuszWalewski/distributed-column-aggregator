#include "GlobalContextHub.h"

#include <iostream>

GlobalContextHub::GlobalContextHub()
{
    std::vector<std::shared_ptr<rpc::client>> clients;
    // TODO: move it to the separate function or sth

    clients.resize( PCTRL().GetNodesPorts().size() );

    for ( size_t i = 0; i < clients.size(); i++ )
    {
        // LOOK OUT! EMPLACE BACK HERE!!
        clients[i] = std::make_shared<rpc::client>( PCTRL().GetNodesIPs()[i], std::stoi( PCTRL().GetNodesPorts()[i] ) );
    }

    mRpcManager = std::make_shared<RPCManager>();
    mRpcManager->SetRPCClients( clients );
}

GlobalContextHub & GlobalContextHub::Instance()
{
    static GlobalContextHub instance;
    return instance;
}

RPCManager & GlobalContextHub::GetRPCManager()
{
    return *mRpcManager;
}
