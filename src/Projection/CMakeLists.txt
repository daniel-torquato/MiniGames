cmake_minimum_required(VERSION 3.18)

project(Projection)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(projection projection.cpp)
target_include_directories(projection
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(projection glfw GLEW OpenGL soil2)