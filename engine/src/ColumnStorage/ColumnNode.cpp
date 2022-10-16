#include "ColumnNode.h"
#include "Tools/Utility.h"

    template class ColumnNode<double>;
    template class ColumnNode<float>;
    template class ColumnNode<int>;


    template<typename T>
    void ColumnNode<T>::AddElement( int element )
    {
        data.push_back( element );
    }

    template<typename T>
    void ColumnNode<T>::Print()
    {
        PrintVector( data, "ColumnNode elements:" );
    }

    template<typename T>
    void ColumnNode<T>::LoadData( const std::string & dataFilePath )
    {
        LoadCsvToDataColumn( dataFilePath, data );
    }

    template<typename T>
    typename std::vector<T>::iterator ColumnNode<T>::DBegin()
    {
        return data.begin();
    }

    template<typename T>
    typename std::vector<T>::iterator ColumnNode<T>::DEnd()
    {
        return data.end();
    }