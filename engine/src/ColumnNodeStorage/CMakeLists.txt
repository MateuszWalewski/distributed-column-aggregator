add_library(ColumnNodeStorage INTERFACE)

target_link_libraries(ColumnNodeStorage INTERFACE ColumnNode)
target_include_directories(ColumnNodeStorage INTERFACE .)

