cmake_minimum_required(VERSION 3.21)
project(Project1_Movie_Table C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Project1_Movie_Table
        driver.c
        student_functions.c
        student_functions.h)
