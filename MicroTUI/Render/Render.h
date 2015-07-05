#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "ScreenBuffer.h"
#include "Cursor.h"

namespace MicroTUI
{
	class Render
	{
	public:
		Render() {
			curs.RestoreCursorAttributes(false);
			CONSOLE_CURSOR_INFO structCursorInfo;
			GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
			structCursorInfo.bVisible = FALSE;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
			curs.hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		}
		Render(ScreenBuffer *scrbuffer){
			ScrBuff = scrbuffer;
			curs.hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

		}
		void Connect(ScreenBuffer *scrbuffer);
		void UpdateChanged();
		void _UpdateChanged();
		void UpdateAll();
		void ClearScreen();
		~Render();
	private:
		ScreenBuffer *ScrBuff;
		Cursor curs;
	};
}


#endif

