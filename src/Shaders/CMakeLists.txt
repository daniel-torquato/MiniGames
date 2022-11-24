cmake_minimum_required(VERSION 3.18)

project(Shaders)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(shaders shaders.cpp)
target_include_directories(shaders PUBLIC ../inc)
target_link_libraries(shaders glfw GLEW OpenGL)