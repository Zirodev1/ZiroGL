#pragma once

#include <vector>
#include <string>
#include <memory>
#include "core/physical_device.h"

namespace ZiroGL {

    class RenderBackend {
    public:
        RenderBackend();
        ~RenderBackend();

        bool initialize(const std::vector<std::string>& requiredExtensions);
        void destroy();

        std::vector<std::shared_ptr<PhysicalDevice>> enumeratePhysicalDevices() const;
        std::vector<std::string> getSupportedExtensions() const;

    private:
        // Add any private members needed for your implementation here
    };

} //
