#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
namespace vulkan {

	class VulkWindow {

	public:
		VulkWindow(int w, int h, std::string name);
		~VulkWindow();

		//resource cleanliness - important later
		VulkWindow(const VulkWindow&) = delete;
		VulkWindow& operator=(const VulkWindow&) = delete;

		bool shouldClose() {
			//returns true if the user closes the window
			return glfwWindowShouldClose(window);
		}

	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}