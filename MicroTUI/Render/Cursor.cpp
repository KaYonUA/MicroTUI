#include "Cursor.h"


namespace MicroTUI
{
	Cursor::Cursor(){
		outStream = &std::cout;
		_Restore = false;
	}

	void Cursor::SetColor(ConsoleColor TextColor, ConsoleColor BackgroundColor){
		SetConsoleTextAttribute(hStdOut, (WORD)((BackgroundColor << 4) | TextColor));
	}

	void Cursor::SetColor(WORD Color){
		SetConsoleTextAttribute(hStdOut, Color);
	}


	void Cursor::SetCoord(COORD coord){
		SetConsoleCursorPosition(hStdOut,coord);
	}

	void Cursor::SaveCurAttr(){
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		oldTextCoord = csbi.dwCursorPosition;
	};

	void Cursor::Print(char letter, int x, int y, ConsoleColor TextColor, ConsoleColor BackgroundColor){
		SaveCurAttr();
		COORD cord = { x, y };
		SetColor(TextColor, BackgroundColor);
		if (_Restore == true)
			RestoreCurAttr();
	}

	void Cursor::Print(char *LPletter, int x, int y, ConsoleColor TextColor, ConsoleColor BackgroundColor){
		SaveCurAttr();
		COORD cord = { x, y };
		SetConsoleCursorPosition(hStdOut, cord);
		SetColor(TextColor, BackgroundColor);
		*outStream << LPletter;
		if (_Restore == true)
			RestoreCurAttr();
	}

	void Cursor::Print(int x, int y, Pixel attrib){
		COORD cord = { x, y };
		SetConsoleCursorPosition(hStdOut, cord);
		SetColor(attrib.pixelColor);
		*outStream << attrib.pixelLetter;
		if (_Restore == true)
			RestoreCurAttr();
	}

	void Cursor::GetPos(COORD *coord){
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		coord = &csbi.dwCursorPosition;
	}

	void Cursor::RestoreCurAttr(){
		SetCoord(oldTextCoord);
	}

	void Cursor::RestoreCursorAttributes(bool RCA){
		_Restore = RCA;
	}

	void Cursor::SetOutputBuffer(HANDLE hOut){
		hStdOut = hOut;
	}

	Cursor::~Cursor()
	{
	}
}