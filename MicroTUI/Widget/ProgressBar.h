#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "Widget.h"

namespace MicroTUI
{

	class ProgressBar : public Widget{
	public:
		ProgressBar(int xCoord, int yCoord, int WidthWidget, int HeightWidget);
		void _Render_func(ScreenBuffer *_scr_buf, COORD _wnd_coord);
		void SetProgress(int progr);
		void setColor(ConsoleColor color);
	private:
		double step;
		int _cr_progress;
		ConsoleColor color;
	};
}

#endif