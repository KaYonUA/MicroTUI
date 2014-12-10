#include "Lable.h"

namespace MicroTUI
{
	namespace GUI
	{
		void Lable::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
		{
			COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X + 1;
			_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y + 1;

			Color::Pixel _b_TranspP = buffer->Get(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y);
			buffer->Label(_g_widgCord.X, _g_widgCord.Y, widgettitle, _b_TranspP.Color);
		}
	}
}