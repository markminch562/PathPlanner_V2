cmake_minimum_required(VERSION 3.21.0)

add_library(WindowServices ../Graphics/src/WindowSystem.cpp ../Graphics/include/window/WindowSystem.h ../Graphics/include/window/keyInputs.h)
target_link_libraries(WindowServices PUBLIC glad_gl_core glfw)
target_include_directories(WindowServices PUBLIC include/)
#target_link_libraries(WindowServices PUBLIC glad glfw)

