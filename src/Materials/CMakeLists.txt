cmake_minimum_required(VERSION 3.18)

project(Materials)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(materials materials.cpp)
add_dependencies(materials copy_resources)
target_include_directories(materials
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(materials glfw GLEW OpenGL soil2)