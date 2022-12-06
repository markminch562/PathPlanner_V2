//
// Created by plotb on 11/13/22.
//

#include <iostream>
#include <string>
//#include "Dynamic.h"
#include <dlfcn.h>
#include <filesystem>
#include "graphics/display.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
typedef void* dl_handle;
typedef int (*running)();





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
    display.setInputSystem();


    int width, height, nrChannels;

    unsigned char* image_map = nullptr;
    image_map = stbi_load("InternalData/images/Path1.png", &width, &height, &nrChannels, 0);
    if(image_map == nullptr)
    {
        return 0;
    }


    //glfwSetWindowUserPointer(window);

    while(display.DisplayRunning())
    {
        display.refreshDisplay();
    }



    return 0;
}