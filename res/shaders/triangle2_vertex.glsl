#version 330 core
layout (location = 0) in vec3 position;

out vec3 myColor;

vec2 center = vec2(0.5f, 0.5f);

void main() {
    gl_Position = vec4(position.x, position.y, position.z, 1.0);

    myColor = vec3(0.5f + position.x, 0.5f + position.y, 0.5f + position.z);

}