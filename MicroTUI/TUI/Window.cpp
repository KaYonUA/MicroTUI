#include "Window.h"

namespace MicroTUI
{
	namespace GUI
	{
		Window::Window(char * Title_, int xCoord, int yCoord, int WidthWindow, int HeightWindow, BYTE param)
		{
			m_clickedWidget = nullptr;
			WindowTitle = new char[sizeof(Title_)];
			int i;
			for (i = 0; *(Title_ + i) != '\0'; i++)
				*(WindowTitle + i) = *(Title_ + i);
			*(WindowTitle + i) = '\0';

			WindowBackground = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::LightGray);
			Border = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::DarkGray);
			WinShadow = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::Black);

			_f_onFocus = false;
			_f_border = BitChecked(param, 0);
			_f_maximiz = BitChecked(param, 1);
			_f_shadow = BitChecked(param, 2);
			_f_visible = BitChecked(param, 3);
			_f_top_ = BitChecked(param, 4);
			_f_fixed = BitChecked(param, 5);


			if (_f_maximiz)
			{
				mSIZE _tw_size = ScreenBuffer::_GetScreenSize();
				WindowCoord.X = 0;
				WindowCoord.Y = 0;
				WindowSize.width = _tw_size.width;
				WindowSize.height = _tw_size.height;
			}
			else
			{
				WindowCoord.X = xCoord;
				WindowCoord.Y = yCoord;
				WindowSize.width = WidthWindow;
				WindowSize.height = HeightWindow;
			}
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

		void Window::_h_lclicked(int lx, int ly, bool _double)
		{
			if (ly == 0 && !_f_fixed){
				if (_double)
					_f_maximiz = true;
				else{
					Draging = true;
					dragStart = { lx + WindowCoord.X, ly + WindowCoord.Y };
				}
			}
			else{
				if (_f_border == false)
					lx += 1;
				for (int it = (int)childWidgets.size() - 1; it >= 0; it--)
				if (childWidgets[it]->WidgetCoord.X < lx &&childWidgets[it]->WidgetCoord.Y < ly &&
					lx <= childWidgets[it]->WidgetCoord.X + childWidgets[it]->WidgetSize.width &&
					ly <= childWidgets[it]->WidgetCoord.Y + childWidgets[it]->WidgetSize.height)
				{
					childWidgets[it]->mouseClick();
					m_clickedWidget = childWidgets[it];
					break;
				}
			}
		}

		void Window::_h_lreleased(int lx, int ly){
			if (m_clickedWidget != nullptr){
				m_clickedWidget->mouseRelease();
				m_clickedWidget = nullptr;
			}
			Draging = false;
		}

		void Window::_h_lmoved(int lx, int ly){
			if (Draging){
				COORD vector = { 0, 0 };
				vector.X = lx - dragStart.X;
				vector.Y = ly - dragStart.Y;
				if (vector.X + vector.Y != 0 ){
					MoveWindow(WindowCoord.X + vector.X, WindowCoord.Y + vector.Y);
					dragStart.X += vector.X;
					dragStart.Y += vector.Y;
				}
			}


		}

		void Window::setFlags(BYTE param){
			_f_border = BitChecked(param, 0);
			_f_maximiz = BitChecked(param, 1);
			_f_shadow = BitChecked(param, 2);
			_f_visible = BitChecked(param, 3);
			_f_top_ = BitChecked(param, 4);
			_f_fixed = BitChecked(param, 5);
		}

		void Window::AddWidget(Widget *widget)
		{
			childWidgets.push_back(widget);
		}


		void Window::_Render_func(ScreenBuffer *buffer)
		{
			if (_f_visible)
			{
				COORD _loc_coord;
				if (_f_shadow)
				{
					buffer->Rectangle(WindowCoord.X + WindowSize.width, WindowCoord.Y + 1, 1, WindowSize.height, Color::Pixel(' ', WinShadow));
					buffer->Rectangle(WindowCoord.X + 1, WindowCoord.Y + WindowSize.height, WindowSize.width - 1, 1, Color::Pixel(' ', WinShadow));
				}

				buffer->Rectangle(WindowCoord.X, WindowCoord.Y, WindowSize.width, 1, Color::Pixel(' ', Border));
				buffer->Rectangle(WindowCoord.X, WindowCoord.Y+1, WindowSize.width, WindowSize.height-1, Color::Pixel(' ', WindowBackground));

				int TitleLength = strlen(WindowTitle);
				int LineLength = (WindowSize.width - TitleLength - 2) / 2;

				buffer->Lable(WindowCoord.X + LineLength + 1, WindowCoord.Y, WindowTitle, Color::_Transparent);
				buffer->LineHorisontal(WindowCoord.Y, WindowCoord.X, WindowCoord.X + LineLength, true, Color::_Transparent);
				buffer->LineHorisontal(WindowCoord.Y, WindowCoord.X + LineLength + 2 + TitleLength, WindowCoord.X + WindowSize.width, true, Color::_Transparent);

				if (_f_border)
				{
					buffer->Set(SB_NEWBUFFER, WindowCoord.X + WindowSize.width - 1, WindowCoord.Y, Color::Pixel(TRDtS_CORNER, Border));
					buffer->LineVertical(WindowCoord.X + WindowSize.width - 1, WindowCoord.Y + 1, WindowCoord.Y + WindowSize.height - 1, false, Border);
					buffer->Set(SB_NEWBUFFER, WindowCoord.X + WindowSize.width - 1, WindowCoord.Y + WindowSize.height - 1, Color::Pixel(BRS_CORNER, Border));
					buffer->LineHorisontal(WindowCoord.Y + WindowSize.height - 1, WindowCoord.X + 1, WindowCoord.X + WindowSize.width - 1, false, Border);
					buffer->Set(SB_NEWBUFFER, WindowCoord.X, WindowCoord.Y + WindowSize.height - 1, Color::Pixel(BLS_CORNER, Border));
					buffer->LineVertical(WindowCoord.X, WindowCoord.Y + 1, WindowCoord.Y + WindowSize.height - 1, false, Border);
					buffer->Set(SB_NEWBUFFER, WindowCoord.X, WindowCoord.Y, Color::Pixel(TLStD_CORNER, Border));

					_loc_coord.X = WindowCoord.X + 1;
					_loc_coord.Y = WindowCoord.Y + 1;
				}
				else
				{
					_loc_coord.X = WindowCoord.X;
					_loc_coord.Y = WindowCoord.Y + 1;
				}

				for (int it = 0; it < (int)childWidgets.size(); it++)
					childWidgets.at(it)->_Render_func(buffer, _loc_coord);
			}
		}


		bool Window::onFocus()
		{
			return _f_onFocus;
		}


		void Window::onFocus(bool Focused)
		{
			_f_onFocus = Focused;
		}

	}
}