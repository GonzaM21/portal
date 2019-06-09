cmake_minimum_required(VERSION 3.1)
project (portal)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS -pthread)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
set(CMAKE_CXX_STANDARD 11)

# Todos los #include son relativos a src
include_directories(src)
# Archivos generados por CMake
include_directories(${PROJECT_BINARY_DIR}/src)
include_directories(${PROJECT_BINARY_DIR}/src/server/modelo)

# Agrego la carpeta con los headers autogenerados a los includes
add_subdirectory(src/vista)
add_subdirectory(src/server)
add_subdirectory(src/common)
add_subdirectory(src/client)


add_executable (Client
  src/client/client.cpp
) 

add_executable (Server
  src/server/server.cpp
)

target_link_libraries(Client clientemodelo clientevista common)
#target_compile_features(Server PUBLIC cxx_std_17)
target_link_libraries(Server server common)
