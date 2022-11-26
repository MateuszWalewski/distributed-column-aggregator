set(SOURCE_FILES ParameterControllerNode.cpp)
add_library(ParameterControllerNode STATIC ${SOURCE_FILES})

target_include_directories(ParameterControllerNode INTERFACE .)