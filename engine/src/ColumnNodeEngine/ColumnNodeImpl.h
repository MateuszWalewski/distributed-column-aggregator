#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>

#include "IColumnNode.h"

template <typename T>
class ColumnNodeImpl : public IColumnNode
{
public:
    // Add rule of 5 -> Scott Meyers!
    ColumnNodeImpl() = default;
    ~ColumnNodeImpl() = default;
    void Print() override;
    void LoadData( const std::string& dataFilePath, const size_t begin, const size_t end ) override;
    void AddElement( const std::any element ) override;

    std::any Sum() override;
    int Count() override;

private:
    std::vector<T> data;
    std::string name;
};