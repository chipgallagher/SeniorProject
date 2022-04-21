#pragma once

#include <string>
#include <vector>
#include "device.hpp"

namespace vulkan {

	struct PipelineConfigInfo {};

	class VulkPipeline {
	public:
		VulkPipeline(VulkDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

		~VulkPipeline(){}

		VulkPipeline(const VulkPipeline&) = delete;
		void operator=(const VulkPipeline&) = delete;

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