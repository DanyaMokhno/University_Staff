cmake_minimum_required(VERSION 3.26)
project(coursework C)

#set(SOURCES )
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/my_build_folder)


add_executable(out main.c)
