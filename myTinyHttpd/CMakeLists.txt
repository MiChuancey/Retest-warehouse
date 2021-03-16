cmake_minimum_required(VERSION 3.16)
project(myTinyHttpd C)

set(CMAKE_C_STANDARD 99)

add_executable(myTinyHttpd main.c serverParameter.h)

add_link_options(-W -Wall)

target_link_libraries(myTinyHttpd pthread)