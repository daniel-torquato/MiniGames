cmake_minimum_required(VERSION 3.18)

project(Triangle)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(triangle src/triangle.cpp)
add_executable(shaders src/shaders.cpp)
target_link_libraries(triangle glfw GLEW OpenGL)
target_link_libraries(shaders glfw GLEW OpenGL)
file(COPY res/shaders/ DESTINATION res/shaders/)