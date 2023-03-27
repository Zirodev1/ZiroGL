#include <iostream>
#include "core/instance.h"
#include "core/physical_device.h"
#include "windowing/window.h"
#include "windowing/input.h"

void keyCallback(int key, int scancode, int action) {
	// Handle key events here
	std::cout << "Key: " << key << " Scancode: " << scancode << " Action: " << action << std::endl;
}

void mouseCallback(int xPos, int yPos, int button) {
	// Handle mouse events here
	std::cout << "Mouse Pos: (" << xPos << ", " << yPos << ") Button: " << button << std::endl;
}

void mouseMoveCallback(double x, double y) {
	std::cout << "Mouse Move: x = " << x << ", y = " << y << std::endl;
}


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

	ZiroGL::Window window(800, 600, L"ZiroGL Test Window");

	window.setKeyCallback(keyCallback);
	window.setMouseCallback(mouseCallback);
	window.setMouseMoveCallback(mouseMoveCallback);

	MSG msg;
	while (true) {
		window.processEvents();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	instance.destroy();
	return 0;
}


