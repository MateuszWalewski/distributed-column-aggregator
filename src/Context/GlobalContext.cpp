#include "GlobalContext.h"

#include <iostream>

GlobalContext::GlobalContext() : mHubIP( "0.0.0.0" ), mHubPort( 5555 ), mNodeIP( "127.0.0.1" )
{
    std::vector<std::shared_ptr<rpc::client>> clients;
    if ( PCTRL().IsHub() )
    {
        auto hubPorts = PCTRL().GetHubPorts();
        auto hubIps = PCTRL().GetHubIPs();

        clients.resize( hubPorts.size() );

        for ( size_t i = 0; i < clients.size(); i++ )
        {
            // LOOK OUT! EMPLACE BACK HERE!!
            clients[i] = std::make_shared<rpc::client>( hubIps[i], std::stoi( hubPorts[i] ) );
        }
    }

    // move semantics here!!
    mSessionHandler = PCTRL().IsHub() ? std::make_shared<SessionHandler>( clients )
                                      : std::make_shared<SessionHandler>( std::make_shared<rpc::server>(
                                            PCTRL().GetNodeIP(), std::stoi( PCTRL().GetNodePort() ) ) );
}

GlobalContext & GlobalContext::Instance()
{
    static GlobalContext instance;
    return instance;
}

SessionHandler & GlobalContext::GetSessionHandler()
{
    return *mSessionHandler;
}

void GlobalContext::Hello()
{
    std::cout << "Hello I'm singleton!!!" << std::endl;
}