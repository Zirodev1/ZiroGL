// src/backend/render_backend.cpp
#include "core/instance.h"
#include "backend/render_backend.h"
#include "core/physical_device.h"

namespace ZiroGL {

    RenderBackend::RenderBackend() {
        // Constructor - initialize any member variables as needed
    }

    RenderBackend::~RenderBackend() {
        // Destructor - release any resources held by the render backend
    }

    bool RenderBackend::initialize(const std::vector<std::string>& requiredExtensions) {
        // Here, you would initialize any platform-specific rendering resources
        return true;
    }

    void RenderBackend::destroy() {
        // Here, you would clean up and release any platform-specific rendering resources
    }


    std::vector<std::string> RenderBackend::getSupportedExtensions() const {
        // Here, you would query the platform-specific rendering backend for the supported extensions
        std::vector<std::string> extensions;
        return extensions;
    }

    std::vector<std::shared_ptr<PhysicalDevice>> RenderBackend::enumeratePhysicalDevices() const {
        // Here, you would query the platform-specific rendering backend to dicover availiable physical devices
        std::vector<std::shared_ptr<PhysicalDevice>> devices;

        //Create a dummy physical device as an example
        std::shared_ptr<PhysicalDevice> dummyDevice = std::make_shared<PhysicalDevice>();
        devices.push_back(dummyDevice);

        return devices;
    }

} // namespace ZiroGL
