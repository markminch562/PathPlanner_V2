//
// Created by plotb on 11/21/22.
//
#include "Inputs/openWindow.h"
void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: s%\n", description);
}


GLFWwindow* createWindow(int width, int height, const char* windowName)
{
    if(!glfwInit())
    {
        std::cout<<"GLFW Failed to run"<<std::endl;
        return nullptr;
    }
    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(width, height, windowName, NULL, NULL);
    if(!window)
    {
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    return window;
}

void key_inputs(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout<<"the key: "<<key<<" the scancode: "<<scancode<<" The action: "<<action<<" the bitmod:"<<mods<<std::endl;
    if(key == GLFW_KEY_Q)
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}