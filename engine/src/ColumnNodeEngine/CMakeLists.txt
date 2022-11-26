add_library(
    ColumnNodeEngine
    STATIC
    IColumnNode.h
    ColumnNodeImpl.h
    ColumnNodeImpl.cpp
    )

target_link_libraries(ColumnNodeEngine PUBLIC Tools)



