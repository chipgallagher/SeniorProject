#pragma once

#include <string>
#include <vector>

namespace vulkan {
	class pipeline {
	public:
		pipeline(const std::string& vertFilepath, const std::string& fragFilepath);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createPipeline(const std::string& vertFilepath, const std::string& fragFilepath);

	};


}