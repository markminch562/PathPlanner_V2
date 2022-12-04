//
// Created by plotb on 11/13/22.
//

#include <iostream>
#include <string>
//#include "Dynamic.h"
#include <dlfcn.h>
#include <filesystem>
#include "graphics/display.hpp"
typedef void* dl_handle;
typedef int (*running)();


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key ==  GLFW_KEY_Q)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if(key == GLFW_KEY_L && action == GLFW_PRESS)
    {
        std::cout<<"Loading in context functions "<<std::endl;
    }
}


int run()
{
    std::cout<<"A window will be created here for this project"<<std::endl;
    //GLFWwindow* window
    /*
    dl_handle handle= nullptr;
    handle  = dlopen("./DynamicLib/libRandom.so", RTLD_LAZY);

    std::filesystem::path  cwd = std::filesystem::current_path();
    std::cout<<cwd<<std::endl;
    if(handle == nullptr)
    {
        std::cout<<"Error the print file could not be found"<<std::endl;
        return -1;
    }
    std::cout<<"The library file was found"<<std::endl;
    running runner = nullptr;
    void* fptr =dlsym(handle, "run");
    if (fptr == nullptr)
    {
        std::cout<<"Error the function was not found in the file"<<std::endl;
        return -1;
    }

    runner = (running)fptr;
    runner();

    dlclose(handle);
     */
    Graphics::Display display;
    display.createMainWindow("Basic Window", 640, 480);

    //glfwSetWindowUserPointer(window);

    while(display.DisplayRunning())
    {
        display.refreshDisplay();
    }



    return 0;
}