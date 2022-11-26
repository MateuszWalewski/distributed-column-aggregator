set(SOURCE_FILES ColumnOperationsNode.cpp)

add_library(ColumnOperationsNode STATIC ${SOURCE_FILES})

target_link_libraries(ColumnOperationsNode PRIVATE ColumnNodeStorage)
target_include_directories(ColumnOperationsNode INTERFACE .)



