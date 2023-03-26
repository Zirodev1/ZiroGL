#pragma once

#include <memory>
#include "core/device.h"

namespace ZiroGL {

	class CommandPool {
		CommandPool(std::shared_ptr<Device> device);
		~CommandPool();

		// Add any required methods to create, manage, and release command buffers

	private:
		std::shared_ptr<Device> m_device;
	};
}
