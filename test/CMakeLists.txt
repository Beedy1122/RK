cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(testss)

enable_testing()

add_executable(testion tests.cpp)

target_link_libraries(testion gtest gmock Qt5::Core)

