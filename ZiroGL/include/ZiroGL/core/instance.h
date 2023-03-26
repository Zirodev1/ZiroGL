#pragma once

#include <vector>
#include <string>
#include <memory>
#include "device.h"

namespace ZiroGL {

	class PhysicalDevice;
	class RenderBackend;

	class ZGLInstance {
	public:
		ZGLInstance();
		~ZGLInstance();

		bool initialize(const std::vector<std::string>& requiredExtension);
		void destroy();

		
		std::vector<std::shared_ptr<PhysicalDevice>> enumeratePhysicalDevices() const;
		std::vector<std::string> getSupportedExtension() const;
		std::shared_ptr<Device> createDevice(const std::shared_ptr<PhysicalDevice>& physicelDevice) {
			return std::make_shared<Device>(physicelDevice);
		}

	private:
		std::shared_ptr<RenderBackend> renderBackend;
	};
}
