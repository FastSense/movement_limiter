cmake_minimum_required(VERSION 2.8.4)
project(movement_limiter)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(visible_points_manager visible_points_manager)
add_executable(movement_limiter launcher.cpp)
target_link_libraries(movement_limiter visible_points_manager)
