cmake_minimum_required(VERSION 3.27)
project(Feistel_Cipher)

set(CMAKE_CXX_STANDARD 17)

add_executable(Feistel_Cipher main.cpp
        lib/feistel.h
        lib/key.h
        lib/key.cpp
        lib/feistel.cpp)
