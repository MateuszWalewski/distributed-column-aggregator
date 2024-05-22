#pragma once
#include "ColumnNodeEngine/IColumnNode.h"
#include <memory>

template <typename T>
class ColumnNode {
public:
    ColumnNode(const std::string& colName);
    ~ColumnNode();

    ColumnNode() = delete;
    ColumnNode& operator=(const ColumnNode&) = delete;  // not applicable as a binding class
    ColumnNode(ColumnNode&& other) = delete;            // ditto
    ColumnNode& operator=(ColumnNode&& other) = delete; // ditto

    void Print();
    void LoadData(const std::string& dataFilePath, const size_t begin, const size_t end);
    void AddElement(const T element);
    size_t Fetch();
    double Sum();
    double SumX2();
    size_t Count();

private:
    std::unique_ptr<IColumnNode> _columnNodeEngine;
    std::string _name;
};
