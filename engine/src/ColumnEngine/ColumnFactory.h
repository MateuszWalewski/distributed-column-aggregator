#pragma once
#include "ColumnImpl.h"
#include "IColumn.h"

template <typename T>
class ColumnFactory
{
public:
    ColumnFactory()
    {
    }

    std::shared_ptr<IColumn> CreateColumnEngine()
    {
        return std::make_shared<ColumnImpl<T>>();
    }
};