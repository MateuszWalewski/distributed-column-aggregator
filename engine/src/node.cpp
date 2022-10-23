#include "AggregationsNode/SimpleAggs.h"
#include "ContextNode/GlobalContextNode.h"
#include "ParameterControllerNode/ParameterControllerNode.h"

int main( int argc, char* argv[] )
{
    // TODO: input sanity check!!!
    (void) argc; // to silent warning

    PCTRL().LoadNodeConnectionInfo( argv );
    PCTRL().PrintNodeConnectionInfo();
    auto rpcServer = CTX().GetRPCManager().GetRPCServer();

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

    CTX().GetRPCManager().RunServer();

    return 0;
}
