#include "Widget.h"

namespace MicroTUI
{
	Widget::Widget(int xCoord, int yCoord, int WidthWidget, int HeightWidget, const char * str){
		backgroundColor = cWhite;
		textColor = cBlack;
		WidgetCoord.X = xCoord;
		WidgetCoord.Y = yCoord;
		WidgetSize.width = WidthWidget;
		WidgetSize.height = HeightWidget;
		if (str != 0)
			widgettitle = str;
		else
			widgettitle.clear();

	}

	void Widget::MoveWidget(int xCoord, int yCoord){
		WidgetCoord.X = xCoord;
		WidgetCoord.Y = yCoord;
	}

	void Widget::ResizeWidget(int WidthWidget, int HeightWidget){
		WidgetSize.width = WidthWidget;
		WidgetSize.height = HeightWidget;
	}

	void Widget::setBackgroundColor(ConsoleColor _color){
		backgroundColor = _color;
	}

	void Widget::setTextColor(ConsoleColor _color){
		textColor = _color;
	}
}