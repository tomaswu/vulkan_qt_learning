#pragma once

#include <iostream>
#include <vulkan/vulkan.hpp>
#include <vector>
#include <string>
#include <memory>

namespace tw{
    class TContext{
        public:
            void Init();
            void Quit();
            static TContext& getTContext();
            
            // TContext(const TContext&)=delete;
            // const TContext & operator=(const TContext&)=delete;

            ~TContext();
            vk::Instance instance{nullptr};

        private:
            TContext();
            static std::unique_ptr<TContext> singleton;
    };
}