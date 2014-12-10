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

		void TUI::AddWindow(Window &window)
		{
			windowsList.push_back(window);
		}

		void TUI::UpdateWindow()
		{
			__Screenbuffer.Fill(Color::Pixel(' ', BackgroundColor));
			if (!windowsList.empty())
			{
				//if(windowsList.back().onFocus() == true)
				for (std::list<Window>::iterator iterat = windowsList.begin(); iterat != windowsList.end(); iterat++)
						iterat->_Render_func(&__Screenbuffer);
				/*else
				for (std::list<Window>::iterator iterat = windowsList.begin(); iterat != windowsList.end(); iterat++)
				if (iterat->onFocus() == true)
					windowsList.push_back(windowsList.erase(iterat));*/
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
