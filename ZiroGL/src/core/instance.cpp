#include "core/instance.h"
#include "core/physical_device.h"
#include "backend/render_backend.h"

namespace ZiroGL {

    ZGLInstance::ZGLInstance() {
        // Constructor - initialize any member variables as needed
    }

    ZGLInstance::~ZGLInstance() {
        // Destructor - release any resources held by the instance
    }

    bool ZGLInstance::initialize(const std::vector<std::string>& requiredExtensions) {
        // Here, you would initialize the rendering backend, which handles low-level graphics operations.
        // The actual implementation will depend on your target platform(s) and rendering techniques.
        renderBackend = std::make_shared<RenderBackend>();
        return renderBackend->initialize(requiredExtensions);
    }

    void ZGLInstance::destroy() {
        // Here, you would clean up and release any resources held by the rendering backend
        if (renderBackend) {
            renderBackend->destroy();
            renderBackend.reset();
        }
    }

    std::vector<std::shared_ptr<PhysicalDevice>> ZGLInstance::enumeratePhysicalDevices() const {
        // Here, you would query the rendering backend to discover available physical devices
        return renderBackend->enumeratePhysicalDevices();
    }

    std::vector<std::string> ZGLInstance::getSupportedExtension() const {
        // Here, you would query the rendering backend for the supported extensions
        return renderBackend->getSupportedExtensions();
    }

} //