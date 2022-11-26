set(SOURCE_FILES Utility.cpp)
add_library(Tools STATIC ${SOURCE_FILES})

target_include_directories(Tools INTERFACE .)

target_compile_definitions(Tools PRIVATE DATA_PATH="${CMAKE_SOURCE_DIR}")

add_subdirectory(test)