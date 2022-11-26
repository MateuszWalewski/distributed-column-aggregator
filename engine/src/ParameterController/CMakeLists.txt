set(SOURCE_FILES ParameterControllerHub.cpp)
add_library(ParameterController STATIC ${SOURCE_FILES})

target_include_directories(ParameterController INTERFACE .)

    
    
    