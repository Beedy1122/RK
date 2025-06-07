cmake_minimum_required(VERSION 3.10)
project(RK)

set(CPACK_PACKAGE_NAME "RK")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Beedy1122")
set(CPACK_GENERATOR DEB)
include(CPack)

include_directories(class_lib)

add_subdirectory(third-party/googletest)

find_package(Qt5 REQUIRED COMPONENTS Core)
#add_library(State STATIC main.cpp)
#target_link_libraries(State Qt5::Core)
add_executable(main main.cpp)
target_link_libraries(main Qt5::Core)

add_subdirectory(test)
#target_link_libraries(main Duck)
