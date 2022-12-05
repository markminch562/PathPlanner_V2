//
// Created by plotb on 12/4/22.
//

#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include <string>
#include <iostream>
namespace Graphics
{
/*
    enum ShaderType
    {
        VERTEX, FRAGMENT, PARTICLE, GEOMETRY
    };


    class Shader
    {
        unsigned  int shaderProgram;
        std::string shaderData;
        int type;

        Shader() = default;
        Shader(const std::string& filePath, int type);

    };

*/
class Display
{
    GLFWwindow* currentWindow = nullptr;
    int shaderProgram;
    //TODO, add camera class, add shader compiler class, add user input handlers
    int displayRunning = 1;
public:
    int LoadShaders();

    ~Display();
    int createMainWindow(const char* windowName, int width, int height);
    void setInputSystem();
    void refreshDisplay();

    inline int DisplayRunning()
    {
        return  displayRunning;
    }
};

}
