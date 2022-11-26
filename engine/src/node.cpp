#include <ColumnOperationsNode/ColumnOperationsNode.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <ParameterControllerNode/ParameterControllerNode.h>
#include <rpc/server.h>

void LoadDependencies( char* argv[] )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerNode>::Instance();

    pCInstance.LoadNodeConnectionInfo( argv );
    pCInstance.PrintNodeConnectionInfo();
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();

    RPCInstance.SetRPCServerInfo(
        std::make_shared<rpc::server>( pCInstance.GetNodeIP(), std::stoi( pCInstance.GetNodePort() ) ) );
    auto rpcServer = RPCInstance.GetRPCServer();

    rpcServer->bind( "CreateColumni", &calcs::CreateColumn<int> );
    rpcServer->bind( "DeleteColumni", &calcs::DeleteColumn<int> );
    rpcServer->bind( "AddElementi", &calcs::AddElement<int> );
    rpcServer->bind( "PrintColumni", &calcs::PrintColumn<int> );
    rpcServer->bind( "LoadCsvDatai", &calcs::LoadCsvData<int> );
    rpcServer->bind( "Sumi", &calcs::Sum<int> );

    rpcServer->bind( "CreateColumnd", &calcs::CreateColumn<double> );
    rpcServer->bind( "DeleteColumnd", &calcs::DeleteColumn<double> );
    rpcServer->bind( "AddElementd", &calcs::AddElement<double> );
    rpcServer->bind( "PrintColumnd", &calcs::PrintColumn<double> );
    rpcServer->bind( "LoadCsvDatad", &calcs::LoadCsvData<double> );
    rpcServer->bind( "Sumd", &calcs::Sum<double> );

    rpcServer->bind( "CreateColumnf", &calcs::CreateColumn<float> );
    rpcServer->bind( "DeleteColumnf", &calcs::DeleteColumn<float> );
    rpcServer->bind( "AddElementf", &calcs::AddElement<float> );
    rpcServer->bind( "PrintColumnf", &calcs::PrintColumn<float> );
    rpcServer->bind( "LoadCsvDataf", &calcs::LoadCsvData<float> );
    rpcServer->bind( "Sumf", &calcs::Sum<float> );

    RPCInstance.RunServer();
}

int main( int argc, char* argv[] )
{
    // TODO: input sanity check!!!
    (void) argc; // to silent warning
    LoadDependencies( argv );

    return 0;
}
