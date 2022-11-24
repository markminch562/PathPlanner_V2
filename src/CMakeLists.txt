cmake_minimum_required(VERSION 3.20.0)

add_subdirectory(Inputs)

add_executable(window executables/openWindow.cpp)


target_link_libraries(window WindowInput)
message("${CMAKE_CURRENT_SOURCE_DIR}")


