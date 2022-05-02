#include "FirstApp.hpp"
#include <stdexcept>

namespace vulkan {

	FirstApp::FirstApp() {
		createPipelineLayout();
		createPipelineLayout();
		createCommandBuffers();
	}

	FirstApp::~FirstApp() {
		vkDestroyPipelineLayout(vkDevice.device(), pipelineLayout, nullptr);
	}
	
	void FirstApp::run() {
		while (!vkWindow.shouldClose()) {
			glfwPollEvents();
		}
	}

	void FirstApp::createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if (vkCreatePipelineLayout(vkDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create pipeline layout!");
		}
	}

	void FirstApp::createPipeline() {
		auto pipelineConfig = VulkPipeline::defaultPipelineConfigInfo(vkSwapchain.width(), vkSwapchain.height());
		pipelineConfig.renderPass = vkSwapchain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		vkPipeline = std::make_unique<VulkPipeline>(vkDevice, "shaders/vert.spv", "shaders/frag.spv", pipelineConfig);
	}

	void FirstApp::createCommandBuffers() {

	}

	void FirstApp::drawFrame() {

	}
}