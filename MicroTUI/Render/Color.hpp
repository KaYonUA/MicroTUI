#ifndef COLOR_HPP
#define COLOR_HPP
#include <Windows.h>
#include "Size.hpp"

namespace MicroTUI{
	enum ConsoleColor{
		cBlack			= 0,
		cBlue			= 1,
		cGreen			= 2,
		cCyan			= 3,
		cRed			= 4,
		cMagenta		= 5,
		cBrown			= 6,
		cLightGray		= 7,
		cDarkGray		= 8,
		cLightBlue		= 9,
		cLightGreen		= 10,
		cLightCyan		= 11,
		cLightRed		= 12,
		cLightMagenta	= 13,
		cYellow			= 14,
		cWhite			= 15,
		cTransparent	= 16
	};

	typedef unsigned short COLOR;

	struct Pixel{
		Pixel(){ pixelColor = ColorToWord(cWhite, cBlack); }
		Pixel(char letter, ConsoleColor textColor = cBlack, ConsoleColor backgroundColor = cWhite){
			pixelLetter = letter;
			pixelColor = ColorToWord(textColor, backgroundColor);
		}
		static WORD ColorToWord(ConsoleColor textColor, ConsoleColor backgroundColor){
			return (WORD)((backgroundColor << 4) | textColor);
		}
		static ConsoleColor wordToBackgroundColor(WORD color){ return (ConsoleColor)(color >> 4); }
		static ConsoleColor wordToTextColor(WORD color){ return (ConsoleColor)(color & 15); }
		static Pixel pixelGen(char letter, ConsoleColor textColor = cBlack, ConsoleColor backgroundColor = cWhite){
			return Pixel(letter, textColor, backgroundColor);
		}
		bool operator==(Pixel obj){
			if (this->pixelColor == obj.pixelColor && this->pixelLetter == obj.pixelLetter)
				return true;
			else
				return false;
		}
		bool operator!=(Pixel obj){ return !(*this == obj); }

		COLOR pixelColor;
		char pixelLetter;
	};
}


#endif