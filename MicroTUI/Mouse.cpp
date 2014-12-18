#include "Mouse.h"

namespace MicroTUI
{
	namespace GUI
	{
		Mouse::Mouse()
		{
			_c_col = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::Black);
			_c_pos.X = 0;
			_c_pos.Y = 0;
		}
		void Mouse::MoveCursor(int x, int y)
		{
			_c_pos.X = x;
			_c_pos.Y = y;
		}
		void Mouse::_Render_func(ScreenBuffer *buffer)
		{
			buffer->Set(SB_NEWBUFFER, _c_pos.X, _c_pos.Y, Color::Pixel(' ', _c_col));
		}
	}
}
