#include "GlobalContextHub.h"

#include <iostream>

GlobalContextHub::GlobalContextHub()
{
    std::vector<std::shared_ptr<rpc::client>> clients;
    // TODO: move it to the separate function or sth

    auto hubPorts = PCTRL().GetHubPorts();
    auto hubIps = PCTRL().GetHubIPs();

    clients.resize( hubPorts.size() );

    for ( size_t i = 0; i < clients.size(); i++ )
    {
        // LOOK OUT! EMPLACE BACK HERE!!
        clients[i] = std::make_shared<rpc::client>( hubIps[i], std::stoi( hubPorts[i] ) );
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
