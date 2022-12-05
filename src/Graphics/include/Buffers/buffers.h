//
// Created by plotb on 12/4/22.
//

#ifndef PATHPLANNER_V2_BUFFERS_H
#define PATHPLANNER_V2_BUFFERS_H
#include <vector>
namespace Graphics
{

    enum BufferType
    {
        VERTEX, FRAGMENT, HEIGHT_MAP, INDEX
    };
    class Buffer
    {
        public:
            std::vector<float> vertexBuffer;
            std::vector<float> fragmentBuffer;
            std::vector<float> indexBuffer;
    };





}




#endif //PATHPLANNER_V2_BUFFERS_H
