cmake_minimum_required(VERSION 3.18)

project(Triangle2)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(triangle2 triangle2.cpp)
add_dependencies(triangle2 copy_resources)
target_include_directories(triangle2
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        )
target_link_libraries(triangle2 glfw GLEW OpenGL)