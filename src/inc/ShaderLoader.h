//
// Created by daniel on 1/3/23.
//

#ifndef MINIGAMES_SHADERLOADER_H
#define MINIGAMES_SHADERLOADER_H

#include <fstream>
#include <sstream>
#include <glm/ext/matrix_transform.hpp>

class ShaderLoader {
    GLuint program;

    enum shader_type {
        VERTEX_SHADER,
        FRAGMENT_SHADER,
    };

    GLuint loadShader(const char *filename, shader_type type) {
        GLuint shader;
        std::ifstream file;
        std::stringstream stream;
        std::string code_string;
        const GLchar *glString;

        file.exceptions(std::ifstream::badbit);
        try {
            file.open(filename);
            stream << file.rdbuf();
            code_string = stream.str();
            file.close();
        } catch (std::ifstream::failure &e) {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
        }
        glString = code_string.c_str();

        switch (type) {
            case VERTEX_SHADER:
                shader = glCreateShader (GL_VERTEX_SHADER);
                break;
            case FRAGMENT_SHADER:
                shader = glCreateShader (GL_FRAGMENT_SHADER);
        }

        glShaderSource (shader, 1, &glString, NULL);
        glCompileShader (shader);

        checkCompilation(shader);

        return shader;
    }

    void checkCompilation(GLuint id) {
        GLint success;
        GLchar infoLog[512];

        glGetShaderiv (id, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog (id, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog <<
                      std::endl;
        }
    }

    void checkLinking(GLuint id) {
        GLint success;
        GLchar infoLog[512];

        glGetProgramiv (id, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog (id, 512, NULL, infoLog);
            std::cout << "ERROR::LINKING_FAILED\n" << infoLog <<
                      std::endl;
        }
    }

public:
    ShaderLoader(const char *vertexFilename, const char *fragmentFilename) {

        GLuint vShader = loadShader(vertexFilename, VERTEX_SHADER);
        GLuint fShader = loadShader(fragmentFilename, FRAGMENT_SHADER);
        program = glCreateProgram ();

        glAttachShader (program, vShader);
        glAttachShader (program, fShader);
        glLinkProgram (program);

        checkLinking(program);

        glDeleteShader (vShader);
        glDeleteShader (fShader);

    }

    GLuint getProgram() {
        return program;
    }

    void setMat4(const std::string &name, const glm::mat4 &mat) const {
        glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(program, name.c_str()), value);
    }
};

#endif //MINIGAMES_SHADERLOADER_H
