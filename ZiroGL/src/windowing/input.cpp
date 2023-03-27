#include "windowing/input.h"
#include "windowing/window.h"

namespace ZiroGL {

    Input::Input(Window& window) : _window(window) {}

    void Input::setKeyCallback(std::function<void(int, int, int)> callback) {
        _window.setKeyCallback(callback);
    }

    void Input::setMouseCallback(std::function<void(int, int, int)> callback) {
        _window.setMouseCallback(callback);
    }

    void Input::setMouseMoveCallback(std::function<void(double, double)> callback) {
        _window.setMouseMoveCallback(callback);
    }

} // namespace ZiroGL
