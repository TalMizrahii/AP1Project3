cmake_minimum_required(VERSION 3.23)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex3
        Client/main.cpp Client/ClientValidation.h Client/ClientValidation.cpp Client/UserVectorInput.h
        Client/UserVectorInput.cpp Client/ClientSocket.h Client/ClientSocket.cpp Server/main.cpp)
