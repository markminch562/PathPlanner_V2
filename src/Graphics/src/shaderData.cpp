//
// Created by plotb on 12/4/22.
//
#include <iostream>
#include "glad/gl.h"
#include "graphics/ShaderData.h"
namespace Graphics {
    const char *getVertexShader() {
        return "#version 330 core\n"
               "layout (location = 0) in vec3 aPos;\n"
               "layout (location = 1) in vec3 aColor;\n"
               "layout (location = 2) in vec2 aTexCoord;\n"

               "out vec3 ourColor;\n"
               "out vec2 TexCoord;\n"

               "void main()\n"
               "{\n"
               "    gl_Position = vec4(aPos, 1.0);\n"
               "    ourColor = aColor;\n"
               "    TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
               "}\0";
    }

    const char *getFragmentShader() {
        return "#version 330 core\n"
               "out vec4 FragColor;\n"
               "in vec3 ourColor;\n"
               "in vec2 TexCoord;\n"
               "uniform sampler2D texture1;\n"
               "void main()\n"
               "{\n"
               "   FragColor = texture(texture1, TexCoord);\n"
               "}\n\0";
    }
}