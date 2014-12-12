#pragma once
#ifndef CURSOR_H
#define CURSOR_H

#include "Color.hpp"

#include <Windows.h>
#include <iostream>


namespace MicroTUI
{
	class Cursor
	{
	public:
		Cursor(std::ostream &initOstream = std::cout);
		~Cursor();
		void Print(char letter, int x, int y, Color::Pixel::ConsoleColor TextColor = Color::Pixel::White, Color::Pixel::ConsoleColor BackgroundColor = Color::Pixel::Black);
		void Print(char *LPletter, int x, int y, Color::Pixel::ConsoleColor TextColor = Color::Pixel::White, Color::Pixel::ConsoleColor BackgroundColor = Color::Pixel::Black);
		void Print(int x, int y, Color::Pixel attrib);
		void GetPos(COORD *coord);
		void SetCoord(COORD coord);
		void RestoreCursorAttributes(bool RCA);
	private:
		void SetColor(Color::Pixel::ConsoleColor TextColor, Color::Pixel::ConsoleColor BackgroundColor);
		void SetColor(WORD Color);
		void SaveCurAttr();
		void RestoreCurAttr();

		bool _Restore;
		HANDLE hStdOut;
		Color::Pixel oldTextAtrr;
		std::ostream *outStream;
	};
}


#endif