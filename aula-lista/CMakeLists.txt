cmake_minimum_required(VERSION 3.15)
project(aula_lista C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(aula_lista
        Aluno.c
        Aluno.h
        ListaComSentinela.c
        ListaComSentinela.h
        main.c)
