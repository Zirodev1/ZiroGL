#include "swapchain/swapchain.h"
#include "core/device.h"

namespace ZiroGL {

	Swapchain::Swapchain(std::shared_ptr<Device> device) : m_device(device) {
		// Constructer - initialize any member variables as needed
	}

	Swapchain::~Swapchain() {
		// Destructor - release any resources held by the swapchain
	}

	// Implement other methods as needed
}