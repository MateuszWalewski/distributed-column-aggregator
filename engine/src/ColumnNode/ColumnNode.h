#pragma once
#include "ColumnNodeEngine/IColumnNode.h"

template <typename T>
class ColumnNode {
public:
    ColumnNode() = default;
    ColumnNode(const std::string& colName);
    ~ColumnNode();
    void Print();
    void LoadData(const std::string& dataFilePath, const size_t begin, const size_t end);
    void AddElement(const T element);
    size_t Fetch();
    double Sum();
    double SumX2();
    size_t Count();

private:
    IColumnNode* _columnNodeEngine;
    std::string _name;
};
