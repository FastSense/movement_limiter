cmake_minimum_required(VERSION 2.8.4)
project(geometry_base)

file(GLOB_RECURSE SOURCES "*.cpp")

add_library(geometry_base ${SOURCES})
