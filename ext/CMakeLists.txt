cmake_minimum_required(VERSION 3.20.0)

project(external_libraries C CXX)

find_package(X11 QUIET)
if(NOT X11_FOUND)
    message(FATAL_ERROR "X11 Library and headers not found in cmake search paths, this is needed for window creation, please install GNU developer tools with <sudo apt install xorg-dev>")
endif()


find_package(glad QUIET)
if(NOT glad_FOUND)
    message(WARNING "Glad is needed to render opengl/vulkan graphics is not found, attempting to install glad from git")
    find_package(Git)
    #if(NOT Git_Found)
     #   message(FATAL_ERROR "Git could not be found on host machine, unable to install GLAD to generate opengl graphics")
    #endif()

    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone
            https://github.com/markminch562/glad.git
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/glad
    )
    add_subdirectory(glad)
endif()


find_package(glfw QUIET)
if(NOT glfw_FOUND)
    message(WARNING "GLFW not found in cmake search path or in build path, installing GLFW git repo")
    find_package(Git)
    if(NOT Git_FOUND)
        message(FATAL_ERROR "Git not found, unable to add GLFW to source")
    endif()
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone
            https://github.com/markminch562/glfw.git
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/glfw
    )
    add_subdirectory(glfw/glfw)
endif()








