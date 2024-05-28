set(SOURCE_FILES ConfigurationManager.cpp)
add_library(ConfigurationManager STATIC ${SOURCE_FILES})

target_include_directories(ConfigurationManager INTERFACE .)
