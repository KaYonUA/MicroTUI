#include "GroupBox.h"

namespace MicroTUI
{
	namespace GUI
	{
		void GroupBox::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
		{
			int max_T_Size = WidgetSize.width - 4;
			int _t_Length = strlen(widgettitle);
			int _fl_length = WidgetSize.width - (5 + _t_Length);
			COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X + 1;
			_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y + 1;

			Color::Pixel _b_TranspP = buffer->Get(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y);

			buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y, Color::Pixel(TLS_CORNER, _b_TranspP.Color));
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + 1, _g_widgCord.Y, Color::Pixel(HS_LINE, _b_TranspP.Color));

			buffer->Label(_g_widgCord.X + 3, _g_widgCord.Y, widgettitle, _t_Length, _b_TranspP.Color);
			buffer->LineHorisontal(_g_widgCord.Y,_g_widgCord.X + 3 + _t_Length + 1 , _g_widgCord.X + WidgetSize.width, false, _b_TranspP.Color);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width, _g_widgCord.Y, Color::Pixel(TRS_CORNER, _b_TranspP.Color));
			buffer->LineVertical(_g_widgCord.X + WidgetSize.width, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height, false, _b_TranspP.Color);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width, _g_widgCord.Y + WidgetSize.height, Color::Pixel(BRS_CORNER, _b_TranspP.Color));
			buffer->LineHorisontal(_g_widgCord.Y + WidgetSize.height,  _g_widgCord.X + 1,_g_widgCord.X + WidgetSize.width, false, _b_TranspP.Color);
			buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y + WidgetSize.height, Color::Pixel(BLS_CORNER, _b_TranspP.Color));
			buffer->LineVertical(_g_widgCord.X, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height, false, _b_TranspP.Color);
		}
	}
}