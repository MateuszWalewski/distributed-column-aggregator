#pragma once
#include "ColumnEngine/IColumn.h"
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class Column
{
public:
    // Add rule of 5 -> Scot Meyers!
    Column();
    ~Column();
    void CreateColumnOnNode( const std::string& id );
    void DeleteColumnOnNode();
    void Print();
    void LoadData( const std::string& dataFilePath );
    T Sum();

private:
    std::shared_ptr<IColumn> columnEngine;
};