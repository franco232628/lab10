cmake_minimum_required(VERSION 3.31)
project(ALGORITMOS_CLAVES)

set(CMAKE_CXX_STANDARD 20)

add_executable(ALGORITMOS_CLAVES main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h
        Bibliotecas/Nodo.h
        Bibliotecas/DatosRandom.h)
