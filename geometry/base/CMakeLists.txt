cmake_minimum_required(VERSION 2.8.4)
project(geometry_base)

include_directories(..)
file(GLOB POINT_SOURCES "point/*.cpp")
file(GLOB VECTOR_SOURCES "vector/*.cpp")
file(GLOB LINE_SOURCES "line/*.cpp")

add_library(geometry_base ${POINT_SOURCES} ${LINE_SOURCES} ${VECTOR_SOURCES})

add_custom_target(tests COMMAND GTEST_COLOR=yes ${CMAKE_CTEST_COMMAND} --verbose)

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

file(GLOB TEST_FILES "tests/*.cpp")
add_executable(geometry_base_tests EXCLUDE_FROM_ALL ${TEST_FILES})
target_link_libraries(geometry_base_tests gtest pthread geometry_base)
add_dependencies(tests geometry_base_tests)
add_test(geometry_base_tests ./geometry_base_tests)