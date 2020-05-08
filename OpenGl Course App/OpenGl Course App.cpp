#include <stdio.h>
#include<iostream>
#include<Gl/glew.h>
#include<GlFW/glfw3.h>

//Window dimensions
const GLint WIDTH = 800;
const GLint HEIGHT = 600;

int main()
{
	//Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "Error initializing GLFW";
		glfwTerminate();
		return 1;
	}

	//Setup GLFW window properties
	//GLFW Version

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	//Core Profile = No Backwards Compatibility

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Allow Forward Compatibility

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		std::cout << "GLFW Window Creation Failed";
		glfwTerminate();
		return 1;
	}

	//Get Buffer Size

	int bufferWidth;
	int bufferHeight;

	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//Set Context For GLEW to Use

	glfwMakeContextCurrent(mainWindow);

	//Allow Modern Extension Features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW Initialization Failed";
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Setup Viewport Size

	glViewport(0, 0, bufferWidth, bufferHeight);

	//Game Loop

	while (!glfwWindowShouldClose(mainWindow))
	{
		//Get + Handle user input events

		glfwPollEvents();

		//Clear Window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	

}

