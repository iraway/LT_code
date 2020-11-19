cmake_minimum_required(VERSION 3.5)

project(LT-code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER
    io.h
    distribution.h
    lt_code.h
    packet.h
    constants.h
    packetfactory.h
    utils.h
    )

set(SOURCE
    main.cpp
    io.cpp
    distribution.cpp
    lt_code.cpp
    packet.cpp
    packetfactory.cpp
    utils.cpp
    )

add_executable(LT-code ${SOURCE} ${HEADER})
