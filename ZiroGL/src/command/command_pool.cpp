#include "command/command_pool.h"

namespace ZiroGL {

	CommandPool::CommandPool(std::shared_ptr<Device> device) : m_device(device) {
		// Constructer - initialize any member variables as needed
	}

	CommandPool::~CommandPool() {
		// Destructor - release any resources held by the command pool
	}

	// Implement other methods as needed
}