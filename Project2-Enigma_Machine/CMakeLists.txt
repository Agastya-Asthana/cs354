cmake_minimum_required(VERSION 3.21)
project(Project2_Enigma_Machine C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Project2_Enigma_Machine
        enigma.h
        enigma_driver.c
        enigma_functions.c)
