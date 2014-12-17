#include "TUI.h"

namespace MicroTUI
{
	namespace GUI
	{

		TUI::TUI()
		{
			BackgroundColor = Color::Pixel::ColorToWord(Color::Pixel::Black, Color::Pixel::LightBlue);
			_Rendr.Connect(&__Screenbuffer);
		}

		void TUI::AddWindow(Window *window)
		{
			windowsList.push_back(window);
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

		void TUI::MouseCursor(void(*Hendlr)(BYTE))
		{
			std::thread mouse([Hendlr]()->void {
				HANDLE _ConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
				HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
				DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
				INPUT_RECORD irInBuf[128];
				GetConsoleMode(hStdin, &fdwSaveOldMode);
				fdwMode = fdwSaveOldMode | ENABLE_MOUSE_INPUT;
				SetConsoleMode(hStdin, fdwMode);
				while (true)
				{
					ReadConsoleInput(hStdin, irInBuf, 250, &cNumRead);
					for (i = 0; i < cNumRead; i++)
					{
						if (irInBuf[i].EventType == MOUSE_EVENT)
						{
							switch (irInBuf[i].Event.MouseEvent.dwEventFlags)
							{
							case MOUSE_MOVED:
								Hendlr(1);
								break;
							case DOUBLE_CLICK:
								Hendlr(2);
								break;
							case MOUSE_WHEELED:
								Hendlr(3);
								break;
							default:
								if (irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
								{
									Hendlr(4);
								}
								else
								if (irInBuf[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
								{
									Hendlr(5);
								}
								else
									Hendlr(6);
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
