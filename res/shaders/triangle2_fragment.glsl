#version 330 core

in vec3 myColor;
out vec4 color;

void main() {

    if (length(gl_FragCoord - vec4(400f, 300f, 0f, 0f)) < 50f) {
        color = vec4(1f, 0.0f, 0.0f, 1.0f);
    } else {
        color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
    }
    //color = vec4(myColor, 1.0f);
}
