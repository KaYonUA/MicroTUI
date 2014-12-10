#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "Render\ScreenBuffer.h"
#include "Widget.h"
#include <vector>

namespace MicroTUI
{
	namespace GUI
	{
		class Window
		{
		public:
			Window(char * Title_, int xCoord, int yCoord, int WidthWindow, int HeightWindow);
			void MoveWindow(int xCoord, int yCoord);
			void ResizeWindow(int WidthWindow, int HeightWindow);
			void AddWidget(Widget *widget);
			bool onFocus();
			void onFocus(bool Focused);
			void _Render_func(ScreenBuffer *buffer);

			COLOR WindowBackground;
		private:
			COLOR WindowBackgroundF;
			COLOR WindowBackgroundN;
			std::vector<Widget*> childWidgets;
			COORD WindowCoord;
			COLOR WinShadow;
			mSIZE WindowSize;
			bool _p_onFocus;
			char * WindowTitle;
		};
	}
}

#endif

