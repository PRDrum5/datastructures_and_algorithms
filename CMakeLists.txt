cmake_minimum_required(VERSION 3.24.0)

project(DataStructuresAlgorithms VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(apps)

include(CTest)
add_subdirectory(external)
add_subdirectory(test)
