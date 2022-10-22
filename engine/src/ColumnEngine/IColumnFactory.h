
#pragma once
#include "IColumn.h"
#include <memory>

class IColumnFactory
{
public:
    virtual std::shared_ptr<IColumn> CreateColumnEngine() = 0;
};