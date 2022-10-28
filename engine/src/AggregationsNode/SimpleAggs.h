#pragma once

#include <vector>

#include "ContextNode/GlobalContextNode.h"
#include <iostream>

namespace calcs
{
template <typename T>
void CreateColumn( const std::string& id );

template <typename T>
void DeleteColumn( const std::string& id );

template <typename T>
void AddElement( const std::string& id, const T elem );

template <typename T>
void PrintColumn( const std::string& id );

template <typename T>
void LoadCsvData( size_t begin, size_t end, const std::string& dataPath, const std::string& id );

template <typename T>
T Sum( const std::string& id )
{
    auto& map = CTX().GetColumnStorage().GetColumnStorage<T>();
    return map[id]->Sum();
}

} // namespace calcs