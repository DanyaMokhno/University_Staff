cmake_minimum_required(VERSION 3.27)
project(Laboratory_work_7 C)

set(CMAKE_C_STANDARD 99)

add_executable(out main.c)

configure_file(Data.csv ${CMAKE_CURRENT_BINARY_DIR}/Data.csv COPYONLY)
configure_file(Data2.csv ${CMAKE_CURRENT_BINARY_DIR}/Data2.csv COPYONLY)