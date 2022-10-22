#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>

template <typename T>
class ColumnNode
{
public:
    // Add rule of 5 -> Scott Meyers!
    ColumnNode() = default;

    ColumnNode( const std::string & colName ) : name( colName )
    {
        std::cout << "Column " << name << " of typid: " << std::string( typeid( T ).name() ) << " created on node" << std::endl;
    };
    ~ColumnNode()
    {
        std::cout << "Column " << name << " destructed on node" << std::endl;
    }
    void AddElement( T element );
    void Print();
    void LoadData( const std::string & dataFilePath );

    typename std::vector<T>::iterator DBegin();
    typename std::vector<T>::iterator DEnd();

private:
    std::vector<T> data;
    std::string name;
};