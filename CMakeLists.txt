cmake_minimum_required(VERSION 3.0.0)
project(digit VERSION 0.1.0)

# set(CXX_STANDARD_REQUIRED 14)

include(CTest)
enable_testing()

add_executable(digit digit.cpp)
add_executable(deletenum deletenum.cpp)
add_executable(deletenumber deletenumber.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
