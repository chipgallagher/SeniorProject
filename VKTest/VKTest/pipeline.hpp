#pragma once

#include <string>
#include <vector>
#include "device.hpp"

namespace vulkan {

	struct PipelineConfigInfo {};

	class pipeline {
	public:
		pipeline(VulkDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

		~pipeline(){}

		pipeline(const pipeline&) = delete;
		void operator=(const pipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(std::uint32_t width, std::uint32_t height);

		

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		

		VulkDevice& device;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShader;
		VkShaderModule fragShader;

	};


}