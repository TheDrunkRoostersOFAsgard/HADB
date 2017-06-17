cmake_minimum_required(VERSION 3.6)
project(Server_)

set(CMAKE_CXX_STANDARD 11)




set(SOURCE_FILES main.cpp Clientapp.h ParseJson.h)
add_executable(Server_ ${SOURCE_FILES})