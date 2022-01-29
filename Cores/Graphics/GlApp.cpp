#include "GlApp.h"

#include<iostream>

namespace PhysX {

GlApp::GlApp(const int width, const int height, const std::string &title) :
	_savedWidth(width),
	_savedHeight(height),
	_savedTitle(title)
{
	_this = this;
	// Initialize GLFW.
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);//4x MSAA.
#ifdef _DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif
	//Create window
	_window = glfwCreateWindow(_savedWidth, _savedHeight, _savedTitle.c_str(), nullptr, nullptr);
	if (!_window) {
		std::cerr << "Error: [GlApp] Failed to create GLFW window." << std::endl;
		std::exit(-1);
	}
	glfwMakeContextCurrent(_window);
	//Initalize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Error: [GlApp] Failed to initialize GLAD." << std::endl;
		std::exit(-1);
	}
	glfwSetWindowSizeLimits(_window, _kMinimalWidth, _kMinimalHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

void GlApp::run()
{
	while (!glfwWindowShouldClose(_window)) {
		//Swap buffers and poll IO events
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
}
}
