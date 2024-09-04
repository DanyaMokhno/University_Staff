cmake_minimum_required(VERSION 3.28)
project(114 C)

set(CMAKE_C_STANDARD 99)

add_executable(out main.c)
configure_file(CID.csv ${CMAKE_CURRENT_BINARY_DIR}/CID.csv COPYONLY)