#pragma once
#include "ColumnNode/ColumnNode.h"
#include <memory>
#include <string>
#include <unordered_map>

using ColStorageInt = std::unordered_map<std::string, std::shared_ptr<ColumnNode<int>>>;
class ColumnStorage
{
private:
    ColStorageInt Storage;

public:
    ColumnStorage() = default;
    void CreateColumn( const std::string & id );
    void DeleteColumn( const std::string & id );
    std::shared_ptr<ColumnNode<int>> GetColumn( const std::string & id );
    int GetSize() const;
};