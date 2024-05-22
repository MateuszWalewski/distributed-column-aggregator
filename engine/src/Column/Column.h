#pragma once
#include "ColumnEngine/IColumn.h"

template <typename T>
class Column {
public:
    Column();
    ~Column();
    void AddElement(const size_t nodeNumber, const T element);
    T GetElement(size_t index);
    void Print();
    void LoadData(const std::string& dataFilePath);

    size_t Count();
    size_t Fetch();
    double Sum();
    double MomentI();
    double MomentII();
    double Stddev();

private:
    IColumn* _columnEngine;
};
