#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H
#pragma once

#include "Buffer.h"
#include <vector>

#define SB_NEWBUFFER		0x0101
#define SB_CURRENTBUFFER	0x0102
#define IR_SAVE				0x0103
#define IR_DONTSAVE			0x0104
#define CGUI_ERROR			0xFFFFFFFF

#define HS_LINE				0x00C4
#define HD_LINE				0x00CD
#define VS_LINE				0x00B3
#define VD_LINE				0x00BA
#define TLS_CORNER			0x00DA
#define TLD_CORNER			0x00C9
#define TRS_CORNER			0x00BF
#define TRD_CORNER			0x00BB
#define BLS_CORNER			0x00C0
#define BLD_CORNER			0x00C8
#define BRS_CORNER			0x00D9
#define BRD_CORNER			0x00BC

namespace MicroTUI
{
	class ScreenBuffer
	{
	public:
		ScreenBuffer();
		void Set(WORD _SwBuff,int x, int y, Color::Pixel attrib);
		Color::Pixel Get(WORD _SwBuff,int x, int y);
		COORD GetBuffersSize(WORD _SwBuff);
		void _GetBuffersSize(COORD *coord,WORD _SwBuff);
		std::vector<COORD> GenUpdateVector();
		void _GenUpdateVector(std::vector<COORD> *LPVector);
		static mSIZE _GetScreenSize();
		static void GetScreenSize(COORD * c);
		bool PixelChanged(int x,int y);
		void SwapBuffers();
		bool isResized(WORD _ResSw);
		void Resize(int Width, int Height);
		void ClearBuffer();
		void ClearScreen();
		void Fill(Color::Pixel pixel);

		void Rectangle(int x, int y, int width, int height, Color::Pixel Pix);
		void LineHorisontal(int y, int Sx, int Ex, bool isDouble, COLOR cr);
		void LineVertical(int y, int Sx, int Ex, bool isDouble, COLOR cr);
		void Label(int x, int y, char l, COLOR cr);
		void Label(int x, int y, const char *const str, unsigned int length, COLOR cr);
		void Label(int x, int y, std::string str, COLOR cr);
		void Label(int x, int y, std::string *str, COLOR cr);
		~ScreenBuffer();
	private:
		COORD ScreenSize;
		COORD CBuffersSize, NBuffersSize;
		Buffer CurrentBuffer;
		Buffer NewBuffer;
		std::vector<COORD> UpdateVector;
	};
}


#endif