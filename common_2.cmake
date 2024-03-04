set_target_properties(${EXEC_NAME} PROPERTIES INCLUDE_DIRECTORIES "${MPI_C_INCLUDE_PATH}")
set_target_properties(${EXEC_NAME} PROPERTIES COMPILE_FLAGS "${MPI_C_COMPILE_FLAGS}")
set_target_properties(${EXEC_NAME} PROPERTIES LINK_FLAGS "${MPI_C_LINK_FLAGS}")
target_link_libraries(${EXEC_NAME} PRIVATE "${MPI_C_LIBRARIES}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake CTestTestfile.cmake Testing)