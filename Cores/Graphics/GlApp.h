#pragma once
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

};
}
