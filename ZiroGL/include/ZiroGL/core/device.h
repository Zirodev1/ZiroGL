#pragma once

#include <memory>
#include "physical_device.h"
#include "swapchain/swapchain.h"

namespace ZiroGL {

	class Device : public std::enable_shared_from_this<Device> {
	public:
		Device(std::shared_ptr<PhysicalDevice> physicalDevice);
		~Device();

		std::shared_ptr<Swapchain> createSwapchain();

		// Add any required methods to create, manage, and release resources, as well as execute commands

	private:
		std::shared_ptr<PhysicalDevice> m_physicalDevice;
	};
}
