set(SOURCE_FILES ColumnImpl.cpp)

add_library(ColumnEngine STATIC ${SOURCE_FILES})

target_link_libraries(ColumnEngine PRIVATE TCPChannel Tools TBB::tbb)
target_include_directories(ColumnEngine INTERFACE .)



