#pragma once

#include <string>
#include <Windows.h>
#include <functional>
#include <unordered_map>

namespace ZiroGL {

	class Window {
	public:
		Window(int width, int height, const std::wstring& title);
		~Window();

		void setKeyCallBack(std::function<void(int, int, int)> callback);
		void setMouseCallback(std::function<void(int, int, int)> callback);
		void setMouseMoveCallback(std::function<void(double, double)> callback);
		void processEvents();

	private:
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		HWND _hwnd;

		std::function<void(int, int, int)> _keyCallback;
		std::function<void(int, int, int)> _mouseCallback;
		std::function<void(double, double)> _mouseMoveCallback;
		static std::unordered_map<HWND, Window*> _windowInstances;
	};
}