cmake_minimum_required(VERSION 3.18)

project(Triangle)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB SOURCE_FILES src/*.cpp)
foreach(SOURCE_PATH ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})
    target_link_libraries(${EXECUTABLE_NAME} glfw GLEW OpenGL)
endforeach(SOURCE_PATH ${SOURCE_FILES})
file(COPY res/shaders/ DESTINATION res/shaders/)