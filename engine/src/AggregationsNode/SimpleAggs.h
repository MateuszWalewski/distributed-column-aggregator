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
    CTX().GetColumnStorage().CreateColumn( id );
}

template <typename T>
void DeleteColumn( std::string id )
{
    CTX().GetColumnStorage().DeleteColumn( id );
}

template <typename T>
void AddElement( int elem, std::string id )
{
    auto col = CTX().GetColumnStorage().GetColumn( id );
    col->AddElement( elem );
    std::cout << "Element = " << elem << " added to column " << id << std::endl;
}

template <typename T>
void PrintColumn( const std::string& id )
{
    auto col = CTX().GetColumnStorage().GetColumn( id );
    col->Print();
}

template <typename T>
void LoadCsvData( const std::string& dataPath, const std::string& id )
{
    auto col = CTX().GetColumnStorage().GetColumn( id );
    col->LoadData( dataPath );
}

template <typename T>
T Sum( const std::string& id )
{
    auto col = CTX().GetColumnStorage().GetColumn( id );
    return std::accumulate( col->DBegin(), col->DEnd(), static_cast<T>( 0 ) );
}

} // namespace calcs