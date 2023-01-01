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

        Client/main.cpp Client/ClientValidation.h Client/ClientValidation.cpp Client/UserVectorInput.h
        Client/UserVectorInput.cpp Client/ClientSocket.h Client/ClientSocket.cpp Server/main.cpp Server/flowAndData/FileReader.cpp Server/flowAndData/FileReader.h)
