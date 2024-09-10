cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(TopDown)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir directorios de encabezados
include_directories(${CMAKE_SOURCE_DIR}/TopDown)

# Buscar e incluir las bibliotecas necesarias
find_package(raylib REQUIRED)

# Agregar todos los archivos .cpp al proyecto
file(GLOB SOURCES "TopDown/*.cpp")

# Crear el ejecutable
add_executable(topdown ${SOURCES})

# Enlazar las bibliotecas necesarias
target_link_libraries(topdown raylib)

# Configuración específica para Emscripten
if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set_target_properties(topdown PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s FULL_ES2=1 -s ASYNCIFY")
endif()