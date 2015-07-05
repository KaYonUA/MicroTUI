#include "GroupBox.h"

namespace MicroTUI
{
	void GroupBox::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
	{
		COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X;
		_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y;

		buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y, Pixel::pixelGen((doub_lined == true ? TLD_CORNER : TLS_CORNER), textColor, backgroundColor));

		if (widgettitle.empty() == false){
			int max_T_Size = WidgetSize.width - 4;
			int _t_Length = (int)widgettitle.size();
			int _fl_length = WidgetSize.width - (5 + _t_Length);

			buffer->Set(SB_NEWBUFFER, _g_widgCord.X + 1, _g_widgCord.Y, Pixel::pixelGen((doub_lined == true ? HD_LINE : HS_LINE), textColor, backgroundColor));
			buffer->Lable(_g_widgCord.X + 3, _g_widgCord.Y, widgettitle, textColor, backgroundColor);
			buffer->LineHorisontal(_g_widgCord.Y, _g_widgCord.X + 3 + _t_Length + 1, _g_widgCord.X + WidgetSize.width, doub_lined, textColor, backgroundColor);
		}
		else
			buffer->LineHorisontal(_g_widgCord.Y, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width, doub_lined, textColor, backgroundColor);

		buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width, _g_widgCord.Y, Pixel::pixelGen((doub_lined == true ? TRD_CORNER : TRS_CORNER), textColor, backgroundColor));
		buffer->LineVertical(_g_widgCord.X + WidgetSize.width, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height, doub_lined, textColor, backgroundColor);
		buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width, _g_widgCord.Y + WidgetSize.height, Pixel::pixelGen((doub_lined == true ? BRD_CORNER : BRS_CORNER), textColor, backgroundColor));
		buffer->LineHorisontal(_g_widgCord.Y + WidgetSize.height, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width, doub_lined, textColor, backgroundColor);
		buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y + WidgetSize.height, Pixel::pixelGen((doub_lined == true ? BLD_CORNER : BLS_CORNER), textColor, backgroundColor));
		buffer->LineVertical(_g_widgCord.X, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height, doub_lined, textColor, backgroundColor);
	}
}