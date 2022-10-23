#pragma once
#include "ColumnNode/ColumnNode.h"
#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>

using ColStorage = std::tuple<std::unordered_map<std::string, std::shared_ptr<ColumnNode<int>>>,
                              std::unordered_map<std::string, std::shared_ptr<ColumnNode<double>>>,
                              std::unordered_map<std::string, std::shared_ptr<ColumnNode<float>>>>;

template <typename T>
using TypedStorage = std::unordered_map<std::string, std::shared_ptr<ColumnNode<T>>>;

class ColumnStorage
{
private:
    ColStorage colStorage;

public:
    ColumnStorage();
    ColStorage GetSuperMap();

    template <typename T>
    inline TypedStorage<T>& GetColumnStorage()
    {
        return std::get<TypedStorage<T>>( colStorage );
    }
};
