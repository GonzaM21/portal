cmake_minimum_required(VERSION 3.5)

project(qt5-demo)

# Find the QtWidgets library
find_package(Qt5Widgets)

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

set(CMAKE_AUTOMOC ON)

# Agrego ej3/include a la lista de directorios de includes
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

# Esta macro toma cada uno los parámetros y ejecuta *uic* sobre ellos
# La aplicacion uic genera headers con la definición de los widgets
# a partir de un archivo .ui
# Los nombres de los headers generados se guardan en la variable pasada
# como primer parámetro.
# No, no los genera con la carpeta como prefijo.
qt5_wrap_ui(UIS_HEADERS
        VentanaPrincipal.ui
)

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

message("Headers generados: ${UIS_HEADERS}")

add_library(ventanaprincipal
  VentanaPrincipal.cpp
  ${UIS_HEADERS}
  )

# Use the Widgets module from Qt 5.
target_link_libraries(ventanaprincipal Qt5::Widgets)