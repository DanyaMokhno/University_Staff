cmake_minimum_required(VERSION 3.27)
project(binary_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(out main.cpp)

configure_file(random_word.txt ${CMAKE_CURRENT_BINARY_DIR}/random_word.txt COPYONLY)
configure_file(test.txt ${CMAKE_CURRENT_BINARY_DIR}/test.txt COPYONLY)