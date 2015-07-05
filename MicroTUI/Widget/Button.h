#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include "Widget.h"

namespace MicroTUI
{
	namespace GUI
	{
		class Button : public Widget
		{
		public:
			Button(std::string str, int xCoord, int yCoord, int WidthWidget, int HeightWidget, void(*hndlr)(void))
				: Widget(xCoord, yCoord, WidthWidget, HeightWidget, str.c_str()), buttonPushed(false),
				pBackgroundColor(Color::Pixel::DarkGray), _f_ptr(hndlr){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
			void mouseClick();
			void mouseRelease();
		private:
			void(*_f_ptr)(void);
			bool buttonPushed;
			Color::Pixel::ConsoleColor pBackgroundColor;
		};
	}
}

#endif

