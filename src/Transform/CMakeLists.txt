cmake_minimum_required(VERSION 3.18)

project(Transform)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(transform transform.cpp)
target_include_directories(transform
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(transform glfw GLEW OpenGL soil2)
add_custom_command(
        TARGET transform POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/res
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res)