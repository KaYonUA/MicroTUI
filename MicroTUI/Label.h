#ifndef LABEL_H
#define LABEL_H

#include "Widget.h"

namespace MicroTUI
{
	namespace GUI
	{
		class Label : public Widget
		{
		public:
			Label(char * str, int xCoord, int yCoord)
				: Widget(xCoord, yCoord, 0, 0, str), _f_isML(false){}
			Label(std::string *str, int xCoord, int yCoord)
				: Widget(xCoord, yCoord, 0, 0), _p_str(str), _f_isML(false){}
			Label(char * str, int xCoord, int yCoord,int width,int height)
				: Widget(xCoord, yCoord, width, height, str), _f_isML(true){}
			Label(std::string *str, int xCoord, int yCoord, int width, int height)
				: Widget(xCoord, yCoord, width, height), _p_str(str), _f_isML(true){}
			virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);
		private:
			std::string * _p_str;
			bool _f_isML;
		};
	}
}

#endif