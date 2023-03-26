#pragma once

#include <memory>


namespace ZiroGL {

	class Device;

	class Swapchain {
	public:
		Swapchain(std::shared_ptr<Device> device);
		~Swapchain();

		// Add any required methods to create, manage, and release image buffers

	private:
		std::shared_ptr<Device> m_device;
	};
}