cmake_minimum_required(VERSION 3.16)
project(tlpi)

set(CMAKE_CXX_STANDARD 14)

link_libraries(crypt)
link_libraries(acl)

add_executable(tlpi main.cpp 
               chapter34/34_3.cpp chapter34/header.h chapter34/34_4.cpp chapter34/34_7.cpp 
               tmp/tmp.h tmp/tmp.cpp
               chapter15/widgets.cpp chapter15/header.h chapter15/test.cpp 
               chapter17/header.h chapter17/17_1.cpp)
