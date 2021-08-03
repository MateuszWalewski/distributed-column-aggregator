cmake_minimum_required(VERSION 3.0.0)

add_library(
    ContainerAggregations
    SHARED
    SimpleAggs.h
    SimpleAggs.cpp)

add_library(
    ContainerAggregationsDist
    SHARED
    SimpleAggsDist.h
    SimpleAggsDist.cpp)

