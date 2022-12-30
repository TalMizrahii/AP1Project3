cmake_minimum_required(VERSION 3.23)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3
        Server/main.cpp
        Server/flowAndData/FileReader.cpp
        Server/flowAndData/FileReader.h
        Client/main.cpp)
