//
// Created by plotb on 11/30/22.
//


#include "glad/gl.h"
#define  GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "window/WindowSystem.h"
#include <iostream>






GLFWwindow* WindowLoader(int versionMajor, int versionMinor, const char* WindowName, int width,  int height)
{
    GLFWwindow* window;


    if(!glfwInit())  return nullptr;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    window = glfwCreateWindow(width, height, WindowName, NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    #ifdef __APPLE__
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    #else
        gladLoadGL(glfwGetProcAddress);
    #endif
    glfwSwapInterval(1);


    return window;
}

