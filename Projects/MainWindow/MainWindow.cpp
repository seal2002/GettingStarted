#include "MainWindow.hpp"

#include <GLFW/glfw3.h>

namespace OpenGLWindow
{
	Window::Window(int width, int height, const std::string& title)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		wnd = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(wnd);

		if (wnd == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initilize GLAD" << std::endl;
		}
	}
	
	Window::~Window()
	{
		glfwDestroyWindow(wnd);
		glfwTerminate();
	}

	bool Window::shouldClose() const noexcept
	{
		return glfwWindowShouldClose(wnd) != 0;
	}

	void Window::pollEvents() const noexcept
	{
		glfwPollEvents();
	}

	void Window::swapBuffers() const noexcept
	{
		glfwSwapBuffers(wnd);
	}

	std::pair<int, int> Window::getWindowSize() const noexcept
	{
		std::pair<int, int> sz{};
		glfwGetWindowSize(wnd, &sz.first, &sz.second);
		return sz;
	}
}