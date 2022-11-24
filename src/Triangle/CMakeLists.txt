cmake_minimum_required(VERSION 3.18)

project(Triangle)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(triangle triangle.cpp)
target_link_libraries(triangle glfw GLEW OpenGL)