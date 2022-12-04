cmake_minimum_required(VERSION 3.21)
project(PathPlanner_V2)

set(CMAKE_CXX_STANDARD 17)

set(GIT_SUBMODULE_PATH "/ext/")

add_subdirectory(ext)
add_subdirectory(src)

add_executable(PathPlanner main.cpp tests/HelloWorld.cpp)



#add_executable(PathPlanner_V2 src/executables/openWindow.cpp)
