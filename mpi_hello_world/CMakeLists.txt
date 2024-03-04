cmake_minimum_required(VERSION 3.0)

# modify project and executable name here
project(HelloWorld)
set(EXEC_NAME helloworld)

include(${CMAKE_SOURCE_DIR}/../common_1.cmake)

# modify source files here
add_executable(${EXEC_NAME} hello_world.cpp)

include(${CMAKE_SOURCE_DIR}/../common_2.cmake)