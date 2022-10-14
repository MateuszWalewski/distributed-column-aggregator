add_library(
    GlobalContextNode
    STATIC
    GlobalContextNode.h
    GlobalContextNode.cpp)

target_link_libraries(GlobalContextNode PUBLIC ColumnStorageNode NetworkingNode)
