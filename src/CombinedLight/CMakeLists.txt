cmake_minimum_required(VERSION 3.18)

project(CombinedLight)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(combinedLight combinedLight.cpp)
add_dependencies(combinedLight copy_resources)
target_include_directories(combinedLight
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        PUBLIC ${CMAKE_SOURCE_DIR}/inc/SOIL2/src
        )
target_link_libraries(combinedLight glfw GLEW OpenGL soil2)