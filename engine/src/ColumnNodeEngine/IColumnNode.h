#pragma once
#include <any>
#include <string>

class IColumnNode
{
public:
    virtual void Print() = 0;
    virtual void LoadData( const std::string& dataFilePath, const size_t begin, const size_t end ) = 0;
    virtual void AddElement( const std::any element ) = 0;
    virtual std::any Sum() = 0;
    virtual double SumX2() = 0;
    virtual int Count() = 0;
    virtual int SendDataToHub() = 0;

    virtual ~IColumnNode(){};
};
