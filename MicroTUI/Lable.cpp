#include "Lable.h"

namespace MicroTUI
{
	namespace GUI
	{
		void Lable::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
		{
			COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X;
			_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y;

			buffer->Lable(_g_widgCord.X, _g_widgCord.Y, widgettitle == 0 ? _p_str->c_str() : widgettitle, Color::_Transparent);
		}
	}
}