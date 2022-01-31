#pragma once

#include "Utilities/Types.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<string>

namespace PhysX {

class GlApp
{
protected:
	static inline GlApp *_this = nullptr;

	static constexpr int _kMinimalWidth = 640;
	static constexpr int _kMinimalHeight = 480;

	GLuint _uboPassConstants = 0;

	GLFWwindow *_window;

	const int _savedWidth;
	const int _savedHeight;
	const std::string _savedTitle;

	int _width = 0;
	int _height = 0;
	Vector3f _bgColor = Vector3f(176, 196, 222) / 255;
public:
	GlApp(const int width, const int height, const std::string &caption);
	GlApp(const GlApp &rhs) = delete;
	GlApp &operator=(const GlApp &rhs) = delete;
	virtual ~GlApp()
	{
		glDeleteBuffers(1, &_uboPassConstants);
		glfwTerminate();
	}
	void run();//unfinished

protected:

	void initialize();//unfinished

	virtual void resize(const int width, const int height);//unfinished
	virtual void setCallbacks() const;//unfinished

	virtual void clearBuffers() const;

	static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
};
}
