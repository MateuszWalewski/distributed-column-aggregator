#include "ColumnImpl.h"
#include "Aggregations/SimpleAggsDist.h"
#include "Context/GlobalContextHub.h"

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
    CTX().GetRPCManager().CallRPCMethod( "CreateColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::DeleteColumnOnNode()
{
    CTX().GetRPCManager().CallRPCMethod( "DeleteColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::PrintColumnOnNode()
{
    CTX().GetRPCManager().CallRPCMethod( "PrintColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::LoadDataToNode( const std::string& dataFilePath )
{
    CTX().GetRPCManager().CallRPCMethod( "LoadCsvData" + typeName, dataFilePath, colId );
}

template <typename T>
std::any ColumnImpl<T>::Sum()
{
    auto results = CTX().GetRPCManager().CallRPCMethod<T>( "Sum" + typeName, colId );
    this->resultValue = std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
    return this->resultValue;
}

template <typename T>
std::string ColumnImpl<T>::GenerateUniqueColumnId() const
{
    // add proper implementation
    return "col1";
}
