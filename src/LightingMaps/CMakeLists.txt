cmake_minimum_required(VERSION 3.18)

project(LightingMaps)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(lightingMaps lightingMaps.cpp)
add_dependencies(lightingMaps copy_resources)
target_include_directories(lightingMaps
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(lightingMaps glfw GLEW OpenGL soil2)