cmake_minimum_required (VERSION 3.8)

project(libgitstat)

include_directories(${CMAKE_CURRENT_BINARY_DIR}
					${libgit2_SOURCE_DIR}/include)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRCS
	Library.cpp
	Repo.cpp
	Object.cpp
	)

set (HEADERS
	Library.h
	Repo.h
	Object.h
	)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

add_library(libgitstat STATIC ${SRCS} ${HEADERS})

target_compile_features(libgitstat PRIVATE cxx_std_17)
