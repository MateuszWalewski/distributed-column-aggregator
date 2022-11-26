set(SOURCE_FILES FactoryNode.cpp)

add_library(FactoryNode STATIC ${SOURCE_FILES})

target_link_libraries(FactoryNode PRIVATE ColumnNodeEngine)
target_include_directories(FactoryNode INTERFACE .)
