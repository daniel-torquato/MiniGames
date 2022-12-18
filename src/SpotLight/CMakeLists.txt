cmake_minimum_required(VERSION 3.18)

project(SpotLight)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(spotLight spotLight.cpp)
add_dependencies(spotLight copy_resources)
target_include_directories(spotLight
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(spotLight glfw GLEW OpenGL soil2)