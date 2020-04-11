cmake_minimum_required(VERSION 3.15)
project(aula2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(aula2
        matriz.c
        matriz.h
        progmat.c)
