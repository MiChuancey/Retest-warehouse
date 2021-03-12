cmake_minimum_required(VERSION 3.11)
project(process C)

set(CMAKE_C_STANDARD 99)

add_executable(process main.c)
add_executable(primer primer.c)
add_executable(few few.c)
add_executable(daemon daemon.c)
add_executable(syslog syslog.c)
