#include "Window.h"

namespace MicroTUI
{
	Window::Window(char * Title_, int xCoord, int yCoord, int WidthWindow, int HeightWindow, BYTE param){
		m_clickedWidget = nullptr;
		WindowTitle = new char[sizeof(Title_)];
		int i;
		for (i = 0; *(Title_ + i) != '\0'; i++)
			*(WindowTitle + i) = *(Title_ + i);
		*(WindowTitle + i) = '\0';

		backgroundColor = cLightGray;
		borderColor = cDarkGray;
		shadowColor = cBlack;

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


	void Window::MoveWindow(int xCoord, int yCoord){
		WindowCoord.X = xCoord;
		WindowCoord.Y = yCoord;
	}


	void Window::ResizeWindow(int WidthWindow, int HeightWindow){
		WindowSize.width = WidthWindow;
		WindowSize.height = HeightWindow;
	}

	void Window::_h_lclicked(int lx, int ly, bool _double){
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
			if ((int)childWidgets[it]->WidgetCoord.X < lx && (int)childWidgets[it]->WidgetCoord.Y < ly &&
				lx <= (int)childWidgets[it]->WidgetCoord.X + (int)childWidgets[it]->WidgetSize.width &&
				ly <= (int)childWidgets[it]->WidgetCoord.Y + (int)childWidgets[it]->WidgetSize.height)
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
			if (vector.X + vector.Y != 0){
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

	void Window::AddWidget(Widget *widget){
		childWidgets.push_back(widget);
	}


	void Window::_Render_func(ScreenBuffer *buffer){
		if (_f_visible){
			COORD _loc_coord;
			if (_f_shadow){
				buffer->Rectangle(WindowCoord.X + WindowSize.width, WindowCoord.Y + 1, 1, WindowSize.height, Pixel::pixelGen(' ', shadowColor, shadowColor));
				buffer->Rectangle(WindowCoord.X + 1, WindowCoord.Y + WindowSize.height, WindowSize.width - 1, 1, Pixel::pixelGen(' ', shadowColor, shadowColor));
			}

			buffer->Rectangle(WindowCoord.X, WindowCoord.Y, WindowSize.width, 1, Pixel::pixelGen(' ', borderColor, borderColor));
			buffer->Rectangle(WindowCoord.X, WindowCoord.Y + 1, WindowSize.width, WindowSize.height - 1, Pixel::pixelGen(' ', cBlack, backgroundColor));

			int TitleLength = (int)strlen(WindowTitle);
			int LineLength = (WindowSize.width - TitleLength - 2) / 2;

			buffer->Lable(WindowCoord.X + LineLength + 1, WindowCoord.Y, WindowTitle, cBlack, cTransparent);
			buffer->LineHorisontal(WindowCoord.Y, WindowCoord.X, WindowCoord.X + LineLength, true, cBlack, cTransparent);
			buffer->LineHorisontal(WindowCoord.Y, WindowCoord.X + LineLength + 2 + TitleLength, WindowCoord.X + WindowSize.width, true, cBlack, cTransparent);

			if (_f_border){
				buffer->Set(SB_NEWBUFFER, WindowCoord.X + WindowSize.width - 1, WindowCoord.Y, Pixel::pixelGen(TRDtS_CORNER, borderColor, borderColor));
				buffer->LineVertical(WindowCoord.X + WindowSize.width - 1, WindowCoord.Y + 1, WindowCoord.Y + WindowSize.height - 1, false, borderColor, borderColor);
				buffer->Set(SB_NEWBUFFER, WindowCoord.X + WindowSize.width - 1, WindowCoord.Y + WindowSize.height - 1, Pixel::pixelGen(BRS_CORNER, borderColor, borderColor));
				buffer->LineHorisontal(WindowCoord.Y + WindowSize.height - 1, WindowCoord.X + 1, WindowCoord.X + WindowSize.width - 1, false, borderColor, borderColor);
				buffer->Set(SB_NEWBUFFER, WindowCoord.X, WindowCoord.Y + WindowSize.height - 1, Pixel::pixelGen(BLS_CORNER, borderColor, borderColor));
				buffer->LineVertical(WindowCoord.X, WindowCoord.Y + 1, WindowCoord.Y + WindowSize.height - 1, false, borderColor, borderColor);
				buffer->Set(SB_NEWBUFFER, WindowCoord.X, WindowCoord.Y, Pixel::pixelGen(TLStD_CORNER, borderColor, borderColor));

				_loc_coord.X = WindowCoord.X + 1;
				_loc_coord.Y = WindowCoord.Y + 1;
			}
			else{
				_loc_coord.X = WindowCoord.X;
				_loc_coord.Y = WindowCoord.Y + 1;
			}

			for (int it = 0; it < (int)childWidgets.size(); it++)
				childWidgets.at(it)->_Render_func(buffer, _loc_coord);
		}
	}


	bool Window::onFocus(){
		return _f_onFocus;
	}


	void Window::onFocus(bool Focused){
		_f_onFocus = Focused;
	}
}