cmake_minimum_required(VERSION 3.21.0)

find_package(X11 QUIET)
if(NOT X11_FOUND)
    message(FATAL_ERROR "X11 Library and headers not found in cmake search paths, this is needed for window creation, please install GNU developer tools with <sudo apt install xorg-dev>")
endif()

find_package(glfw QUIET)
if(NOT glfw_FOUND)
    find_package(Git QUIET)

    if(GIT_FOUND)
        message(STATUS "Submodule GLFW updated")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init glfw
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --update failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
        add_subdirectory(glfw)
    endif()
endif()