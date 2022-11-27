#pragma once
#include "constants.h"

template <typename T>
struct TypeName
{
    static const char* name;
};

template <typename T>
const char* TypeName<T>::name = "unknown";

template <>
const char* TypeName<int>::name = INT_TYPE_GADGET.c_str();

template <>
const char* TypeName<double>::name = DOUBLE_TYPE_GADGET.c_str();

template <>
const char* TypeName<float>::name = FLOAT_TYPE_GADGET.c_str();
