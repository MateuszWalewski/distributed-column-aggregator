#include "ColumnNodeImpl.h"
#include "Tools/Utility.h"
#include <numeric>

template class ColumnNodeImpl<double>;
template class ColumnNodeImpl<float>;
template class ColumnNodeImpl<int>;

template <typename T>
void ColumnNodeImpl<T>::Print()
{
    util::PrintVector( data, "ColumnNodeImpl elements:" );
}

template <typename T>
void ColumnNodeImpl<T>::LoadData( const std::string& dataFilePath, const size_t begin, const size_t end )
{
    util::LoadCsvToDataColumn( dataFilePath, begin, end, data );
}

template <typename T>
std::any ColumnNodeImpl<T>::Sum()
{
    return std::accumulate( data.begin(), data.end(), static_cast<T>( 0 ) );
}

template <typename T>
void ColumnNodeImpl<T>::AddElement( const std::any element )
{
    auto elem = std::any_cast<T>( element );
    data.push_back( std::any_cast<T>( elem ) );
    std::cout << "Element: " << std::to_string( elem ) << " added to node." << std::endl;
}