cmake_minimum_required (VERSION 3.18)

project (test-type-erasure)

set (CMAKE_CXX_STANDARD 17)
include (FetchContent)

FetchContent_Declare (
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable (googletest)
FetchContent_GetProperties (googletest)

if (NOT googletest_POPULATED)
    message (FATAL_ERROR "GoogleTest is required to build rss-reader tests. Use FetchContent to populate it.")
endif ()

add_executable (test-type-erasure type_erasure_test.cpp)
target_link_libraries (test-type-erasure GTest::gmock_main)