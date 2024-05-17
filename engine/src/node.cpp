#include "bindings.h"
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <ParameterControllerNode/ParameterControllerNode.h>

void InitialiseNode()
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerNode>::Instance();
    const char* rpcPort = std::getenv( "RPC_PORT" );
    const char* tcpPort = std::getenv( "TCP_PORT" );
    pCInstance.LoadNodeConnectionInfo( rpcPort, tcpPort );
    pCInstance.PrintNodeConnectionInfo();
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto rpcInfo = std::make_unique<rpc::server>( pCInstance.GetRPCPort() );
    RPCInstance.SetRPCServerInfo( std::move( rpcInfo ) );
    performBindings();
    RPCInstance.RunServer();
}

int main()
{
    InitialiseNode();
    return 0;
}
