cmake_minimum_required(VERSION 3.0)

# modify project and executable name here
project(SendRecv)

include(${CMAKE_SOURCE_DIR}/../common_1.cmake)

add_executable(send_recv_1 send_recv_1.cpp basic.cpp)
set_target_properties(send_recv_1 PROPERTIES INCLUDE_DIRECTORIES "${MPI_C_INCLUDE_PATH}")
set_target_properties(send_recv_1 PROPERTIES COMPILE_FLAGS "${MPI_C_COMPILE_FLAGS}")
set_target_properties(send_recv_1 PROPERTIES LINK_FLAGS "${MPI_C_LINK_FLAGS}")
target_link_libraries(send_recv_1 PRIVATE "${MPI_C_LIBRARIES}")

add_executable(send_recv_2 send_recv_2.cpp basic.cpp)
set_target_properties(send_recv_2 PROPERTIES INCLUDE_DIRECTORIES "${MPI_C_INCLUDE_PATH}")
set_target_properties(send_recv_2 PROPERTIES COMPILE_FLAGS "${MPI_C_COMPILE_FLAGS}")
set_target_properties(send_recv_2 PROPERTIES LINK_FLAGS "${MPI_C_LINK_FLAGS}")
target_link_libraries(send_recv_2 PRIVATE "${MPI_C_LIBRARIES}")

add_executable(send_recv_3 send_recv_3.cpp basic.cpp)
set_target_properties(send_recv_3 PROPERTIES INCLUDE_DIRECTORIES "${MPI_C_INCLUDE_PATH}")
set_target_properties(send_recv_3 PROPERTIES COMPILE_FLAGS "${MPI_C_COMPILE_FLAGS}")
set_target_properties(send_recv_3 PROPERTIES LINK_FLAGS "${MPI_C_LINK_FLAGS}")
target_link_libraries(send_recv_3 PRIVATE "${MPI_C_LIBRARIES}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake CTestTestfile.cmake Testing)