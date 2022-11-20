add_library(
    ColumnStorage
    STATIC
    ColumnStorage.h
    ColumnStorage.cpp
    )

target_link_libraries(ColumnStorage PUBLIC ColumnNode)