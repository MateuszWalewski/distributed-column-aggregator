#pragma once
#include <vector>

#include "IColumnNode.h"

template <typename T>
class ColumnNodeImpl : public IColumnNode
{
public:
    ColumnNodeImpl() = default;
    ~ColumnNodeImpl() = default;
    void Print() override;
    void LoadData( const std::string& dataFilePath, const size_t begin, const size_t end ) override;
    void AddElement( const std::any element ) override;

    std::any Sum() override;
    double SumX2() override;
    int Count() override;
    int SendDataToHub() override;

private:
    std::vector<T> _data;
};
