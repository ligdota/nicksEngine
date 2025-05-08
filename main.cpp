#include <GLFW/glfw3.h>
#include <iostream>
#include "ecs.h"
#include "render.h"
#include "input.h"




float aspectRatio = 800.0f / 600.0f;




void frameBuffer_size_callback(GLFWwindow* window, int width, int height) {
	aspectRatio = static_cast<float>(width) / height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-aspectRatio, aspectRatio, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main() {

	if (!glfwInit()) {
		std::cerr << "GLFW init failed" << std::endl;
		return -1;
	}


	GLFWwindow* window = glfwCreateWindow(800, 600, "nicks engine", nullptr, nullptr);

	if (!window) {
		std::cerr << "Failed to create openGL window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);


	glfwSetFramebufferSizeCallback(window, frameBuffer_size_callback);


	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	frameBuffer_size_callback(window, width, height);





	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		// process game logic

		for (auto& entity : entities) {
			render(entity);
		}

		glfwSwapBuffers(window);	// swap buffers (display what has been drawn)
		
	}

	glfwTerminate(); // clean up glfw

	return 0;
}