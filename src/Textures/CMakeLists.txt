cmake_minimum_required(VERSION 3.18)

project(Textures)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(textures textures.cpp)
target_include_directories(textures
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(textures glfw GLEW OpenGL soil2)