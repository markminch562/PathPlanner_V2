cmake_minimum_required(VERSION  3.21.0)

project(Graphics CXX C)

set(CMAKE_CXX_STANDARD 17)

add_library(Graphics  src/WindowSystem.cpp src/shaderData.cpp src/display.cpp)
target_link_libraries(Graphics PUBLIC glad_gl_core glfw)
target_include_directories(Graphics PUBLIC include)
