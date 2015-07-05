#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include "..\Render\ScreenBuffer.h"

namespace MicroTUI
{
	namespace GUI
	{
		class Widget
		{
		public:
			Widget(int xCoord, int yCoord, int WidthWidget, int HeightWidget,const char * str = 0);
			void MoveWidget(int xCoord, int yCoord);
			void ResizeWidget(int WidthWidget, int HeightWidget);
			void setBackgroundColor(Color::Pixel::ConsoleColor _color);
			void setTextColor(Color::Pixel::ConsoleColor _color);
			virtual void mouseClick(){}
			virtual void mouseRelease(){}
			virtual void _Render_func(ScreenBuffer*,COORD){}

			mSIZE WidgetSize;
			COORD WidgetCoord;
		protected:
			bool _f_Enebled;
			std::string widgettitle;
			Color::Pixel::ConsoleColor backgroundColor;
			Color::Pixel::ConsoleColor textColor;
		};
	}
}

#endif

