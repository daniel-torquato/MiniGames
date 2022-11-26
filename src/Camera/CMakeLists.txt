cmake_minimum_required(VERSION 3.18)

project(Camera)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(camera camera.cpp)
add_dependencies(camera copy_resources)
target_include_directories(camera
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(camera glfw GLEW OpenGL soil2)