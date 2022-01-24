#include "Tools/Utility.h"
#include <iostream>
#include <vector>

template <typename T> class Column
{
public:
    Column()
    {
    }
    void AddElement( int element )
    {
        data.push_back( element );
    }
    void Print()
    {
        PrintVector( data, "Column elements:" );
    }

    void LoadData( const std::string & dataFilePath )
    {
        LoadCsvToDataColumn( dataFilePath, data );
    }

    T Sum()
    {
        return calcs::AllocateAndAggregateDist( data );
    }

private:
    std::vector<T> data;
};