set(SOURCE_FILES Column.cpp)

add_library(DataColumn STATIC ${SOURCE_FILES})

target_link_libraries(DataColumn PRIVATE Factory)
