cmake_minimum_required(VERSION 3.18)

project(MiniGames)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_custom_target(copy_resources ALL)
add_custom_command(
        TARGET copy_resources PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res)


add_subdirectory(src/Shaders)
add_subdirectory(src/Triangle)
add_subdirectory(src/Textures)
add_subdirectory(src/Transform)
add_subdirectory(src/Projection)
add_subdirectory(src/Camera)
add_subdirectory(src/Lighting)
add_subdirectory(src/Materials)
add_subdirectory(src/LightingMaps)
add_subdirectory(inc/SOIL2)