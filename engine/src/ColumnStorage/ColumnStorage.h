#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "ColumnNode.h"


#define STRG() ColumnStorage::Instance()
using ColStorageInt = std::unordered_map<std::string, std::shared_ptr<ColumnNode<int>>>;
class ColumnStorage
{
private:
    ColumnStorage();
    ColStorageInt Storage;

public:
    static ColumnStorage & Instance();
    void CreateColumn(const std::string& id );
    void DeleteColumn(const std::string& id );
    std::shared_ptr<ColumnNode<int>> GetColumn(const std::string& id );
    int GetSize() const;
};