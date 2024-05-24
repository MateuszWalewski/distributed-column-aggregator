#pragma once
#include <vector>

#include "IColumnNode.h"

template <typename T>
class ColumnNodeImpl : public IColumnNode {
public:
    ColumnNodeImpl() = default;
    ~ColumnNodeImpl() = default;
    void Print() override;
    void LoadData(const std::string& dataFilePath, const size_t begin, const size_t end) override;
    void AddElement(const std::any element) override;

    double Sum() override;
    double SumX2() override;
    size_t Count() override;
    size_t Fetch() override;

    std::any Max() override;
    std::any Min() override;

private:
    std::vector<T> _data;
};
