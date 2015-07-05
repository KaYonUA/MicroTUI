#include "TUI.h"

namespace MicroTUI
{
	TUI::TUI(int width, int height, char * title){
		backgroundColor = cLightBlue;
		textColor = cBlack;
		mouse = nullptr;
		m_clickedWindow = nullptr;
		setTitle(title);
		resizeConsole(width, height);
		__Screenbuffer = new ScreenBuffer;
		_Rendr.Connect(__Screenbuffer);
	}

	void TUI::AddWindow(Window *window){
		windowsList.push_back(window);
	}

	void TUI::SetMouse(Mouse * mouse){
		this->mouse = mouse;
	}

	void TUI::ClickMouse(int x, int y, bool _double){
		for (int i = (int)windowsList.size() - 1; i >= 0; i--){
			if ((int)windowsList[i]->WindowCoord.X <= x && (int)windowsList[i]->WindowCoord.Y <= y &&
				x <= (int)windowsList[i]->WindowCoord.X + (int)windowsList[i]->WindowSize.width &&
				y <= (int)windowsList[i]->WindowCoord.Y + (int)windowsList[i]->WindowSize.height)
			{
				windowsList[i]->_h_lclicked(x - windowsList[i]->WindowCoord.X,
					y - windowsList[i]->WindowCoord.Y, _double);
				m_clickedWindow = windowsList[i];
				break;
			}
		}
	}

	void TUI::ReleaseMouse(int x, int y){
		if (m_clickedWindow != nullptr){
			m_clickedWindow->_h_lreleased(x, y);
			m_clickedWindow = nullptr;
		}
	}

	void TUI::moveMouse(int x, int y){
		if (m_clickedWindow != nullptr){
			m_clickedWindow->_h_lmoved(x, y);
		}
	}

	void TUI::UpdateWindow()
	{
		__Screenbuffer->Fill(Pixel::pixelGen(' ', textColor, backgroundColor));
		if (!windowsList.empty()){
			for (int i = 0; i < (int)windowsList.size(); i++)
				windowsList[i]->_Render_func(__Screenbuffer);
		}
		if (mouse != nullptr)
			mouse->_Render_func(__Screenbuffer);
	}


	void TUI::ShowWindow(){
		_Rendr._UpdateChanged();
		__Screenbuffer->SwapBuffers();
	}

	void TUI::_GetMessage(){

	}

	void TUI::_DispatchMessage(){

	}

	unsigned short TUI::Width(){
		mSIZE size = ScreenBuffer::_GetScreenSize();
		return size.width;
	}

	unsigned short TUI::Height(){
		mSIZE size = ScreenBuffer::_GetScreenSize();
		return size.height;
	}

	void TUI::MouseCursor(void(*Hendlr)(BYTE, COORD), HANDLE stdIn){
		std::thread mouse([Hendlr, stdIn, this]()->void {
			DWORD cNumRead, fdwMode, fdwOldMode, i;
			INPUT_RECORD irInBuf[5];
			GetConsoleMode(stdIn, &fdwOldMode);
			fdwMode = fdwOldMode | ENABLE_MOUSE_INPUT;
			SetConsoleMode(stdIn, fdwMode);
			while (true)
			{
				ReadConsoleInput(stdIn, irInBuf, 3, &cNumRead);
				for (i = 0; i < cNumRead; i++)
				{
					if (irInBuf[i].EventType == MOUSE_EVENT)
					{
						switch (irInBuf[i].Event.MouseEvent.dwEventFlags)
						{
						case MOUSE_MOVED:
							Hendlr(MOUSE_MOVED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
							moveMouse(irInBuf[i].Event.MouseEvent.dwMousePosition.X,
								irInBuf[i].Event.MouseEvent.dwMousePosition.Y);
							break;
						case DOUBLE_CLICK:
							Hendlr(MOUSE_DCLICKED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
							ClickMouse(irInBuf[i].Event.MouseEvent.dwMousePosition.X,
								irInBuf[i].Event.MouseEvent.dwMousePosition.Y, true);
							break;
						case MOUSE_WHEELED:
							Hendlr(MOUSE_WHEELED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
							break;
						default:
							if (irInBuf[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED){
								Hendlr(MOUSE_RBCLICKED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								ClickMouse(irInBuf[i].Event.MouseEvent.dwMousePosition.X,
									irInBuf[i].Event.MouseEvent.dwMousePosition.Y, false);
							}
							else
							if (irInBuf[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
								Hendlr(MOUSE_LBCLICKED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
							else{
								Hendlr(MOUSE_BRELEAZED_, irInBuf[i].Event.MouseEvent.dwMousePosition);
								ReleaseMouse(irInBuf[i].Event.MouseEvent.dwMousePosition.X,
									irInBuf[i].Event.MouseEvent.dwMousePosition.Y);
							}
							break;

						}
					}
				}
			}
		});
		mouse.detach();
	}

	void TUI::setTitle(char  * _str){
		SetConsoleTitleA(_str);
		consoleTitle = new char[strlen(_str)];
		memcpy(consoleTitle, _str, strlen(_str) + 1);
	}

	void TUI::resizeConsole(int width, int height){
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { width, height + 3 });
		MoveWindow(FindWindowA(NULL, consoleTitle), 1, 1, 3000, height * 12, true);
	}
}
