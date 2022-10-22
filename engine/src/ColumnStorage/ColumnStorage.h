#pragma once
#include "ColumnNode/ColumnNode.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <tuple>

using ColStorage = std::tuple<std::unordered_map<std::string, std::shared_ptr<ColumnNode<int>>>,
                              std::unordered_map<std::string, std::shared_ptr<ColumnNode<double>>>,
                              std::unordered_map<std::string, std::shared_ptr<ColumnNode<float>>>>;
class ColumnStorage
{
private:
    ColStorage colStorage;

public:
    ColumnStorage();
    ColStorage GetSuperMap();

    template <typename T>
    inline std::unordered_map<std::string, std::shared_ptr<ColumnNode<T>>> & GetColumnStorage()
    {
        return std::get<std::unordered_map<std::string, std::shared_ptr<ColumnNode<T>>>>( colStorage );
    }
};
