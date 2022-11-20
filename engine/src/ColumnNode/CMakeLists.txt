add_library(
    ColumnNode
    STATIC
    ColumnNode.h
    ColumnNode.cpp
    )

target_link_libraries(ColumnNode PUBLIC Tools)