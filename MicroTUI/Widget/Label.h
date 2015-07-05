#ifndef LABEL_H
#define LABEL_H

#include "Widget.h"

namespace MicroTUI
{
	class Label : public Widget
	{
	public:
		Label(std::string str, int xCoord, int yCoord, int WidthWidget, int HeightWidget, bool multiline)
			: Widget(xCoord, yCoord, WidthWidget, HeightWidget, str.c_str()), _f_isML(multiline),
			L_colr(Pixel::ColorToWord(cBlack, cWhite)){}
		Label(std::string *str, int xCoord, int yCoord, int WidthWidget, int HeightWidget, bool multiline)
			: Widget(xCoord, yCoord, WidthWidget, HeightWidget), _p_str(str), _f_isML(multiline),
			L_colr(Pixel::ColorToWord(cBlack, cWhite)){}
		virtual void _Render_func(ScreenBuffer *buffer, COORD _w_Coord);

		COLOR L_colr;
	private:
		std::string * _p_str;
		bool _f_isML;
	};
}

#endif