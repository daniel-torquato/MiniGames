cmake_minimum_required(VERSION 3.18)

project(Lighting)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(lighting lighting.cpp)
add_dependencies(lighting copy_resources)
target_include_directories(lighting
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(lighting glfw GLEW OpenGL soil2)