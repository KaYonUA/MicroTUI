#include "Widget.h"

namespace MicroTUI
{
	namespace GUI
	{
		Widget::Widget(int xCoord, int yCoord, int WidthWidget, int HeightWidget, char * str)
		{
			WidgetCoord.X = xCoord;
			WidgetCoord.Y = yCoord;
			WidgetSize.width = WidthWidget;
			WidgetSize.height = HeightWidget;
			widgettitle = new char[sizeof(str)];
			int i; for (i = 0; *(str + i) != '\0'; i++)
				*(widgettitle + i) = *(str + i);
			*(widgettitle + i) = '\0';
		}

		void Widget::MoveWidget(int xCoord, int yCoord)
		{

		}

		void Widget::ResizeWidget(int WidthWidget, int HeightWidget)
		{

		}
	}
}