#include "TUI.h"

namespace MicroTUI
{
	namespace GUI
	{

		TUI::TUI()
		{
			BackgroundColor = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::LightBlue);
			_Rendr.Connect(&__Screenbuffer);
			mouse = nullptr;
		}

		void TUI::AddWindow(Window *window)
		{
			windowsList.push_back(window);
		}

		void TUI::SetMouse(Mouse *mouse)
		{
			this->mouse = mouse;
		}

		void TUI::UpdateWindow()
		{
			__Screenbuffer.Fill(Color::Pixel(' ', BackgroundColor));
			if (!windowsList.empty())
			{
				//if (windowsList[windowsList.size()-1]->onFocus() == true)
				for (int i = 0; i < (int)windowsList.size(); i++)
						windowsList[i]->_Render_func(&__Screenbuffer);
				//else
				//{
				//	for (int i = windowsList.size()-1; i > 0; i--)
				//		if (windowsList[i]->onFocus() == true)
				//		{
				//			/*Window *temp = windowsList[i];
				//			windowsList.erase(windowsList.begin() + i);
				//			windowsList.push_back(temp);*/
				//			UpdateWindow();
				//			return;
				//		}
				//	windowsList[0]->onFocus(true);
				//	UpdateWindow();
				//}
			}
			if (mouse != nullptr)
				mouse->_Render_func(&__Screenbuffer);
		}


		void TUI::ShowWindow()
		{
			_Rendr._UpdateChanged();
			__Screenbuffer.SwapBuffers();
		}

		void TUI::_GetMessage()
		{

		}

		void TUI::_DispatchMessage()
		{

		}

		unsigned short TUI::Width()
		{
			mSIZE size = ScreenBuffer::_GetScreenSize();
			return size.width;
		}

		unsigned short TUI::Height()
		{
			mSIZE size = ScreenBuffer::_GetScreenSize();
			return size.height;
		}

		void TUI::MouseCursor(void(*Hendlr)(BYTE,COORD), HANDLE stdIn)
		{
			std::thread mouse([Hendlr, stdIn]()->void {
				DWORD cNumRead, fdwMode, fdwOldMode, i;
				INPUT_RECORD irInBuf[300];
				GetConsoleMode(stdIn, &fdwOldMode);
				fdwMode = fdwOldMode | ENABLE_MOUSE_INPUT;
				SetConsoleMode(stdIn, fdwMode);
				while (true)
				{
					ReadConsoleInput(stdIn, irInBuf, 250, &cNumRead);
					for (i = 0; i < cNumRead; i++)
					{
						if (irInBuf[i].EventType == MOUSE_EVENT)
						{
							switch (irInBuf[i].Event.MouseEvent.dwEventFlags)
							{
							case MOUSE_MOVED:
								Hendlr(MOUSE_MOVED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								break;
							case DOUBLE_CLICK:
								Hendlr(MOUSE_DCLICKED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								break;
							case MOUSE_WHEELED:
								Hendlr(MOUSE_WHEELED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								break;
							default:
								if (irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
									Hendlr(MOUSE_RBCLICKED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								else
									if (irInBuf[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
										Hendlr(MOUSE_LBCLICKED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
									else
										Hendlr(MOUSE_BRELEAZED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								break;

							}
						}
					}
				}
			});
			mouse.detach();
		}
	}
}