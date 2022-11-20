cmake_minimum_required(VERSION 3.0.0)

add_library(
    ColumnOperationsNode
    STATIC
    ColumnOperationsNode.h
    ColumnOperationsNode.cpp)


target_link_libraries(ColumnOperationsNode PUBLIC ColumnStorage)