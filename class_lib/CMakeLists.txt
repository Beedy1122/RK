cmake_minimum_required(VERSION 3.10)
project(Duck)

add_library(Duck INTERFACE)

target_include_directories(Duck INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
