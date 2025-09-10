cmake_minimum_required(VERSION 3.10)

project(cpp_hello_world)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_hello_world src/main.cpp)

target_link_libraries(cpp_hello_world PRIVATE pthread gtest gtest_main)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_test(NAME cpp_hello_world_tests COMMAND cpp_hello_world)
