#include <iostream>
#include "core/instance.h"
#include "core/physical_device.h"

int main() {
	ZiroGL::ZGLInstance instance;

	std::vector<std::string> requiredExtensions = {}; // Add any required extensions here
	if (!instance.initialize(requiredExtensions)) {
		std::cerr << "Failed to initialize ZiroGL instance" << std::endl;
		return 1;
	}

	std::vector<std::shared_ptr<ZiroGL::PhysicalDevice>> physicalDevices = instance.enumeratePhysicalDevices();
	std::cout << "Found " << physicalDevices.size() << " physical devices" << std::endl;

	for (const auto& device : physicalDevices) {
		std::cout << "Device name: " << device->getName() << std::endl;
	}

	// create a logical device fro the first physical device found
	std::shared_ptr<ZiroGL::Device> device = instance.createDevice(physicalDevices[0]);
	std::cout << "Created logical device from physical device: " << physicalDevices[0]->getName() << std::endl;

	// Create a swapchain for the logical device
	std::shared_ptr<ZiroGL::Swapchain> swapchain = device->createSwapchain();
	std::cout << "Created swapchain for the logical device" << std::endl;

	instance.destroy();
	return 0;
}