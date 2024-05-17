#include <ColumnOperationsNode/ColumnOperationsNode.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <ParameterControllerNode/ParameterControllerNode.h>
#include <TCPChannel/TCPClient.h>
#include <rpc/server.h>

void InitialiseNode()
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerNode>::Instance();
    const char* rpcPort = std::getenv( "RPC_PORT" );
    const char* tcpPort = std::getenv( "TCP_PORT" );
    pCInstance.LoadNodeConnectionInfo( rpcPort, tcpPort );
    pCInstance.PrintNodeConnectionInfo();
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();

    RPCInstance.SetRPCServerInfo( std::make_shared<rpc::server>( pCInstance.GetRPCPort() ) );
    auto rpcServer = RPCInstance.GetRPCServer();

    // TODO: kick it off to the separate function
    rpcServer->bind( "CreateColumni", &calcs::CreateColumn<int> );
    rpcServer->bind( "DeleteColumni", &calcs::DeleteColumn<int> );
    rpcServer->bind( "AddElementi", &calcs::AddElement<int> );
    rpcServer->bind( "Fetchi", &calcs::Fetch<int> );
    rpcServer->bind( "PrintColumni", &calcs::PrintColumn<int> );
    rpcServer->bind( "LoadCsvDatai", &calcs::LoadCsvData<int> );
    rpcServer->bind( "Sumi", &calcs::Sum<int> );
    rpcServer->bind( "SumX2i", &calcs::SumX2<int> );
    rpcServer->bind( "Counti", &calcs::Count<int> );

    rpcServer->bind( "CreateColumnd", &calcs::CreateColumn<double> );
    rpcServer->bind( "DeleteColumnd", &calcs::DeleteColumn<double> );
    rpcServer->bind( "AddElementd", &calcs::AddElement<double> );
    rpcServer->bind( "Fetchd", &calcs::Fetch<double> );
    rpcServer->bind( "PrintColumnd", &calcs::PrintColumn<double> );
    rpcServer->bind( "LoadCsvDatad", &calcs::LoadCsvData<double> );
    rpcServer->bind( "Sumd", &calcs::Sum<double> );
    rpcServer->bind( "SumX2d", &calcs::SumX2<double> );
    rpcServer->bind( "Countd", &calcs::Count<double> );

    rpcServer->bind( "CreateColumnf", &calcs::CreateColumn<float> );
    rpcServer->bind( "DeleteColumnf", &calcs::DeleteColumn<float> );
    rpcServer->bind( "AddElementf", &calcs::AddElement<float> );
    rpcServer->bind( "Fetchf", &calcs::Fetch<float> );
    rpcServer->bind( "PrintColumnf", &calcs::PrintColumn<float> );
    rpcServer->bind( "LoadCsvDataf", &calcs::LoadCsvData<float> );
    rpcServer->bind( "Sumf", &calcs::Sum<float> );
    rpcServer->bind( "SumX2f", &calcs::SumX2<float> );
    rpcServer->bind( "Countf", &calcs::Count<float> );

    RPCInstance.RunServer();
}

int main()
{
    InitialiseNode();
    return 0;
}
