#pragma once
#include <iostream>
#include <vector>

#include "IColumn.h"

template <typename T>
class ColumnImpl : public IColumn
{
public:
    // Add rule of 5 -> Scot Meyers!
    ColumnImpl();
    ~ColumnImpl();
    void CreateColumnOnNode() override;
    void DeleteColumnOnNode() override;
    void AddElement( const std::any element ) override;
    void PrintColumnOnNode() override;
    void LoadDataToNode( const std::string& dataFilePath ) override;
    std::any Sum() override;

private:
    std::string colId;
    std::string typeName;
    T resultValue;
    std::vector<T> result;
    std::string GenerateUniqueColumnId() const;
};