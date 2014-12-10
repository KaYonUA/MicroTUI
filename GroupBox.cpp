#include "GroupBox.h"

namespace MicroTUI
{
	namespace GUI
	{
		void GroupBox::_Render_func(ScreenBuffer *buffer)
		{
			Color::Pixel _b_TranspP = buffer->Get(SB_NEWBUFFER, WidgetCoord.X, WidgetCoord.Y);

			int max_T_Size = WidgetSize.width - 4;
			int _t_Length = strlen(widgettitle);
			int _fl_length = WidgetSize.width - (5 + _t_Length);

			buffer->Set(SB_NEWBUFFER, WidgetCoord.X, WidgetCoord.Y, Color::Pixel(TLS_CORNER, _b_TranspP.Color));
			buffer->Set(SB_NEWBUFFER, WidgetCoord.X + 1, WidgetCoord.Y, Color::Pixel(HS_LINE, _b_TranspP.Color));

			buffer->Label(WidgetCoord.X + 3, WidgetCoord.Y, widgettitle, _t_Length, _b_TranspP.Color);
			buffer->LineHorisontal(WidgetCoord.Y,WidgetCoord.X + 3 + _t_Length + 1 , WidgetCoord.X + WidgetSize.width, false, _b_TranspP.Color);
			buffer->Set(SB_NEWBUFFER, WidgetCoord.X + WidgetSize.width, WidgetCoord.Y, Color::Pixel(TRS_CORNER, _b_TranspP.Color));
			buffer->LineVertical(WidgetCoord.X + WidgetSize.width, WidgetCoord.Y + 1, WidgetCoord.Y + WidgetSize.height, false, _b_TranspP.Color);
			buffer->Set(SB_NEWBUFFER, WidgetCoord.X + WidgetSize.width, WidgetCoord.Y + WidgetSize.height, Color::Pixel(BRS_CORNER, _b_TranspP.Color));
			buffer->LineHorisontal(WidgetCoord.Y + WidgetSize.height,  WidgetCoord.X + 1,WidgetCoord.X + WidgetSize.width, false, _b_TranspP.Color);
			buffer->Set(SB_NEWBUFFER, WidgetCoord.X, WidgetCoord.Y + WidgetSize.height, Color::Pixel(BLS_CORNER, _b_TranspP.Color));
			buffer->LineVertical(WidgetCoord.X, WidgetCoord.Y + 1, WidgetCoord.Y + WidgetSize.height, false, _b_TranspP.Color);
		}
	}
}