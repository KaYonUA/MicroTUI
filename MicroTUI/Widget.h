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
			Widget(int xCoord, int yCoord, int WidthWidget, int HeightWidget,const char * str = 0);
			void MoveWidget(int xCoord, int yCoord);
			void ResizeWidget(int WidthWidget, int HeightWidget);
			virtual void _Render_func(ScreenBuffer*,COORD){};
		protected:
			bool _f_Enebled;
			mSIZE WidgetSize;
			COORD WidgetCoord;
			std::string widgettitle;
		};
	}
}

#endif

