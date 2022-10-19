#include "ColumnStorage.h"
#include <iostream>

void ColumnStorage::CreateColumn( const std::string & id )
{
    Storage[id] = std::make_shared<ColumnNode<int>>( id );
}

void ColumnStorage::DeleteColumn( const std::string & id )
{
    Storage.erase( id );
}

std::shared_ptr<ColumnNode<int>> ColumnStorage::GetColumn( const std::string & id )
{
    return Storage[id];
}

int ColumnStorage::GetSize() const
{
    return Storage.size();
}
