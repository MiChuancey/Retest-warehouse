cmake_minimum_required(VERSION 3.11)
project(paraller C)

set(CMAKE_C_STANDARD 99)

add_executable(paraller main.c)
add_executable(5secCount 5secCount.c)
add_executable(pipeControlcat pipeControlcat.c)
add_executable(pipControlcatStrenthed pipControlcatStrenthed.c)