#pragma once
#include "device.hpp"
#include "pipeline.hpp"
#include "window.hpp"
#include "swapchain.hpp"

#include <memory>

namespace vulkan {
    class FirstApp {
    public:
        static constexpr int WIDTH = 1920;
        static constexpr int HEIGHT = 1080;
        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp&) = delete;
        FirstApp& operator=(const FirstApp&) = delete;
        void run();

    private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        VulkWindow vkWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
        VulkDevice vkDevice{ vkWindow };
        VulkSwapChain vkSwapchain{ vkDevice, vkWindow.getExtent() };
        std::unique_ptr<VulkPipeline> vkPipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        //VulkPipeline VulkPipeline{VulkDevice, "shaders/vert.spv", "shaders/frag.spv", VulkPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT) };
    };
}