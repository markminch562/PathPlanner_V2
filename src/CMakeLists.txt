cmake_minimum_required(VERSION 3.20.0)

add_executable(window executables/openWindow.cpp)

target_link_libraries(window glad_gl_core glfw)