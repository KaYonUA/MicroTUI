#include "GroupBox.h"

namespace MicroTUI
{
	namespace GUI
	{
		void GroupBox::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
		{
			COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X;
			_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y;

			buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y, Color::Pixel(TLS_CORNER,Color::_Transparent));

			if(widgettitle != 0)
			{
				int max_T_Size = WidgetSize.width - 4;
				int _t_Length = strlen(widgettitle);
				int _fl_length = WidgetSize.width - (5 + _t_Length);

				buffer->Set(SB_NEWBUFFER, _g_widgCord.X + 1, _g_widgCord.Y, Color::Pixel(HS_LINE, Color::_Transparent));
				buffer->Lable(_g_widgCord.X + 3, _g_widgCord.Y, widgettitle, _t_Length, Color::_Transparent);
				buffer->LineHorisontal(_g_widgCord.Y, _g_widgCord.X + 3 + _t_Length + 1, _g_widgCord.X + WidgetSize.width, false, Color::_Transparent);
			}
			else
				buffer->LineHorisontal(_g_widgCord.Y, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width, false, Color::_Transparent);

			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width, _g_widgCord.Y, Color::Pixel(TRS_CORNER, Color::_Transparent));
			buffer->LineVertical(_g_widgCord.X + WidgetSize.width, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height, false, Color::_Transparent);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width, _g_widgCord.Y + WidgetSize.height, Color::Pixel(BRS_CORNER, Color::_Transparent));
			buffer->LineHorisontal(_g_widgCord.Y + WidgetSize.height, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width, false, Color::_Transparent);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y + WidgetSize.height, Color::Pixel(BLS_CORNER, Color::_Transparent));
			buffer->LineVertical(_g_widgCord.X, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height, false, Color::_Transparent);
		}
	}
}