cmake_minimum_required(VERSION 3.21)
project(Project_4_Memory_Allocator C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Project_4_Memory_Allocator
        driver_alloc_1_24.c
        mem_functions.c
        mem_init.c)
