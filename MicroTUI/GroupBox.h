#pragma once
#ifndef GROUPBOX_H
#define GROUPBOX_H

#include "Widget.h"

namespace MicroTUI
{
	namespace GUI
	{
		class GroupBox :
			public Widget
		{
		public:
			GroupBox(char * str, int xCoord, int yCoord, int WidthWidget, int HeightWidget)
				: Widget(xCoord, yCoord, WidthWidget, HeightWidget, str){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
		};

	}
}

#endif

