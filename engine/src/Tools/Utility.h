#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <mutex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using DataLoadRanges = std::vector<std::pair<size_t, size_t>>;

namespace util
{
template <typename T>
void PrintVector( const std::vector<T>& container, const std::string& label )
{
    for ( auto& x : container )
    {
        std::cout << label << ": " << x << '\n';
    }

    std::cout << std::endl;
}
DataLoadRanges CalculateRangesToLoadDataOnNodes( const std::string& dataFilePath, int nOfNodes );

template <typename T>
void LoadCsvToDataColumn( const std::string& dataFilePath, const size_t begin, const size_t end, std::vector<T>& destination );

inline std::vector<std::string> SplitStringToVector( std::string stringToSplit )
{
    std::stringstream ss( stringToSplit );
    std::istream_iterator<std::string> begin( ss );
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings( begin, end );
    return vstrings;
}
} // namespace util
