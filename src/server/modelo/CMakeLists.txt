cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS -pthread)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
set(CMAKE_CXX_STANDARD 11)

# Tomar los archivos fuente del cliente (todos los *.cpp)
add_subdirectory(3rdparty/Box2D-cmake)
file(GLOB libservermodelo_srcs *.cpp)
file(GLOB_RECURSE libservermodelobox_srcs Box2D/*.cpp)

# Generar una libería estática con todo el cliente EXCEPTO el main
add_library(servermodelo ${libservermodelo_srcs} ${libservermodelobox_srcs})
target_link_libraries(servermodelo TG::Box2D pthread)