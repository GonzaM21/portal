cmake_minimum_required(VERSION 3.1)


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS -pthread)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
set (CMAKE_CXX_STANDARD 11)

# Tomar los archivos fuente del cliente (todos los *.cpp)
file(GLOB libserver_srcs *.cpp)

add_subdirectory(modelo)
add_subdirectory(level_creator)

# Generar una libería estática con todo el server EXCEPTO el main
add_library(server ${libserver_srcs})
target_link_libraries(server
  levelcreator
  servermodelo
  common
  pthread
)
