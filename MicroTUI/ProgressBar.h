#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "Widget.h"

namespace MicroTUI
{
	namespace GUI
	{
		class ProgressBar
			: public Widget
		{
		public:
			ProgressBar(int xCoord, int yCoord, int WidthWidget, int HeightWidget)
				: Widget(xCoord, yCoord, WidthWidget, HeightWidget), 
				_def_Color(Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::Green)),
				_bg_Color(Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::White)),
				step(100.0f / WidthWidget), _cr_progress(0){}
			void _Render_func(ScreenBuffer *_scr_buf, COORD _wnd_coord);
			void SetProgress(int progr);
		private:
			double step;
			int _cr_progress;
			COLOR _def_Color;
			COLOR _bg_Color;
		};
	}
}

#endif