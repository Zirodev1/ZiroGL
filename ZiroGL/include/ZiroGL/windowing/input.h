#pragma once

#include "windowing/window.h"
#include <functional>

namespace ZiroGL {

    class Input {
    public:
        Input(Window& window);

        void setKeyCallback(std::function<void(int, int, int)> callback);
        void setMouseCallback(std::function<void(int, int, int)> callback);
        void setMouseMoveCallback(std::function<void(double, double)> callback);

    private:
        Window& _window;
    };

} // namespace ZiroGL

