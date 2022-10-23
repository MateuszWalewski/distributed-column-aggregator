#include "Column.h"
#include "Context/GlobalContextHub.h"

template class Column<double>;
template class Column<float>;
template class Column<int>;

template <typename T>
Column<T>::Column()
{
    columnEngine = CTX().GetColumnFactory<T>()->CreateColumnEngine();
    columnEngine->CreateColumnOnNode();
}

template <typename T>
Column<T>::~Column()
{
    columnEngine->DeleteColumnOnNode();
}

template <typename T>
void Column<T>::Print()
{
    columnEngine->PrintColumnOnNode();
}

template <typename T>
void Column<T>::AddElement( const T element )
{
    columnEngine->AddElement( std::make_any<T>( element ) );
}

template <typename T>
void Column<T>::LoadData( const std::string& dataFilePath )
{
    columnEngine->LoadDataToNode( dataFilePath );
}

template <typename T>
T Column<T>::Sum()
{
    return std::any_cast<T>( columnEngine->Sum() );
}
