#ifndef LABLE_H
#define LABLE_H

#include "Widget.h"

namespace MicroTUI
{
	namespace GUI
	{
		class Lable : public Widget
		{
		public:
			Lable(char * str, int xCoord, int yCoord)
				: Widget(xCoord, yCoord, 0, 0, str){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
		};
	}
}

#endif