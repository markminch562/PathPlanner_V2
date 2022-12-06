cmake_minimum_required(VERSION 3.20.0)

#add_executable(window executables/openWindow.cpp DynamicLib/PrintBasic.cpp DynamicLib/RandomBasic.cpp DynamicLib/DynamicLib/Dynamic.h)

#target_link_libraries(window glad_gl_core glfw)
add_subdirectory(DynamicLib)
add_subdirectory(Graphics)
add_library(entryPoint executables/openWindow.cpp )

target_include_directories(entryPoint PUBLIC DynamicLib/DynamicLib)

target_link_libraries(entryPoint PUBLIC Graphics stb)
#target_include_directories(Print PUBLIC DynamicLib/DynamicLib)
#target_include_directories(Random PUBLIC DynamicLib/DynamicLib)