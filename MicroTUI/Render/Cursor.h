#pragma once
#ifndef CURSOR_H
#define CURSOR_H

#include "Color.hpp"

#include <Windows.h>
#include <iostream>


namespace MicroTUI
{
	class Cursor{
	public:
		Cursor();
		~Cursor();
		void Print(char letter, int x, int y, ConsoleColor TextColor = cWhite, ConsoleColor BackgroundColor = cBlack);
		void Print(char *LPletter, int x, int y, ConsoleColor TextColor = cWhite, ConsoleColor BackgroundColor = cBlack);
		void Print(int x, int y, Pixel attrib);
		void SetOutputBuffer(HANDLE hOut);
		void GetPos(COORD *coord);
		void SetCoord(COORD coord);
		void RestoreCursorAttributes(bool RCA);

		HANDLE hStdOut;
	private:
		void SetColor(ConsoleColor TextColor, ConsoleColor BackgroundColor);
		void SetColor(WORD Color);
		void SaveCurAttr();
		void RestoreCurAttr();

		bool _Restore;
		COORD oldTextCoord;
		std::ostream *outStream;
	};
}


#endif