#pragma once

#include <string>
#include <Windows.h>

namespace ZiroGL {

	class Window {
		Window(int width, int height, const std::wstring& title);
		~Window();

		void processEvents();

	private:
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		HWND _hwnd;
	};
}