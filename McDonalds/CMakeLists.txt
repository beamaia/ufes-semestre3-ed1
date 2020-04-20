cmake_minimum_required(VERSION 3.15)
project(McDonalds C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(McDonalds
        pedido.c
        pedido.h
        produto.c
        produto.h
        progpedidos.c)
