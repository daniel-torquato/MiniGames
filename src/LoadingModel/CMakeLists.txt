cmake_minimum_required(VERSION 3.18)

project(LoadingModel)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(loadingModel loadingModel.cpp)
add_dependencies(loadingModel copy_resources)
target_include_directories(loadingModel
        PUBLIC ${CMAKE_SOURCE_DIR}/src/inc
        )
target_link_libraries(loadingModel stb assimp glfw GLEW OpenGL)