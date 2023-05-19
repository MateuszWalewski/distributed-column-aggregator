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
    ColumnImpl( const ColumnImpl& obj );
    void CreateColumnOnNode() override;
    void DeleteColumnOnNode() override;
    void AddElement( const size_t nodeNumber, const std::any element ) override;
    void PrintColumnOnNode() override;
    void LoadDataToNode( const std::string& dataFilePath ) override;
    std::any Sum() override;
    double MomentI() override;
    double MomentII() override;
    double Stddev() override;
    int Count() override;
    int Fetch() override;

private:
    std::string colId;
    std::string typeName;
    std::vector<T> result;
    std::vector<T> data;
    std::string GenerateUniqueColumnId() const;
    static size_t instanceId;
};

template <typename T>
size_t ColumnImpl<T>::instanceId = 0;