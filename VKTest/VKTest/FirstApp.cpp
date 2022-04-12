#include "FirstApp.hpp"

namespace vulkan {
	
	void FirstApp::run() {
		while (!VulkWindow.shouldClose()) {
			glfwPollEvents();
		}
	}
}