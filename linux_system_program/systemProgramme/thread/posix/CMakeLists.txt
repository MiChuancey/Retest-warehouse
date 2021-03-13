cmake_minimum_required(VERSION 3.16)
project(posix C)

set(CMAKE_C_STANDARD 99)

add_executable(posix main.c)

target_link_libraries(posix pthread)