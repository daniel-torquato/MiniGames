cmake_minimum_required(VERSION 3.18)

project(MiniGames)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_subdirectory(src/Shaders)
add_subdirectory(src/Triangle)
add_subdirectory(src/Textures)
add_subdirectory(src/Transformation)
add_subdirectory(inc/SOIL2)