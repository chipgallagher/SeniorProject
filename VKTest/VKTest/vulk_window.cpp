#include "window.hpp"

namespace vulkan {

	VulkWindow::VulkWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name }{
		initWindow();
	}

	VulkWindow::~VulkWindow() {
		//destructor, terminates the window
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VulkWindow::initWindow() {
		//opens the GLFW window. disables OpenGL and makes the window not resizable.
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

}