cmake_minimum_required(VERSION 3.21)
project(Project_6_Cache_Memory C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Cache cache_template.c)
