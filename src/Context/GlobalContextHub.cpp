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

    mSessionHandler = std::make_shared<SessionHandlerHub>( clients );
}

GlobalContextHub & GlobalContextHub::Instance()
{
    static GlobalContextHub instance;
    return instance;
}

SessionHandlerHub & GlobalContextHub::GetSessionHandler()
{
    return *mSessionHandler;
}
