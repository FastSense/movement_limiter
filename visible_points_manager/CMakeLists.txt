cmake_minimum_required(VERSION 2.8.4)
project(visible_points_manager)

include_directories(..)
add_subdirectory(../geometry/base geometry_base)
file(GLOB_RECURSE SOURCES "*.cpp")

add_library(visible_points_manager ${SOURCES})
target_link_libraries(visible_points_manager geometry_base)

