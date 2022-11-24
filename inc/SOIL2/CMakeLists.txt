cmake_minimum_required(VERSION 3.18)

project(LibSOIL2)
find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/SOIL2/)
add_library(LibSOIL2 SOIL2.c)
target_link_libraries(LibSOIL2 glfw GLEW OpenGL)