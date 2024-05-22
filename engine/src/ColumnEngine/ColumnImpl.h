#pragma once
#include "IColumn.h"
#include <vector>

template <typename T>
class ColumnImpl : public IColumn {
public:
    ColumnImpl();
    void CreateColumnOnNode() override;
    void DeleteColumnOnNode() override;
    void AddElement(const size_t nodeNumber, const std::any element) override;
    std::any GetElement(size_t index);
    void PrintColumnOnNode() override;
    void LoadDataToNode(const std::string& dataFilePath) override;
    double Sum() override;
    double MomentI() override;
    double MomentII() override;
    double Stddev() override;
    size_t Count() override;
    size_t Fetch() override;

private:
    std::string _colId;
    std::string _typeName;
    std::vector<T> _data;
    bool _isDataFetchedFromNodes;
    static size_t _instanceId;

    std::string GenerateUniqueColumnId() const;
};

template <typename T>
size_t ColumnImpl<T>::_instanceId = 0;
