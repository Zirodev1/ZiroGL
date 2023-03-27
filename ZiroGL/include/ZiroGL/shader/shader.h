#pragma once

#include <string>
#include <memory>

namespace ZiroGL {

    enum class ShaderType {
        Vertex,
        Fragment,
        Compute,
        Geometry
    };

    class Shader {
    public:
        Shader(ShaderType type, const std::string& source);
        ~Shader();

        bool compile();
        const std::string& getCompileLog() const;

    private:
        ShaderType m_type;
        std::string m_source;
        std::string m_compileLog;

        // Add any platform-specific implementation details
    };

} // namespace ZiroGL
