cmake_minimum_required(VERSION 3.5)

project(LT-code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(LT-code
    main.cpp
    io.cpp
    io.h
    distribution.cpp
    distribution.h
    )



