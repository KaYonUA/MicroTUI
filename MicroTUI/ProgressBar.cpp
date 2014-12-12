#include "ProgressBar.h"

namespace MicroTUI
{
	namespace GUI
	{
		void ProgressBar::SetProgress(int progr)
		{
			if (progr<=100 && progr>=0)
				_cr_progress = progr;
			else
				if (progr < 0)
					_cr_progress = 0;
				else
					_cr_progress = 100;

		}
		void ProgressBar::_Render_func(ScreenBuffer* _scr_buf, COORD _wnd_coord)
		{
			COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _wnd_coord.X;
			_g_widgCord.Y = WidgetCoord.Y + _wnd_coord.Y;

			_scr_buf->Rectangle(_g_widgCord.X, _g_widgCord.Y, WidgetSize.width, WidgetSize.height, Color::Pixel(' ', _bg_Color));
			_scr_buf->Rectangle(_g_widgCord.X, _g_widgCord.Y, _cr_progress == 100 ? WidgetSize.width : _cr_progress / step, WidgetSize.height, Color::Pixel(' ', _def_Color));
		}
	}
}