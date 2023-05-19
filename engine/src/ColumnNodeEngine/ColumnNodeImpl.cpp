#include "ColumnNodeImpl.h"
#include <Loki/Singleton.h>
#include <TCPChannel/SessionNode.h>
#include <Tools/Utility.h>

#include <algorithm>
#include <execution>
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
int ColumnNodeImpl<T>::Count()
{
    return std::count_if( data.begin(), data.end(), []( T& element ) {
        // TODO: add proper filter once null type is introduced
        if ( element )
        {
        }
        return true;
    } );
}

template <typename T>
double ColumnNodeImpl<T>::SumX2()
{
    // probably should be normalized to multiplicity to avoid overflow for big numbers
    return std::transform_reduce( std::execution::par, data.cbegin(), data.cend(), static_cast<double>( 0 ), std::plus{},
                                  [&]( auto val ) { return static_cast<double>( val ) * val / data.size(); } ) *
           data.size();
}

template <typename T>
void ColumnNodeImpl<T>::AddElement( const std::any element )
{
    auto elem = std::any_cast<T>( element );
    data.push_back( std::any_cast<T>( elem ) );
    std::cout << "Element: " << std::to_string( elem ) << " added to node." << std::endl;
}

template <typename T>
int ColumnNodeImpl<T>::SendDataToHub()
{
    auto& pCInstance = Loki::SingletonHolder<SessionNode>::Instance();
    pCInstance.Send( data );
    return data.size();
}