cmake_minimum_required(VERSION 3.5)

project(Figures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
endif()

add_executable(Figures main.cpp)
target_link_libraries(Figures glfw GLEW OpenGL::GL)
