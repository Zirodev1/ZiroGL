#include "windowing/window.h"
#include <iostream>

#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))

namespace ZiroGL {

	std::unordered_map<HWND, Window*> Window::_windowInstances;

	Window::Window(int width, int height, const std::wstring& title) {
		WNDCLASS wc = { 0 };

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = L"ZiroGLWindowClass";

		RegisterClass(&wc);

		_hwnd = CreateWindowEx(
			0,
			L"ZiroGLWindowCLass",
			title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			width, height,
			NULL, NULL,
			GetModuleHandle(NULL),
			this
		);

		ShowWindow(_hwnd, SW_SHOW);
		_windowInstances[_hwnd] = this;
	}

	Window::~Window() {
		DestroyWindow(_hwnd);
		_windowInstances.erase(_hwnd);
	}

	void Window::setKeyCallBack(std::function<void(int, int, int)> callback) {
		_keyCallback = callback;
	}

	void Window::setMouseCallback(std::function<void(int, int, int)> callback) {
		_mouseCallback = callback;
	}

	void Window::setMouseMoveCallback(std::function<void(double, double)> callback) {
		_mouseMoveCallback = callback;
	}

	void Window::processEvents() {
		MSG msg;
		while (PeekMessage(&msg, _hwnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		Window* window = _windowInstances[hwnd];

		switch (uMsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			if (window->_keyCallback) {
				window->_keyCallback(static_cast<int>(wParam), (lParam & 0xFFFF0000) >> 16, uMsg);
			}
			return 0;

		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_MBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
			if (window->_mouseCallback) {
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				window->_mouseCallback(xPos, yPos, uMsg);
			}
			return 0;
		case WM_MOUSEMOVE:
			if (window->_mouseMoveCallback) {
				int xPos = GET_X_LPARAM(lParam);
				int yPos = GET_Y_LPARAM(lParam);
				window->_mouseMoveCallback(static_cast<double>(xPos), static_cast<double>(yPos));
			}
			return 0;

			// Handle other window events here...

		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
}