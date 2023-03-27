#pragma once

#include "core/device.h"

namespace ZiroGL {

	class GraphicsPipeline {
	public:
		GraphicsPipeline(std::shared_ptr<Device> device);
		~GraphicsPipeline();

		// Add methods for setting up and configuring the graphics pipeline

	private:
		std::shared_ptr<Device> device;
	};
}