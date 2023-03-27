#include "buffer/vertex_buffer.h"

namespace ZiroGL {

    VertexBuffer::VertexBuffer(const std::vector<float>& data) {
        // Initialize the backend-specific buffer object.
        // Replace this with your custom API's buffer object creation function.
        // For example: _bufferID = CustomAPI::createBuffer(data);
    }

    VertexBuffer::~VertexBuffer() {
        // Cleanup the backend-specific buffer object.
        // Replace this with your custom API's buffer object deletion function.
        // For example: CustomAPI::deleteBuffer(_bufferID);
    }

    void VertexBuffer::bind() const {
        // Bind the backend-specific buffer object.
        // Replace this with your custom API's buffer object binding function.
        // For example: CustomAPI::bindBuffer(_bufferID);
    }

    void VertexBuffer::unbind() const {
        // Unbind the backend-specific buffer object.
        // Replace this with your custom API's buffer object unbinding function.
        // For example: CustomAPI::unbindBuffer(_bufferID);
    }

} // namespace ZiroGL
