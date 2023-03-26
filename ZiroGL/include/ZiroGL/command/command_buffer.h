#pragma once

#include <memory>
#include "command_pool.h"

namespace ZiroGL {

	class CommandBuffer {
	public:
		CommandBuffer(std::shared_ptr<CommandPool> commandPool);
		~CommandBuffer();

		// Add any required methods to record, submit, and manage commands

	private:
		std::shared_ptr<CommandPool> m_commandPool;
	};
}
