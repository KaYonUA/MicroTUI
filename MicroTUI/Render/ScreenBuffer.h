#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H
#pragma once

#include "Buffer.h"
#include <vector>

#define SB_NEWBUFFER		0x0101
#define SB_CURRENTBUFFER	0x0102
#define IR_SAVE				0x0103
#define IR_DONTSAVE			0x0104
#define CGUI_ERROR			0xFFFF

#define HS_LINE				char(0x00C4)
#define HD_LINE				char(0x00CD)
#define VS_LINE				char(0x00B3)
#define VD_LINE				char(0x00BA)
#define TLS_CORNER			char(0x00DA)
#define TLD_CORNER			char(0x00C9)
#define TRS_CORNER			char(0x00BF)
#define TRD_CORNER			char(0x00BB)
#define BLS_CORNER			char(0x00C0)
#define BLD_CORNER			char(0x00C8)
#define BRS_CORNER			char(0x00D9)
#define BRD_CORNER			char(0x00BC)
#define BRDtS_CORNER		char(0x00BD)
#define BLDtS_CORNER		char(0x00D4)
#define TRDtS_CORNER		char(0x00B8)
#define TLDtS_CORNER		char(0x00D6)
#define BRStD_CORNER		char(0x00BE)
#define BLStD_CORNER		char(0x00D3)
#define TRStD_CORNER		char(0x00B7)
#define TLStD_CORNER		char(0x00D5)

namespace MicroTUI
{
	class ScreenBuffer
	{
	public:
		ScreenBuffer();
		void Set(WORD _SwBuff,int x, int y, Pixel attrib);
		Pixel Get(WORD _SwBuff,int x, int y);
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
		void Fill(Pixel pixel);

		void Rectangle(int x, int y, int width, int height, Pixel Pix);
		void LineHorisontal(int y, int Sx, int Ex, bool isDouble, ConsoleColor text,ConsoleColor background);
		void LineVertical(int x, int Sy, int Ey, bool isDouble, ConsoleColor text, ConsoleColor background);
		void Lable(int x, int y, char l, ConsoleColor text, ConsoleColor background);
		void Lable(int x, int y, const char *const str, unsigned int length, ConsoleColor text, ConsoleColor background);
		void Lable(int x, int y, std::string str, ConsoleColor text, ConsoleColor background);
		void Lable(int x, int y, std::string *str, ConsoleColor text, ConsoleColor background);

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