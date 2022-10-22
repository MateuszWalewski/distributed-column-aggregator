#include "Column.h"
#include "Aggregations/SimpleAggsDist.h"
#include "Context/GlobalContextHub.h"

template class Column<double>;
template class Column<float>;
template class Column<int>;

template <typename T>
Column<T>::Column()
{
    typeName = std::string( typeid( T ).name() );
    colId = GenerateUniqueColumnId();
    CreateColumnOnNode();
}

template <typename T>
Column<T>::~Column()
{
    DeleteColumnOnNode();
}

template <typename T>
void Column<T>::CreateColumnOnNode()
{
    CTX().GetRPCManager().CallRPCMethod( "CreateColumn" + typeName, colId );
}

template <typename T>
void Column<T>::DeleteColumnOnNode()
{
    CTX().GetRPCManager().CallRPCMethod( "DeleteColumn" + typeName, colId );
}

template <typename T>
void Column<T>::AddElement( T elem )
{
    CTX().GetRPCManager().CallRPCMethod( "AddElement" + typeName, elem, colId );
}

template <typename T>
void Column<T>::Print()
{
    CTX().GetRPCManager().CallRPCMethod( "PrintColumn" + typeName, colId );
}

template <typename T>
void Column<T>::LoadData( const std::string & dataFilePath )
{
    CTX().GetRPCManager().CallRPCMethod( "LoadCsvData" + typeName, dataFilePath, colId );
}

template <typename T>
T Column<T>::Sum()
{
    auto results = CTX().GetRPCManager().CallRPCMethod<T>( "Sum" + typeName, colId );
    return std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
    ;
}

template <typename T>
std::string Column<T>::GenerateUniqueColumnId() const
{
    // TODO: add proper implementation
    return "col1";
}
