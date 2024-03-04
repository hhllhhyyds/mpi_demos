cmake_minimum_required(VERSION 3.26)

# modify project and executable name here
project(RandomWalk)
set(EXEC_NAME random_walk)

include(${CMAKE_SOURCE_DIR}/../common_1.cmake)

# modify source files here
add_executable(${EXEC_NAME} main.cpp)

include(${CMAKE_SOURCE_DIR}/../common_2.cmake)