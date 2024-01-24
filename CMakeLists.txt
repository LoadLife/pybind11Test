cmake_minimum_required(VERSION 3.15)
project(bindtest VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(pybind11)
add_subdirectory(src)
