//
// Created by plotb on 11/21/22.
//

#ifndef PATHPLANNER_V2_OPENWINDOW_H
#define PATHPLANNER_V2_OPENWINDOW_H

#include <iostream>
#define GLFW_INCLUDE_NONE
#include "glad/gl.h"
#include "GLFW/glfw3.h"

void error_callback(int error, const char* description);
GLFWwindow* createWindow(int width, int height, const char* windowName);

void closeWindow();

void key_inputs(GLFWwindow* window, int key, int scancode, int action, int mods);

struct CreateWindow
{
    int width;
    int height;
    int GladMajor;
    int GladMinor;
    GLFWwindow* Window;
};




#endif //PATHPLANNER_V2_OPENWINDOW_H
