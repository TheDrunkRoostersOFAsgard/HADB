cmake_minimum_required(VERSION 3.6)
project(Server_)

set(CMAKE_CXX_STANDARD 11)

#Include Allegro
INCLUDE_DIRECTORIES(/usr/local/lib/)
LINK_DIRECTORIES( /usr/local/lib/)

INCLUDE_DIRECTORIES( usr/json/include )
LINK_DIRECTORIES( usr/json/include/lib )

set(game_LIBS libsqlparser.so libjson.so)

set(SOURCE_FILES main.cpp Clientapp.h SQL.h)
add_executable(Server_ ${SOURCE_FILES})

target_link_libraries(Server_ ${game_LIBS})