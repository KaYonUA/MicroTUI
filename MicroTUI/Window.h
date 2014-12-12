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
		const BYTE W_BORDERED = 1;
		const BYTE W_MAXIMIZED = 2;
		const BYTE W_SHADOW = 4;
		const BYTE W_VISIBLE = 8;
		const BYTE W_ONTOP = 16;


		inline bool BitChecked(BYTE _pws_mem, unsigned _b_count){ return (bool)(_pws_mem & (1 << _b_count)); }

		class Window
		{
		public:
			Window(char * Title_, int xCoord, int yCoord, int WidthWindow, int HeightWindow, BYTE param);
			void MoveWindow(int xCoord, int yCoord);
			void ResizeWindow(int WidthWindow, int HeightWindow);
			void AddWidget(Widget *widget);
			bool onFocus();
			void onFocus(bool Focused);
			void _Render_func(ScreenBuffer *buffer);

			COLOR WindowBackground;
			COLOR Border;
		private:
			COORD WindowCoord;
			COLOR WinShadow;
			mSIZE WindowSize;
			std::vector<Widget*> childWidgets;
			char * WindowTitle;

			/*Window flags*/
			bool _f_onFocus;
			bool _f_border;
			bool _f_maximiz;
			bool _f_shadow;
			bool _f_visible;
			bool _f_top_;
		};
	}
}

#endif

