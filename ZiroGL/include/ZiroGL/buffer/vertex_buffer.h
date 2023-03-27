#pragma once

#include <vector>
#include <cstddef>

namespace ZiroGL {

	class VertexBuffer {
	public:
		VertexBuffer(const std::vector<float>& data);
		~VertexBuffer();

		void bind() const;
		void unbind() const;

	private:
		unsigned int _bufferID;
		// Add any necessary backend-specific data members here.
	};
}
