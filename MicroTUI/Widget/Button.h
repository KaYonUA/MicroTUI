#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include "Widget.h"

namespace MicroTUI
{
	class Button : public Widget
	{
	public:
		Button(std::string str, int xCoord, int yCoord, int WidthWidget, int HeightWidget, void(*hndlr)(void))
			: Widget(xCoord, yCoord, WidthWidget, HeightWidget, str.c_str()), buttonPushed(false),
			pBackgroundColor(cDarkGray), _f_ptr(hndlr){}
		void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
		void setColor(ConsoleColor color);
		void mouseClick();
		void mouseRelease();
	private:
		void(*_f_ptr)(void);
		bool buttonPushed;
		bool buttonWork;
		ConsoleColor pBackgroundColor;
	};
}

#endif

