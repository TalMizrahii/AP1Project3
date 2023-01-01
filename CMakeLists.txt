cmake_minimum_required(VERSION 3.23)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3
        Server/flowAndData/DataProcessing.cpp
        Server/flowAndData/DataProcessing.h
        Server/flowAndData/KnnAlgorithm.cpp
        Server/flowAndData/KnnAlgorithm.h
        Server/flowAndData/RelativeVector.h
        Server/flowAndData/RelativeVector.cpp
        Server/flowAndData/ServerSocket.cpp
        Server/flowAndData/ServerSocket.h
        Server/flowAndData/ServerValidations.cpp
        Server/flowAndData/ServerValidations.h
        Server/Distances/AbstractDistance.cpp
        Server/Distances/AbstractDistance.h
        Server/Distances/Canberra.cpp
        Server/Distances/Canberra.h
        Server/Distances/Chebyshev.cpp
        Server/Distances/Chebyshev.h
        Server/Distances/Euclidean.cpp
        Server/Distances/Euclidean.h
        Server/Distances/Minkowski.cpp
        Server/Distances/Minkowski.h
        Server/Distances/Taxicab.cpp
        Server/Distances/Taxicab.h
        Server/flowAndData/FileReader.cpp
        Server/flowAndData/FileReader.h
        Server/main.cpp

        Client/main.cpp
        Client/ClientValidation.cpp
        Client/ClientValidation.h
        Client/ClientSocket.cpp
        Client/ClientSocket.h
        Client/UserVectorInput.cpp
        Client/UserVectorInput.h
        )
