#version 330 core
in vec3 ourColor;
in vec3 TexCoord;

out vec4 color;

uniform sampler2D outTexture1;

void main()
{
    color = texture(outTexture1, TexCoord);
}