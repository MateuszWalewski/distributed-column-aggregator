#include "ColumnNode.h"
#include "Tools/Utility.h"
#include <numeric>

template class ColumnNode<double>;
template class ColumnNode<float>;
template class ColumnNode<int>;

template <typename T>
void ColumnNode<T>::Print()
{
    PrintVector( data, "ColumnNode elements:" );
}

template <typename T>
void ColumnNode<T>::LoadData( const std::string& dataFilePath )
{
    LoadCsvToDataColumn( dataFilePath, data );
}

template <typename T>
T ColumnNode<T>::Sum()
{
    return std::accumulate( data.begin(), data.end(), static_cast<T>( 0 ) );
}

template <typename T>
void ColumnNode<T>::AddElement( const T element )
{
    data.push_back( element );
}