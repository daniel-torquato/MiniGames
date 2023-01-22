//
// Created by daniel on 1/8/23.
//

#ifndef MINIGAMES_VERTEX_H
#define MINIGAMES_VERTEX_H

#include <glm/glm.hpp>

#define MAX_BONE_INFLUENCE 4

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    float m_Weights[MAX_BONE_INFLUENCE];
};

#endif //MINIGAMES_VERTEX_H
