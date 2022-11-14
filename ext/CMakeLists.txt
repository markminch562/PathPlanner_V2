cmake_minimum_required(VERSION 3.20.0)

project(external_libraries C CXX)

find_package(X11 QUIET)
if(NOT X11_FOUND)
    message(FATAL_ERROR "X11 Library and headers not found in cmake search paths, this is needed for window creation, please install GNU developer tools with <sudo apt install xorg-dev>")
endif()

find_package(glfw QUIET)
if(NOT glfw_FOUND)
    message(WARNING "GLFW not found in cmake search path or in build path, installing GLFW git repo")
endif()


