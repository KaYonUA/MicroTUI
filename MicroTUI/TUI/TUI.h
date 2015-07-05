#pragma once
#ifndef TUI_H
#define TUI_H

#include "..\Render\Render.h"
#include "Window.h"
#include "Mouse.h"
#include <vector>
#include <thread>

const BYTE MOUSE_MOVED_ = 1;
const BYTE MOUSE_WHEELED_ = 2;
const BYTE MOUSE_RBCLICKED_ = 4;
const BYTE MOUSE_LBCLICKED_ = 8;
const BYTE MOUSE_DCLICKED_ = 16;
const BYTE MOUSE_BRELEAZED_ = 32;

namespace MicroTUI
{
	class TUI
	{
	public:
		TUI(int width, int height, char * str);

		void AddWindow(Window *window);
		void SetMouse(Mouse *mouse);
		void ClickMouse(int x, int y, bool _double);
		void ReleaseMouse(int x, int y);
		void moveMouse(int x, int y);
		void UpdateWindow();
		void ShowWindow();
		void _GetMessage();
		void _DispatchMessage();
		void MouseCursor(void(*Hendlr)(BYTE, COORD), HANDLE stdIn);
		void setTitle(char  * _string);
		void resizeConsole(int width, int height);
		unsigned short Width();
		unsigned short Height();
		ConsoleColor backgroundColor;
		ConsoleColor textColor;
	private:
		char * consoleTitle;

		Render _Rendr;
		ScreenBuffer * __Screenbuffer;
		std::vector<Window*> windowsList;
		Window* m_clickedWindow;
		Mouse *mouse;
	};
}

#endif

