#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
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

template <typename T> void LoadCsvToDataColumn( const std::string & dataFilePath, std::vector<T> & destination )
{
    T tempValue;
    std::ifstream myfile( dataFilePath );
    try
    {
        if ( !myfile.is_open() )
        {
            throw std::exception(); // Throw an exception when a problem arise
        }
        else
        {
            std::cout << "File opened!!" << std::endl;
        }
    }
    catch ( ... )
    {
        std::cout << "PRoblem with file" << std::endl;
    }

    while ( myfile >> tempValue )
    {
        destination.push_back( tempValue );
    }
}

// think about this 'inline' here
inline std::vector<std::string> SplitStringToVector( std::string stringToSplit )
{
    std::stringstream ss( stringToSplit );
    std::istream_iterator<std::string> begin( ss );
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings( begin, end );
    return vstrings;
}