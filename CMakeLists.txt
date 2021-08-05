cmake_minimum_required(VERSION 3.0.0)
project(distDB)
SET(CMAKE_CXX_STANDARD 17)

include_directories(".")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
