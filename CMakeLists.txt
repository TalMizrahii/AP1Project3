cmake_minimum_required(VERSION 3.23)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3
        Server/main.cpp
        Server/flowAndData/FileReader.cpp
        Server/flowAndData/FileReader.h
        Server/flowAndData/RelativeVector.h
        Server/flowAndData/RelativeVector.cpp
        Server/Distances/AbstractDistance.cpp
        Server/Distances/AbstractDistance.h
        Server/flowAndData/KnnAlgorithm.cpp
        Server/flowAndData/KnnAlgorithm.h
        Client/main.cpp)
