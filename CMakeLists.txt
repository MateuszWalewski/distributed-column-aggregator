cmake_minimum_required(VERSION 3.0.0)
project(distDB)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wfatal-errors -Wredundant-move -Wpessimizing-move -Wmaybe-uninitialized -Wuninitialized)
endif()

SET(CMAKE_CXX_STANDARD 17)

include_directories(".")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
