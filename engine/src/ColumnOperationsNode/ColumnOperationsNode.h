#pragma once

#include <vector>

#include <ColumnNodeStorage/ColumnNodeStorage.h>
#include <Loki/Singleton.h>
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
int Fetch( const std::string& id );

template <typename T>
void PrintColumn( const std::string& id );

template <typename T>
void LoadCsvData( size_t begin, size_t end, const std::string& dataPath, const std::string& id );

template <typename T>
int Count( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->Count();
}

template <typename T>
T Sum( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->Sum();
}

template <typename T>
double SumX2( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->SumX2();
}

} // namespace calcs