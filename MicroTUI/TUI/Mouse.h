#pragma once
#ifndef MOUSE_H
#define MOUSE_H

#include "..\Render\ScreenBuffer.h"

namespace MicroTUI
{
	class Mouse
	{
	public:
		Mouse();
		void MoveCursor(int x, int y);
		void _Render_func(ScreenBuffer *buffer);
	private:
		COORD _c_pos;
		ConsoleColor backgroundColor;
		ConsoleColor textColor;
	};
}


#endif

