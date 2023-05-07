#pragma once
#include <any>
#include <string>

class IColumn
{
public:
    virtual void CreateColumnOnNode() = 0;
    virtual void DeleteColumnOnNode() = 0;
    virtual void PrintColumnOnNode() = 0;
    virtual void AddElement( const size_t nodeNumber, const std::any element ) = 0;
    virtual void LoadDataToNode( const std::string& dataFilePath ) = 0;
    virtual std::any Sum() = 0;
    virtual std::any MomentI() = 0;
    virtual std::any MomentII() = 0;
    virtual int Count() = 0;

    virtual ~IColumn(){};
};