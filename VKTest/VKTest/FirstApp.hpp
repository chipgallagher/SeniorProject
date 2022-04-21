#pragma once
#include "device.hpp"
#include "pipeline.hpp"
#include "window.hpp"

namespace vulkan {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1920;
        static constexpr int HEIGHT = 1080;

        void run();

    private:
        VulkWindow VulkWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
        VulkDevice VulkDevice{ VulkWindow };
        VulkPipeline VulkPipeline{VulkDevice, "shaders/vert.spv", "shaders/frag.spv", VulkPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };
    };
}