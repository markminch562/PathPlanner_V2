cmake_minimum_required(VERSION 3.21.0)

find_package(Git QUIET)
set(GLAD_TARGET_AVAILABLE FALSE)

if(NOT ${GLAD_TARGET_AVAILABLE})
    message("GLAD PACKAGE NOT FOUND")
    if(GIT_FOUND)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init glad
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --update failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
        set(GLAD_TARGET_AVAILABLE TRUE)
    endif()
endif()

if(${GLAD_TARGET_AVAILABLE})
    message("Glad target was available")
    set(GLAD_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glad/")
    add_subdirectory("${GLAD_SOURCES_DIR}/cmake" glad_mx)
    #This program aims to be usable someday on linux, mac, and windows and so OpenGl will only be used up to the version available to mac computers
    glad_add_library(glad_gl_core SHARED API gl:core=4.1)
endif()