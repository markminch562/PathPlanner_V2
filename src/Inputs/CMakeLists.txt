cmake_minimum_required(VERSION 3.20.0)

SET(WINDOW_INPUTS "${CMAKE_CURRENT_SOURCE_DIR}")
SET(WINDOW_SOURCE "${WINDOW_INPUTS}/src")

add_library(WindowInput  src/openWindow.cpp)
target_include_directories(WindowInput PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(WindowInput glad_gl_core_33 glfw)