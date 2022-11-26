set(SOURCE_FILES Factory.cpp)

add_library(Factory STATIC ${SOURCE_FILES})

target_link_libraries(Factory PRIVATE ColumnEngine)
target_include_directories(Factory INTERFACE .)
