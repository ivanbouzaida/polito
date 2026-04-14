cmake_minimum_required(VERSION 3.20)
project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

add_executable(misura_sorts
    misura_sorts.cpp
    timecounter.cpp
)

add_executable(test_bubblesort
    test_bubblesort.cpp
)

add_executable(test_insertionsort
    test_insertionsort.cpp
)

add_executable(test_selectionsort
    test_selectionsort.cpp
)

add_test(NAME bubblesort COMMAND test_bubblesort)
add_test(NAME insertionsort COMMAND test_insertionsort)
add_test(NAME selectionsort COMMAND test_selectionsort)

enable_testing()