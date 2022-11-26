add_library(
    ColumnNodeStorage
    STATIC
    ColumnNodeStorage.h
    ColumnNodeStorage.cpp
    )

target_link_libraries(ColumnNodeStorage PUBLIC ColumnNode)