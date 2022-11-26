set(SOURCE_FILES ColumnNode.cpp)

add_library(ColumnNode STATIC ${SOURCE_FILES})

target_link_libraries(ColumnNode PRIVATE FactoryNode)
target_include_directories(ColumnNode INTERFACE .)