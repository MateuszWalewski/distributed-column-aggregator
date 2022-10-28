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

    ColumnNode( const std::string& colName ) : name( colName )
    {
        // TODO: Introduce external logger
        std::cout << "Column " << name << " of typid: " << std::string( typeid( T ).name() ) << " created on node" << std::endl;
    };
    ~ColumnNode()
    {
        std::cout << "Column " << name << " of typid: " << std::string( typeid( T ).name() ) << " destructed on node"
                  << std::endl;
    }
    void Print();
    void LoadData( const std::string& dataFilePath, const size_t begin, const size_t end );
    void AddElement( const T element );

    T Sum();

private:
    std::vector<T> data;
    std::string name;
};