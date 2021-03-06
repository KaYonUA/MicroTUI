#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "..\Render\ScreenBuffer.h"
#include "..\Widget\Widget.h"
#include <vector>

namespace MicroTUI
{
	const BYTE W_BORDERED = 1;
	const BYTE W_MAXIMIZED = 2;
	const BYTE W_SHADOW = 4;
	const BYTE W_VISIBLE = 8;
	const BYTE W_ONTOP = 16;
	const BYTE W_FIXED = 32;

	inline bool BitChecked(BYTE _pws_mem, unsigned _b_count){ return (_pws_mem & (1 << _b_count)) != 0; }

	class Window
	{
	public:
		Window(char * Title_, int xCoord, int yCoord, int WidthWindow, int HeightWindow, BYTE param);

		void MoveWindow(int xCoord, int yCoord);
		void ResizeWindow(int WidthWindow, int HeightWindow);
		void AddWidget(Widget *widget);

		void _h_lclicked(int lx, int ly, bool _double);
		void _h_lreleased(int lx, int ly);
		void _h_lmoved(int lx, int ly);

		bool onFocus();
		void onFocus(bool Focused);
		void setFlags(BYTE param);
		void _Render_func(ScreenBuffer *buffer);

		mSIZE WindowSize;
		COORD WindowCoord;
		ConsoleColor backgroundColor;
		ConsoleColor borderColor;

		bool _f_fixed;
		bool _f_onFocus;
		bool _f_border;
		bool _f_maximiz;
		bool _f_shadow;
		bool _f_visible;
		bool _f_top_;
	private:

		bool Draging;
		COORD dragStart;
		ConsoleColor shadowColor;
		std::vector<Widget*> childWidgets;
		Widget* m_clickedWidget;
		char * WindowTitle;
	};
}

#endif

