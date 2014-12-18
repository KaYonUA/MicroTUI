#pragma once
#ifndef MOUSE_H
#define MOUSE_H

#include "..\Render\ScreenBuffer.h"

namespace MicroTUI
{
	namespace GUI
	{
		class Mouse
		{
		public:
			Mouse();
			void MoveCursor(int x, int y);
			void _Render_func(ScreenBuffer *buffer);
		private:
			COORD _c_pos;
			COLOR _c_col;
		};
	}
}


#endif

