cmake_minimum_required(VERSION 2.8.4)
project(visible_points_manager)

file(GLOB_RECURSE SOURCES "*.cpp")

add_library(visible_points_manager ${SOURCES})
