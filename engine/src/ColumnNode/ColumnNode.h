#pragma once
#include "ColumnNodeEngine/IColumnNode.h"
#include <iostream>
#include <typeinfo>
#include <vector>

template <typename T>
class ColumnNode
{
public:
    // Add rule of 5 -> Scott Meyers!
    ColumnNode() = default;
    ColumnNode( const std::string& colName );
    ~ColumnNode();
    void Print();
    void LoadData( const std::string& dataFilePath, const size_t begin, const size_t end );
    void AddElement( const T element );

    T Sum();

private:
    IColumnNode* columnNodeEngine;
    std::string name;
};