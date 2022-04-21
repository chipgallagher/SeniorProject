#include "pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace vulkan {

	pipeline::pipeline(VulkDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) : device{ device } {
		createPipeline(vertFilepath, fragFilepath, configInfo);
	}

	
	std::vector<char> pipeline::readFile(const std::string& filepath) {

		std::ifstream file(filepath, std::ios::ate | std::ios::binary);

		if (!file.is_open()) {
			std::cout << "CANNOT FIND SHADER" << '\n';
			throw std::runtime_error("File open failed: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);
		
		file.seekg(0);
		file.read(buffer.data(), fileSize);


		file.close();
		return buffer;

	}

	void pipeline::createPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) {
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
		std::cout << "Frag Shader Code Size: " << fragCode.size() << '\n';
	}

	void pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const std::uint32_t*>(code.data());

		if (vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module!");
		}
	}

	PipelineConfigInfo pipeline::defaultPipelineConfigInfo(std::uint32_t width, std::uint32_t height) {
		PipelineConfigInfo configInfo{};

		return configInfo;
	}
}