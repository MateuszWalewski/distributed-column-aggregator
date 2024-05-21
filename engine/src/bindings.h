#include <ColumnOperationsNode/ColumnOperationsNode.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>

void performBindings()
{
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto rpcServer = rpcInstance.GetRpcServer();

    rpcServer->bind( "IntTypeColumn_CreateColumn", &calcs::CreateColumn<int> );
    rpcServer->bind( "IntTypeColumn_DeleteColumn", &calcs::DeleteColumn<int> );
    rpcServer->bind( "IntTypeColumn_AddElement", &calcs::AddElement<int> );
    rpcServer->bind( "IntTypeColumn_Fetch", &calcs::Fetch<int> );
    rpcServer->bind( "IntTypeColumn_PrintColumn", &calcs::PrintColumn<int> );
    rpcServer->bind( "IntTypeColumn_LoadCsvData", &calcs::LoadCsvData<int> );
    rpcServer->bind( "IntTypeColumn_Sum", &calcs::Sum<int> );
    rpcServer->bind( "IntTypeColumn_SumX2", &calcs::SumX2<int> );
    rpcServer->bind( "IntTypeColumn_Count", &calcs::Count<int> );

    rpcServer->bind( "DoubleTypeColumn_CreateColumn", &calcs::CreateColumn<double> );
    rpcServer->bind( "DoubleTypeColumn_DeleteColumn", &calcs::DeleteColumn<double> );
    rpcServer->bind( "DoubleTypeColumn_AddElement", &calcs::AddElement<double> );
    rpcServer->bind( "DoubleTypeColumn_Fetch", &calcs::Fetch<double> );
    rpcServer->bind( "DoubleTypeColumn_PrintColumn", &calcs::PrintColumn<double> );
    rpcServer->bind( "DoubleTypeColumn_LoadCsvData", &calcs::LoadCsvData<double> );
    rpcServer->bind( "DoubleTypeColumn_Sum", &calcs::Sum<double> );
    rpcServer->bind( "DoubleTypeColumn_SumX2", &calcs::SumX2<double> );
    rpcServer->bind( "DoubleTypeColumn_Count", &calcs::Count<double> );

    rpcServer->bind( "FloatTypeColumn_CreateColumn", &calcs::CreateColumn<float> );
    rpcServer->bind( "FloatTypeColumn_DeleteColumn", &calcs::DeleteColumn<float> );
    rpcServer->bind( "FloatTypeColumn_AddElement", &calcs::AddElement<float> );
    rpcServer->bind( "FloatTypeColumn_Fetch", &calcs::Fetch<float> );
    rpcServer->bind( "FloatTypeColumn_PrintColumn", &calcs::PrintColumn<float> );
    rpcServer->bind( "FloatTypeColumn_LoadCsvData", &calcs::LoadCsvData<float> );
    rpcServer->bind( "FloatTypeColumn_Sum", &calcs::Sum<float> );
    rpcServer->bind( "FloatTypeColumn_SumX2", &calcs::SumX2<float> );
    rpcServer->bind( "FloatTypeColumn_Count", &calcs::Count<float> );
}
