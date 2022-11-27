#pragma once
#include "constants.h"

template <typename T>
struct TypeNameCol { static const char *name; };

template <typename T>
const char *TypeNameCol<T>::name = "unknown";

template <>
const char *TypeNameCol<int>::name = INT_TYPE.c_str();

template <>
const char *TypeNameCol<double>::name = DOUBLE_TYPE.c_str();

template <>
const char *TypeNameCol<float>::name = FLOAT_TYPE.c_str();
