#include "Column.h"

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
    CTX().GetSessionHandler().CallRPCMethod( "CreateColumn" + typeName, colId );
}

template <typename T>
void Column<T>::DeleteColumnOnNode()
{
    CTX().GetSessionHandler().CallRPCMethod( "DeleteColumn" + typeName, colId );
}

template <typename T>
void Column<T>::AddElement( int elem )
{
    CTX().GetSessionHandler().CallRPCMethod( "AddElement" + typeName, elem, colId );
}

template <typename T>
void Column<T>::Print()
{
    CTX().GetSessionHandler().CallRPCMethod( "PrintColumn" + typeName, colId );
}

template <typename T>
void Column<T>::LoadData( const std::string & dataFilePath )
{
    CTX().GetSessionHandler().CallRPCMethod( "LoadCsvData" + typeName, dataFilePath, colId );
}

template <typename T>
T Column<T>::Sum()
{
    auto results = CTX().GetSessionHandler().CallRPCMethod<T>( "Sum" + typeName, colId );
    return std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
    ;
}

template <typename T>
std::string Column<T>::GenerateUniqueColumnId() const
{
    // add proper implementation
    return "col1";
}