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
			GroupBox(const char * str, int xCoord, int yCoord, int WidthWidget, int HeightWidget, bool line_s_ = false)
				: Widget(xCoord, yCoord, WidthWidget, HeightWidget, str), doub_lined(line_s_){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
		private:
			bool doub_lined;
		};

	}
}

#endif

