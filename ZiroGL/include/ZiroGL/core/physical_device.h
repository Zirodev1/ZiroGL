#pragma once

#include <string>
#include <vector>

namespace ZiroGL {

    class PhysicalDevice {
    public:
        PhysicalDevice(); // You may need to add parameters depending on your implementation
        ~PhysicalDevice();

        // Add any required methods to query the capabilities and features of the physical device
        std::string getName() const;
        // Other methods like getAvailableMemory, getMaxTextureSize, getSupportedFormats, etc.
    };

} // namespace ZiroGL