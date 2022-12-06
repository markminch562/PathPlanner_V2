cmake_minimum_required(VERSION 3.21)
project(PathPlanner_V2)

set(CMAKE_CXX_STANDARD 17)

set(GIT_SUBMODULE_PATH "/ext/")

add_subdirectory(ext)
add_subdirectory(src)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/InternalData/images/Path1.png InternalData/images/Path1.png COPYONLY )


add_executable(PathPlanner main.cpp)
target_link_libraries(PathPlanner PUBLIC entryPoint)



#add_executable(PathPlanner_V2 src/executables/openWindow.cpp)
