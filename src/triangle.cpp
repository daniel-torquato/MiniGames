#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


const GLuint WIDTH = 800, HEIGHT = 600;


/**
 * Shaders
 */
const GLchar *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main() {gl_Position = vec4(position.x, position.y, position.z, 1.0);}\0";

const GLchar *fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main() {color = vec4(1.0f, 0.7f, 0.2f, 1.0f);}\0";

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

	GLFWwindow *window = glfwCreateWindow (
			WIDTH,
			HEIGHT,
			"LearnOpenGL",
			nullptr,
			nullptr
			);

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


	GLuint vertexShader = glCreateShader (GL_VERTEX_SHADER);

	glShaderSource (vertexShader, 1, &vertexShaderSource, NULL);

	glCompileShader (vertexShader);

	GLint success;
	GLchar infoLog[512];

	glGetShaderiv (vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog (vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog <<
			std::endl;
	}

	GLuint fragmentShader = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader (fragmentShader);

	glGetShaderiv (fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog (fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog <<
			std::endl;
	}

	GLuint shaderProgram = glCreateProgram ();
	glAttachShader (shaderProgram, vertexShader);
	glAttachShader (shaderProgram, fragmentShader);
	glLinkProgram (shaderProgram);

	glGetProgramiv (shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog (shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog <<
			std::endl;
	}

	glDeleteShader (vertexShader);
	glDeleteShader (fragmentShader);

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
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

		glUseProgram (shaderProgram);
		glBindVertexArray (VAO);
		glDrawArrays (GL_TRIANGLE_FAN, 0, 4);
		glBindVertexArray (0);

		glfwSwapBuffers (window);
	}

	glDeleteVertexArrays (1, &VAO);
	glDeleteBuffers (1, &VBO);

	glfwTerminate ();

	return EXIT_SUCCESS;
}
