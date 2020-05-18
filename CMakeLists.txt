cmake_minimum_required(VERSION 3.16)
project(tlpi)

set(CMAKE_CXX_STANDARD 14)

add_executable(tlpi main.cpp chapter34/34_3.cpp chapter34/header.h chapter34/34_4.cpp tmp/tmp.h tmp/tmp.cpp)