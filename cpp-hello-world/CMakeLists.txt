cmake_minimum_required(VERSION 3.10)

project(cpp_hello_world)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_hello_world src/main.cpp)

target_link_libraries(cpp_hello_world pthread)
