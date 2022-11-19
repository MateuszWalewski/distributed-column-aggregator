add_library(
    DataColumn
    STATIC
    Column.h
    Column.cpp
    )

target_link_libraries(DataColumn PUBLIC Factory)
