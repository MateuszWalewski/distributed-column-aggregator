#pragma once

#include <numeric>
#include <vector>

#include "ContextNode/GlobalContextNode.h"
#include <iostream>

namespace calcs
{
template <typename T>
void CreateColumn( std::string id )
{
    auto & map = CTX().GetColumnStorage().GetColumnStorage<T>();
    map[id] = std::make_shared<ColumnNode<T>>( id );
}

template <typename T>
void DeleteColumn( std::string id )
{
    auto & map = CTX().GetColumnStorage().GetColumnStorage<T>();
    map.erase( id );
}

template <typename T>
void AddElement( T elem, std::string id )
{
    auto & map = CTX().GetColumnStorage().GetColumnStorage<T>();
    map[id]->AddElement( elem );
}

template <typename T>
void PrintColumn( const std::string& id )
{
    auto & map = CTX().GetColumnStorage().GetColumnStorage<T>();
    map[id]->Print();
}

template <typename T>
void LoadCsvData( const std::string& dataPath, const std::string& id )
{
    auto & map = CTX().GetColumnStorage().GetColumnStorage<T>();
    map[id]->LoadData( dataPath );
}

template <typename T>
T Sum( const std::string& id )
{
    auto & map = CTX().GetColumnStorage().GetColumnStorage<T>();
    auto col = map[id];
    return std::accumulate( col->DBegin(), col->DEnd(), static_cast<T>( 0 ) );
}

} // namespace calcs