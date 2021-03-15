cmake_minimum_required(VERSION 3.16)
project(socket C)

set(CMAKE_C_STANDARD 99)

add_executable(socket main.c)
add_executable(updServer updServer.c transferData.h)
add_executable(updClient updClient.c transferData.h)
add_executable(tcpServer tcpServer transferData.h)
add_executable(tcpClient tcpClient.c transferData.h)