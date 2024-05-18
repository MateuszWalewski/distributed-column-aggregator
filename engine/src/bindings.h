#include <ColumnOperationsNode/ColumnOperationsNode.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>

void performBindings()
{
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto rpcServer = rpcInstance.GetRpcServer();

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
}