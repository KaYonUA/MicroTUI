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
			buffer->LineVertical(_g_widgCord.X, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height - 1, false, tx_colr);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y, Color::Pixel(TLS_CORNER, tx_colr));
			buffer->LineHorisontal(_g_widgCord.Y, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width - 1, false, tx_colr);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width - 1, _g_widgCord.Y, Color::Pixel(TRS_CORNER, tx_colr));
			buffer->LineVertical(_g_widgCord.X + WidgetSize.width - 1, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height - 1, false, tx_colr);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width - 1, _g_widgCord.Y + WidgetSize.height-1, Color::Pixel(BRS_CORNER, tx_colr));
			buffer->LineHorisontal(_g_widgCord.Y + WidgetSize.height - 1, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width - 1, false, tx_colr);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y + WidgetSize.height - 1, Color::Pixel(BLS_CORNER, tx_colr));
		}

		void Button::Click()
		{
			_f_ptr();
		}
	}
}
