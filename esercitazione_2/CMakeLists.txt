cmake_minimum_required(VERSION 3.10)

project(esercitazione_2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Warning richiesti
add_compile_options(-Wall -Wshadow -Werror=vla)

# Eseguibili
add_executable(es1 es_1.cpp)
add_executable(es2 es_2.cpp)