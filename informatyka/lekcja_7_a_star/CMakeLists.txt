cmake_minimum_required(VERSION 3.29)
project(lekcja_7_a_star)

set(CMAKE_CXX_STANDARD 20)

add_executable(lekcja_7_a_star main.cpp
        Node.h
        NodeField.h
        NodeField.cpp)
