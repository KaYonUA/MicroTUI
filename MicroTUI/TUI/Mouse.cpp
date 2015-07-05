#include "Mouse.h"

namespace MicroTUI
{
	Mouse::Mouse(){
		backgroundColor = cBlack;
		textColor = cBlack;
		_c_pos.X = 0;
		_c_pos.Y = 0;
	}
	void Mouse::MoveCursor(int x, int y){
		_c_pos.X = x;
		_c_pos.Y = y;
	}
	void Mouse::_Render_func(ScreenBuffer *buffer){
		buffer->Set(SB_NEWBUFFER, _c_pos.X, _c_pos.Y, Pixel::pixelGen('x', textColor, backgroundColor));
	}
}
