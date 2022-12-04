//
// Created by plotb on 11/13/22.
//

#include <iostream>
#include <string>
//#include "GLFW/glfw3.h"
#include "Dynamic.h"
#include <dlfcn.h>
#include <filesystem>

#include "Window/WindowSystem.h"
typedef void* dl_handle;
typedef int (*running)();
int main()
{
    std::cout<<"A window will be created here for this project"<<std::endl;
    //GLFWwindow* window
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
    WindowLoader(3, 3, "Hello Window", 480, 920);


    return 0;
}