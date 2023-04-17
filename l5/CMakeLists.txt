cmake_minimum_required(VERSION 3.5)

project(image LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(image main.cpp image.cpp image.h)
