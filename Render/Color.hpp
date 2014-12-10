#ifndef COLOR_HPP
#define COLOR_HPP
#include <Windows.h>
#include "Size.hpp"

#define EMPTY COORD()

namespace MicroTUI
{
	typedef char LETTER;
	typedef WORD COLOR;
	namespace Color
	{
		struct Pixel
		{
			enum ConsoleColor
			{
				Black = 0,
				Blue = 1,
				Green = 2,
				Cyan = 3,
				Red = 4,
				Magenta = 5,
				Brown = 6,
				LightGray = 7,
				DarkGray = 8,
				LightBlue = 9,
				LightGreen = 10,
				LightCyan = 11,
				LightRed = 12,
				LightMagenta = 13,
				Yellow = 14,
				White = 15
			};
			Pixel()
			{
				Color = ColorToWord(White, Black);
			}
			Pixel(LETTER let, WORD col = ColorToWord(White, Black), COORD coor = EMPTY)
			{
				letter = let;
				Color = col;
				TextCoord = coor;
			}
			static WORD ColorToWord(ConsoleColor textColor, ConsoleColor backgroundColor)
			{
				return (WORD)((backgroundColor << 4) | textColor);
			}
			bool operator==(Pixel obj)
			{
				if (this->Color == obj.Color && this->letter == obj.letter)
					return true;
				else
					return false;
			}
			bool operator!=(Pixel obj)
			{
				return !(*this == obj);
			}
			COLOR Color;
			COORD TextCoord;
			LETTER letter;
		};
	}
}


#endif