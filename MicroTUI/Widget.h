#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include "Render\ScreenBuffer.h"
namespace MicroTUI
{
	namespace GUI
	{
		class Widget
		{
		public:
			Widget(int xCoord, int yCoord, int WidthWidget, int HeightWidget, char * str = nullptr);
			void MoveWidget(int xCoord, int yCoord);
			void ResizeWidget(int WidthWidget, int HeightWidget);
			virtual void _Render_func(ScreenBuffer*){};
		protected:
			mSIZE WidgetSize;
			COORD WidgetCoord;
			char * widgettitle;
		};
	}
}

#endif

