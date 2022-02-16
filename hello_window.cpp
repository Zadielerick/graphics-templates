#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

// glfw: default window settings
const unsigned int SRC_WIDTH = 800;
const unsigned int SRC_HEIGHT = 600;

int main()
{
	// glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw: window creation
	GLFWwindow* window = glfwCreateWindow(SRC_WIDTH, SRC_HEIGHT, "glfw-template-window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// glad: load all opengl function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

    // opengl: set viewport same as window
	glViewport(0, 0, 800, 600);


	// render loop
	while(!glfwWindowShouldClose(window))
	{
		// glfw: input processing for window
		processInput(window);

		// opengl: rendering commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate and clean-up
	glfwTerminate();

	return 0;
}

// glfw: query GLFW whether relavant keys are pressed/released this frame
void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the windows size is changed, this callback function executes
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the new width and height from screen size change
	glViewport(0, 0, width, height);
}
