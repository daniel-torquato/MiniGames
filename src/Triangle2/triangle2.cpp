#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ShaderLoader.h>

const GLuint WIDTH = 800, HEIGHT = 600;

void escapeWindow(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main () {

	glfwInit();

	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow *window = glfwCreateWindow (
			WIDTH,
			HEIGHT,
			"LearnOpenGL",
			nullptr,
			nullptr
			);

    glEnable(GL_MULTISAMPLE);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize (window, &screenWidth, &screenHeight);
	if (nullptr == window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent (window);

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit ()) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_SUCCESS;
	}

	glViewport (0, 0, screenWidth, screenHeight);

    ShaderLoader shaderLoader("res/shaders/triangle2_vertex.glsl",
                              "res/shaders/triangle2_fragment.glsl");

    GLuint program = shaderLoader.getProgram();
    /*
     *
     */

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	GLuint VBO, VAO;
	glGenVertexArrays (1, &VAO);
	glGenBuffers (1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer (GL_ARRAY_BUFFER, VBO);
	glBufferData (GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer (
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			3 * sizeof(GLfloat),
			(GLvoid *) 0);

	glEnableVertexAttribArray (0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	while (!glfwWindowShouldClose (window)) {

        escapeWindow(window);
		glfwPollEvents ();

		glClearColor (0.5f, 0.3f, 0.3f, 1.0f);
		glClear (GL_COLOR_BUFFER_BIT);

		glUseProgram (program);
		glBindVertexArray (VAO);
		glDrawArrays (GL_TRIANGLE_FAN, 0, 3);
		glBindVertexArray (0);

		glfwSwapBuffers (window);
	}

	glDeleteVertexArrays (1, &VAO);
	glDeleteBuffers (1, &VBO);

	glfwTerminate ();

	return EXIT_SUCCESS;
}
