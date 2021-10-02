cmake_minimum_required(VERSION 3.20)
project(hash_duo)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

#set (CMAKE_CXX_FLAGS "-g -fsanitize=leak")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fsanitize=address -g")

add_executable(hash_duo
        src/duohash.cpp
        src/duohash.hpp)
