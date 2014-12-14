#include "Cursor.h"


namespace MicroTUI
{
	Cursor::Cursor()
	{
		outStream = &std::cout;
		oldTextAtrr.Color = (WORD)((Color::Pixel::Black << 4) | Color::Pixel::White);
		oldTextAtrr.TextCoord.X = 0;
		oldTextAtrr.TextCoord.Y = 0;
		_Restore = false;
	}


	void Cursor::SetColor(Color::Pixel::ConsoleColor TextColor, Color::Pixel::ConsoleColor BackgroundColor)
	{
		SetConsoleTextAttribute(hStdOut, (WORD)((BackgroundColor << 4) | TextColor));
	}


	void Cursor::SetColor(WORD Color)
	{
		SetConsoleTextAttribute(hStdOut, Color);
	}


	void Cursor::SetCoord(COORD coord)
	{
		SetConsoleCursorPosition(hStdOut,coord);
	}


	void Cursor::SaveCurAttr()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		oldTextAtrr.TextCoord = csbi.dwCursorPosition;
		oldTextAtrr.Color = csbi.wAttributes;
	};


	void Cursor::Print(char letter, int x, int y, Color::Pixel::ConsoleColor TextColor, Color::Pixel::ConsoleColor BackgroundColor)
	{
		SaveCurAttr();
		COORD cord;
		cord.X = x;
		cord.Y = y;
		SetColor(TextColor, BackgroundColor);
		if (_Restore == true)
			RestoreCurAttr();
	}


	void Cursor::Print(char *LPletter, int x, int y, Color::Pixel::ConsoleColor TextColor, Color::Pixel::ConsoleColor BackgroundColor)
	{
		SaveCurAttr();
		COORD cord;
		cord.X = x;
		cord.Y = y;
		SetConsoleCursorPosition(hStdOut, cord);
		SetColor(TextColor, BackgroundColor);
		*outStream << LPletter;
		if (_Restore == true)
			RestoreCurAttr();
	}


	void Cursor::Print(int x, int y, Color::Pixel attrib)
	{
		//SaveCurAttr();
		COORD cord;
		cord.X = x;
		cord.Y = y;
		SetConsoleCursorPosition(hStdOut, cord);
		SetColor(attrib.Color);
		*outStream << attrib.letter;
		if (_Restore == true)
			RestoreCurAttr();
	}


	void Cursor::GetPos(COORD *coord)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		coord = &csbi.dwCursorPosition;
	}


	void Cursor::RestoreCurAttr()
	{
		SetCoord(oldTextAtrr.TextCoord);
		SetColor(oldTextAtrr.Color);
	}


	void Cursor::RestoreCursorAttributes(bool RCA)
	{
		_Restore = RCA;
	}


	void Cursor::SetOutputBuffer(HANDLE hOut)
	{
		hStdOut = hOut;
	}


	Cursor::~Cursor()
	{
	}
}