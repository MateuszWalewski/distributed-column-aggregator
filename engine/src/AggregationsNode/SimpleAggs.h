#pragma once

#include <numeric>
#include <vector>

#include "ColumnStorage/ColumnStorage.h"
#include "ContextNode/GlobalContextNode.h"
#include <iostream>

namespace calcs
{
template <typename T>
void CreateColumn( std::string id )
{
    STRG().CreateColumn( id );
}

template <typename T>
void DeleteColumn( std::string id )
{
    STRG().DeleteColumn( id );
}

template <typename T>
void AddElement( int elem, std::string id )
{
    auto col = STRG().GetColumn( id );
    col->AddElement( elem );
    std::cout << "Element = " << elem << " added to column " << id << std::endl;
}

template <typename T>
void PrintColumn( const std::string & id )
{
    auto col = STRG().GetColumn( id );
    col->Print();
}

template <typename T>
void LoadCsvData( const std::string & dataPath, const std::string & id )
{
    auto col = STRG().GetColumn( id );
    col->LoadData( dataPath );
}

template <typename T>
T Sum( const std::string & id )
{
    auto col = STRG().GetColumn( id );
    return std::accumulate( col->DBegin(), col->DEnd(), static_cast<T>( 0 ) );
}

} // namespace calcs