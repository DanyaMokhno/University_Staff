cmake_minimum_required(VERSION 3.27)
project(Laboratory_Work_6 C)

set(CMAKE_C_STANDARD 99)

add_executable(out main.c)

# Копируем input.txt в каталог сборки
#configure_file(input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)
