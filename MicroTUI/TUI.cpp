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
	}
}
