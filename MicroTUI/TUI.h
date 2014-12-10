#pragma once
#ifndef TUI_H
#define TUI_H


#include "Render\Render.h"
#include "Window.h"
#include <vector>

namespace MicroTUI
{
	namespace GUI
	{
		class TUI
		{
		public:
			TUI();
			void AddWindow(Window *window);
			void UpdateWindow();
			void ShowWindow();
			void _GetMessage();
			void _DispatchMessage();
			unsigned short Width();
			unsigned short Height();
			COLOR BackgroundColor;
		private:
			Render _Rendr;
			ScreenBuffer __Screenbuffer;
			std::vector<Window*> windowsList;
		};
	}
}

#endif

