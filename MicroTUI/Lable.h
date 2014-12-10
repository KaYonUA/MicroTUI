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
			Lable(std::string *str, int xCoord, int yCoord)
				: Widget(xCoord, yCoord, 0, 0), _p_str(str){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
		private:
			std::string * _p_str;
		};
	}
}

#endif