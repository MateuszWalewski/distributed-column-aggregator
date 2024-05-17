#include "Utility.h"
#include <algorithm>

namespace util
{
template void LoadCsvToDataColumn<int>( const std::string& dataFilePath, const size_t begin, const size_t end,
                                        std::vector<int>& destination );
template void LoadCsvToDataColumn<float>( const std::string& dataFilePath, const size_t begin, const size_t end,
                                          std::vector<float>& destination );
template void LoadCsvToDataColumn<double>( const std::string& dataFilePath, const size_t begin, const size_t end,
                                           std::vector<double>& destination );

const std::string DATA_FILE_PATH = std::string( DATA_PATH ) + "/data/";

DataLoadRanges CalculateRangesToLoadDataOnNodes( const std::string& dataFilePath, int nOfNodes )
{
    DataLoadRanges ranges;

    std::ifstream inFile( DATA_FILE_PATH + dataFilePath );

    int fileSize = std::count( std::istreambuf_iterator<char>( inFile ), std::istreambuf_iterator<char>(), '\n' ) + 1;

    size_t length = fileSize / nOfNodes;
    size_t remain = fileSize % nOfNodes;

    size_t begin = 0;
    size_t end = 0;

    for ( int i = 0; i < std::min( nOfNodes, fileSize ); ++i )
    {
        end += ( remain > 0 ) ? ( length + !!( remain-- ) ) : length;

        ranges.emplace_back( std::make_pair( begin, end ) );
        begin = end;
    }

    return ranges;
}

template <typename T>
void LoadCsvToDataColumn( const std::string& dataFilePath, const size_t begin, const size_t end, std::vector<T>& destination )
{
    T tempValue;
    std::mutex m;
    m.lock();
    std::ifstream myfile( DATA_FILE_PATH + dataFilePath );

    try
    {
        if ( !myfile.is_open() )
        {
            throw std::exception(); // Throw an exception when a problem arise
        }
    }
    catch ( ... )
    {
        std::cout << "Problem with file" << std::endl;
        ;
    }

    size_t count = 0;
    while ( myfile >> tempValue )
    {
        ++count;
        if ( count > end )
        {
            break;
        }
        if ( count <= begin )
        {
            continue;
        }
        destination.push_back( tempValue );
    }

    m.unlock();
}

} // namespace util
