#pragma once

#include <iostream>
#include <vector>

template <typename T> void PrintVector( std::vector<T> container, const std::string & label )
{
    for ( auto & x : container )
    {
        std::cout << label << ": " << x << std::endl;
    }
}

// make it cleaner
template <typename T> std::vector<std::vector<T>> PartitionDataToSendOnNodes( const std::vector<T> & vec, size_t n )
{
    std::vector<std::vector<T>> outVec;

    size_t length = vec.size() / n;
    size_t remain = vec.size() % n;

    size_t begin = 0;
    size_t end = 0;

    for ( size_t i = 0; i < std::min( n, vec.size() ); ++i )
    {
        end += ( remain > 0 ) ? ( length + !!( remain-- ) ) : length;

        outVec.push_back( std::vector<T>( vec.begin() + begin, vec.begin() + end ) );

        begin = end;
    }

    return outVec;
}