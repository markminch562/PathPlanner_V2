//
// Created by plotb on 12/4/22.
//
#include "glad/gl.h"
#include "graphics/display.hpp"
#include "graphics/ShaderData.h"
#include "window/WindowSystem.h"
namespace Graphics
{

    int Display::LoadShaders() {
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char *vertexShaderSource = getVertexShader();
        glShaderSource(vertexShader, 1, &vertexShaderSource , NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            return 0;
        }
        // fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char *fragmentShaderSource = getFragmentShader();
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            return 0;
        }
        // link shaders
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    //
    int Display::createMainWindow(const char* windowName, int width, int height) {
        currentWindow = WindowLoader(4, 1, windowName, width, height);
        if(currentWindow == nullptr)
        {
            return 0;
        }
        glfwMakeContextCurrent(currentWindow);

    }
    void Display::refreshDisplay() {
        glfwSwapBuffers(currentWindow);
        glfwPollEvents();

    }
    Display::~Display() {
        glfwDestroyWindow(currentWindow);
        glfwTerminate();
    }




}