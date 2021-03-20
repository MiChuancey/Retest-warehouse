cmake_minimum_required(VERSION 3.16)
project(test C)

set(CMAKE_C_STANDARD 99)

add_executable(test main.c logParamenters.h init.c init.h)