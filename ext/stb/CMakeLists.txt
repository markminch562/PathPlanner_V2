cmake_minimum_required(VERSION 3.21.0)

find_package(stb QUIET)
if(NOT stb_FOUND)
    find_package(Git QUIET)

    if(GIT_FOUND)
        message(STATUS "Submodule STB updated")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init stb
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --update failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
        add_library(stb INTERFACE)
        target_include_directories(stb INTERFACE .)
    endif()
endif()