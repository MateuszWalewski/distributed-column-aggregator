add_library(
    FactoryNode
    STATIC
    FactoryNode.h
    FactoryNode.cpp)

target_link_libraries(FactoryNode PUBLIC ColumnNodeEngine)
