#include "GlobalContextHub.h"

#include <iostream>

GlobalContextHub::GlobalContextHub()
{
    RPCClientHandlers rpcClientHandlers;
    rpcClientHandlers.resize( PCTRL().GetNodesPorts().size() );

    for ( size_t i = 0; i < rpcClientHandlers.size(); i++ )
    {
        // LOOK OUT! EMPLACE BACK HERE!!
        rpcClientHandlers[i] = std::make_shared<rpc::client>( PCTRL().GetNodesIPs()[i], std::stoi( PCTRL().GetNodesPorts()[i] ) );
    }

    mRPCManager = std::make_shared<RPCManager>( rpcClientHandlers );
}

GlobalContextHub & GlobalContextHub::Instance()
{
    static GlobalContextHub instance;
    return instance;
}

RPCManager & GlobalContextHub::GetRPCManager()
{
    return *mRPCManager;
}
