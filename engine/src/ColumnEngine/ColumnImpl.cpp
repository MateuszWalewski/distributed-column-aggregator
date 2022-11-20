#include "ColumnImpl.h"
#include "Loki/Singleton.h"
#include "Networking/RPCManager.h"
#include "ParameterController/ParameterControllerHub.h"
#include "Tools/Utility.h"

#include <numeric>

template class ColumnImpl<double>;
template class ColumnImpl<float>;
template class ColumnImpl<int>;

template <typename T>
ColumnImpl<T>::ColumnImpl()
{
    typeName = std::string( typeid( T ).name() );
    colId = GenerateUniqueColumnId();
}

template <typename T>
ColumnImpl<T>::~ColumnImpl()
{
}

template <typename T>
void ColumnImpl<T>::CreateColumnOnNode()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.CallRPCMethod( "CreateColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::DeleteColumnOnNode()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.CallRPCMethod( "DeleteColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::PrintColumnOnNode()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.CallRPCMethod( "PrintColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::AddElement( const size_t nodeNumber, const std::any element )
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto elem = std::any_cast<T>( element );
    RPCInstance.CallRPCMethodOnTheGivenNode( "AddElement" + typeName, nodeNumber, colId, elem );
}

template <typename T>
void ColumnImpl<T>::LoadDataToNode( const std::string& dataFilePath )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto ranges = util::CalculateRangesToLoadDataOnNodes( dataFilePath, (int) pCInstance.GetNumberOfNodes() );
    RPCInstance.CallRPCMethod( "LoadCsvData" + typeName, ranges, dataFilePath, colId );
}

template <typename T>
std::any ColumnImpl<T>::Sum()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = RPCInstance.CallRPCMethod<T>( "Sum" + typeName, colId );
    this->resultValue = std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
    return this->resultValue;
}

template <typename T>
std::string ColumnImpl<T>::GenerateUniqueColumnId() const
{
    // TODO: add proper implementation generating unique ID
    return "col1";
}
