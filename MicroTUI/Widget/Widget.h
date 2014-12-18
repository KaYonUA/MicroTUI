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
			virtual void Click(){}
			virtual void _Render_func(ScreenBuffer*,COORD){};

			mSIZE WidgetSize;
			COORD WidgetCoord;
		protected:
			bool _f_Enebled;
			std::string widgettitle;
		};
	}
}

#endif

