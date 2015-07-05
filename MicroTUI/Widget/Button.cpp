#include "Button.h"
#include <thread>

namespace MicroTUI
{
	void Button::setColor(ConsoleColor color){
		pBackgroundColor = color;
	}

	void Button::_Render_func(ScreenBuffer *buffer, COORD _w_Coord){
		COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X;
		_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y;

		int textlen = (int)widgettitle.length();
		ConsoleColor background;

		if (buttonPushed)
			background = pBackgroundColor;
		else
			background = backgroundColor;
		buffer->Rectangle(_g_widgCord.X, _g_widgCord.Y, WidgetSize.width, WidgetSize.height, Pixel::pixelGen(' ', cBlack, background));
		buffer->Lable(_g_widgCord.X + (WidgetSize.width / 2 - textlen / 2), _g_widgCord.Y + ((WidgetSize.height) / 2), widgettitle, textColor, background);
		buffer->LineVertical(_g_widgCord.X, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height - 1, false, cBlack, background);
		buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y, Pixel::pixelGen(TLS_CORNER, cBlack, background));
		buffer->LineHorisontal(_g_widgCord.Y, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width - 1, false, cBlack, background);
		buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width - 1, _g_widgCord.Y, Pixel::pixelGen(TRS_CORNER, cBlack, background));
		buffer->LineVertical(_g_widgCord.X + WidgetSize.width - 1, _g_widgCord.Y + 1, _g_widgCord.Y + WidgetSize.height - 1, false, cBlack, background);
		buffer->Set(SB_NEWBUFFER, _g_widgCord.X + WidgetSize.width - 1, _g_widgCord.Y + WidgetSize.height - 1, Pixel::pixelGen(BRS_CORNER, cBlack, background));
		buffer->LineHorisontal(_g_widgCord.Y + WidgetSize.height - 1, _g_widgCord.X + 1, _g_widgCord.X + WidgetSize.width - 1, false, cBlack, background);
		buffer->Set(SB_NEWBUFFER, _g_widgCord.X, _g_widgCord.Y + WidgetSize.height - 1, Pixel::pixelGen(BLS_CORNER, cBlack, background));
	}

	void Button::mouseClick(){
		buttonPushed = true;
	}
	void Button::mouseRelease(){
		buttonPushed = false;
		std::thread mevent(_f_ptr);
		mevent.detach();
	}
}