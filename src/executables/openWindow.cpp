//
// Created by plotb on 11/13/22.
//

#include <iostream>
#include <string>
#include "Inputs/openWindow.h"

int main()
{
    std::cout<<"A window will be created here for this project"<<std::endl;

    GLFWwindow* window = createWindow(480, 640, "TestWindow");
    if(!window)
    {
        std::cout<<"Error window failed to be created in glfw"<<std::endl;
        return -1;
    }
    glfwSetKeyCallback(window, key_inputs);
    while(true)
    {
        glfwPollEvents();
    }
    //glfwDestroyWindow(window);
    //glfwTerminate();
    return 0;
}