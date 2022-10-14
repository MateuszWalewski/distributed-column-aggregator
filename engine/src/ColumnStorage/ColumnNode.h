#include "Tools/Utility.h"
#include <iostream>
#include <vector>

template <typename T>
class ColumnNode
{
public:
    // Add rule of 5 -> Scott Meyers!
    ColumnNode() = default;

    ColumnNode( const std::string & colName ) : name( colName )
    {
        std::cout << "Column " << name << " created on node" << std::endl;
    };
    ~ColumnNode()
    {
        std::cout << "Column " << name << " destructed on node" << std::endl;
    }
    void AddElement( int element );
    void Print();
    void LoadData( const std::string & dataFilePath );

    typename std::vector<T>::iterator DBegin();
    typename std::vector<T>::iterator DEnd();

private:
    std::vector<T> data;
    std::string name;
};