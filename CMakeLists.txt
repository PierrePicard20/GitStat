cmake_minimum_required (VERSION 3.8)

project (GitStat)

# Include sub-projects.
add_subdirectory (libgitstat)
add_subdirectory (libgit2)

option(GITSTAT_PACKAGE_TESTS "Build the tests" OFF)
if(GITSTAT_PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(gitstat_tests)
	option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
	add_subdirectory(googletest)
endif()
