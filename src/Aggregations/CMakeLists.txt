cmake_minimum_required(VERSION 3.0.0)

add_library(
    ContainerAggregations
    SHARED
    SimpleAggs.h
    SimpleAggs.cpp)

add_library(
    ContainerAggregationsDist
    STATIC
    SimpleAggsDist.h
    SimpleAggsDist.cpp)

target_link_libraries(ContainerAggregationsDist PUBLIC GlobalContext)