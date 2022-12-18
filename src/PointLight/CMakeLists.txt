cmake_minimum_required(VERSION 3.18)

project(PointLight)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(pointLight pointLight.cpp)
add_dependencies(pointLight copy_resources)
target_include_directories(pointLight
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(pointLight glfw GLEW OpenGL soil2)