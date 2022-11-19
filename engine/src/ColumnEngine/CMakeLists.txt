add_library(
    ColumnEngine
    STATIC
    IColumn.h
    ColumnImpl.h
    ColumnImpl.cpp
    )

target_link_libraries(ColumnEngine PUBLIC GlobalContext)



