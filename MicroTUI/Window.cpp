#include "Window.h"

namespace MicroTUI
{
	namespace GUI
	{
		Window::Window(char * Title_, int xCoord, int yCoord, int WidthWindow, int HeightWindow)
		{
			WindowTitle = new char[sizeof(Title_)];
			//std::copy<char*, char*>(Title_, Title_ + (sizeof(Title_) / sizeof(char)), WindowTitle);*/
			//strcpy(WindowTitle, Title_);
			int i;
			for (i = 0; Title_[i] != '\0'; i++)
				WindowTitle[i] = Title_[i];
			WindowTitle[i] = '\0';
			WindowCoord.X = xCoord;
			WindowCoord.Y = yCoord;
			WindowSize.width = WidthWindow;
			WindowSize.height = HeightWindow;
			WindowBackgroundF = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::LightGray);
			WindowBackgroundN = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::DarkGray);
			WinShadow = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::Black);
			_p_onFocus = false;
		}


		void Window::MoveWindow(int xCoord, int yCoord)
		{
			WindowCoord.X = xCoord;
			WindowCoord.Y = yCoord;
		}


		void Window::ResizeWindow(int WidthWindow, int HeightWindow)
		{
			WindowSize.width = WidthWindow;
			WindowSize.height = HeightWindow;
		}


		void Window::AddItem(Widget *widget)
		{
			/*widgetsList.push_back(*widget);*/
			childWidgets.push_back(widget);

		}


		void Window::_Render_func(ScreenBuffer *buffer)
		{
			char bgrLable;
			bgrLable = ' ';
			if (_p_onFocus != true)
				WindowBackground = WindowBackgroundF;
			else
				WindowBackground = WindowBackgroundN;
			buffer->Rectangle(WindowCoord.X + WindowSize.width, WindowCoord.Y + 1, 1, WindowSize.height, Color::Pixel(bgrLable, WinShadow));
			buffer->Rectangle(WindowCoord.X + 1, WindowCoord.Y + WindowSize.height, WindowSize.width - 1, 1, Color::Pixel(bgrLable, WinShadow));
			buffer->Rectangle(WindowCoord.X, WindowCoord.Y, WindowSize.width, WindowSize.height, Color::Pixel(bgrLable, WindowBackground));

			int TitleLength =strlen(WindowTitle);
			int LineLength = (WindowSize.width - TitleLength - 2) / 2;

			buffer->Label(WindowCoord.X + LineLength + 1, WindowCoord.Y, WindowTitle, WindowBackground);
			buffer->LineHorisontal(WindowCoord.Y, WindowCoord.X, WindowCoord.X + LineLength,true, WindowBackground);
			buffer->LineHorisontal(WindowCoord.Y, WindowCoord.X + LineLength + 2 + TitleLength, WindowCoord.X + WindowSize.width,true, WindowBackground);

			for (int it = 0; it < childWidgets.size(); it++)
				childWidgets.at(it)->_Render_func(buffer,WindowCoord);
		}


		bool Window::onFocus()
		{
			return _p_onFocus;
		}


		void Window::onFocus(bool Focused)
		{
			_p_onFocus = Focused;
		}

	}
}