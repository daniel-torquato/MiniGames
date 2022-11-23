cmake_minimum_required(VERSION 3.18)

project(Triangle)

find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(triangle src/triangle.cpp)
target_link_libraries(triangle glfw)
target_link_libraries(triangle GLEW)
target_link_libraries(triangle OpenGL)
