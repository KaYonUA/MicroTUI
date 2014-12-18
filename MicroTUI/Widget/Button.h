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
				: Widget(xCoord, yCoord, WidthWidget, HeightWidget, str.c_str()), 
				bgL_colr(Color::Pixel::ColorToWord(Color::Pixel::LightBlue, Color::Pixel::LightBlue)),
				tx_colr(Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::LightBlue)), _f_ptr(hndlr){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
			void Click();
		private:
			void(*_f_ptr)(void);
			COLOR bgL_colr;
			COLOR tx_colr;
		};
	}
}

#endif

