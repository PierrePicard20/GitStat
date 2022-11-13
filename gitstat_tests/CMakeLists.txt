cmake_minimum_required (VERSION 3.8)

project(gitstat_tests)

include_directories(${gtest_SOURCE_DIR}
					${gtest_SOURCE_DIR}/include)
	
set (CMAKE_INCLUDE_CURRENT_DIR ON)

set (SRCS
	 BasicTestCases.cpp
	)
	
set (HEADERS
	)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(gitstat_tests ${SRCS} ${HEADERS})
target_link_libraries(gitstat_tests libgitstat gtest_main)
add_test(NAME gitstat_tests
		 COMMAND $<TARGET_FILE:gitstat_tests>
		 WORKING_DIRECTORY ${PROJECT_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_dependencies(gitstat_tests libgitstat)
