#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Column
{
public:
    // Add rule of 5 -> Scot Meyers!
    Column();
    ~Column();
    void CreateColumnOnNode();
    void DeleteColumnOnNode();
    void AddElement( T elem );
    void Print();
    void LoadData( const std::string & dataFilePath );
    T Sum();

private:
    std::string colId;
    std::string typeName;
    std::string GenerateUniqueColumnId() const;
};