cmake_minimum_required(VERSION 4.0)
project(lab102)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab102 main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/AuxiliaryFunctions.cpp
        Bibliotecas/AuxiliaryFunctions.hpp
        Bibliotecas/Cuenta.hpp
        Bibliotecas/Nodo.hpp
)
