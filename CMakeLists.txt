cmake_minimum_required(VERSION 3.17)
project(Client)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS *boost libraries here)


set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Client
        include/connectionHandler.h
        src/connectionHandler.cpp
        src/echoClient.cpp)