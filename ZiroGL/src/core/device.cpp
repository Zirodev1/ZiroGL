#include "core/device.h"

namespace ZiroGL {

	Device::Device(std::shared_ptr<PhysicalDevice> physicalDevice) : m_physicalDevice(physicalDevice) {
		// Constructor - initialize any member variables as needed
	}

	Device::~Device() {
		// Destructor - release any resources held by the device
	}

	std::shared_ptr<Swapchain> ZiroGL::Device::createSwapchain() {
		return std::make_shared<Swapchain>(shared_from_this());
	}

	// Implement other methods as needed
}