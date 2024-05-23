#pragma once
#include "ColumnEngine/IColumn.h"
#include <memory>

template <typename T>
class Column {
public:
    Column();
    ~Column();
    Column(const Column&);                     // Needed by the Boost.Python
    Column& operator=(const Column&) = delete; // not applicable

    Column(Column&& other) = delete;            // not applicable as the interpreter's binding class
    Column& operator=(Column&& other) = delete; // ditto

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
    std::unique_ptr<IColumn> _columnEngine;
};
