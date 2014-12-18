#include "Button.h"

namespace MicroTUI
{
	namespace GUI
	{
		void Button::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
		{
			COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X;
			_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y;

			int textlen = widgettitle.length();

			buffer->Rectangle(_g_widgCord.X, _g_widgCord.Y, WidgetSize.width, WidgetSize.height, Color::Pixel('.', bgL_colr));
			buffer->Lable(_g_widgCord.X + (WidgetSize.width / 2 - textlen / 2), _g_widgCord.Y + ((WidgetSize.height) / 2), widgettitle, tx_colr);
		}

		void Button::Click()
		{
			_f_ptr();
		}
	}
}