#include "ScreenBuffer.h"
#include <iostream>

namespace MicroTUI
{
	ScreenBuffer::ScreenBuffer(){
		alphaChannel = false;
		mSIZE size = _GetScreenSize();
		Resize(size.width, size.height);
	}

	void ScreenBuffer::Set(WORD _SwBuff,int x, int y, Pixel attrib){
		switch (_SwBuff){
		case SB_NEWBUFFER:
			if (alphaChannel){
				ConsoleColor newTextColor;
				ConsoleColor newBackgroundColor;
				if (Pixel::wordToTextColor(attrib.pixelColor) == cTransparent)
					newTextColor = Pixel::wordToTextColor(NewBuffer.Get(x, y).pixelColor);
				else
					newTextColor = Pixel::wordToTextColor(attrib.pixelColor);
				if (Pixel::wordToBackgroundColor(attrib.pixelColor) == cTransparent){
					if (attrib.pixelLetter == ' '){
						attrib.pixelLetter = NewBuffer.Get(x, y).pixelLetter;
						newTextColor = Pixel::wordToTextColor(NewBuffer.Get(x, y).pixelColor);
					}
					newBackgroundColor = Pixel::wordToBackgroundColor(NewBuffer.Get(x, y).pixelColor);
				}
				else
					newBackgroundColor = Pixel::wordToBackgroundColor(attrib.pixelColor);
				attrib.pixelColor = Pixel::ColorToWord(newTextColor, newBackgroundColor);
			}
			NewBuffer.Set(attrib, x, y);
			break;
		case SB_CURRENTBUFFER:
			CurrentBuffer.Set(attrib, x, y);
			break;
		}
	}

	Pixel ScreenBuffer::Get(WORD _SwBuff, int x, int y){
		switch (_SwBuff)
		{
		case SB_NEWBUFFER:
			return NewBuffer.Get(x, y);
			break;
		case SB_CURRENTBUFFER:
			return CurrentBuffer.Get(x, y);
			break;
		default:
			return Pixel::pixelGen('~');
			break;
		}
	}

	void ScreenBuffer::SwapBuffers(){
		CurrentBuffer.Copy(NewBuffer);
	}

	COORD ScreenBuffer::GetBuffersSize(WORD _SwBuff){
		COORD temp;
		switch (_SwBuff){
		case SB_NEWBUFFER:
			temp.X = NewBuffer.ScreenWidth;
			temp.Y = NewBuffer.ScreenHeight;
			break;
		case SB_CURRENTBUFFER :
			temp.X = CurrentBuffer.ScreenWidth;
			temp.Y = CurrentBuffer.ScreenHeight;
			break;
		default:
			temp.X = ERROR;
			temp.Y = ERROR;
			break;
		}
		return temp;
	}

	void ScreenBuffer::_GetBuffersSize(COORD *coord, WORD _SwBuff){
		switch (_SwBuff){
		case SB_NEWBUFFER:
			coord->X = NewBuffer.ScreenWidth;
			coord->Y = NewBuffer.ScreenHeight;
			break;
		case SB_CURRENTBUFFER:
			coord->X = CurrentBuffer.ScreenWidth;
			coord->Y = CurrentBuffer.ScreenHeight;
			break;
		default:
			break;
		}
		
	}

	bool ScreenBuffer::isResized(WORD _ResSw){
		mSIZE newSize = _GetScreenSize();
		if (newSize.width == ScreenSize.X && newSize.height == ScreenSize.Y)
			return false;
		else{
			if (_ResSw == IR_SAVE){
				ScreenSize.X = newSize.width;
				ScreenSize.Y = newSize.height;
			}
			return true;
		}
	}

	std::vector<COORD> ScreenBuffer::GenUpdateVector(){
		COORD temp;
		UpdateVector.clear();
		for (SHORT height = 0; height <= NBuffersSize.Y; height++){
			for (SHORT width = 0; width <= NBuffersSize.X; width++)
			if (NewBuffer.Get(width, height) != CurrentBuffer.Get(width, height)){
				temp.X = width; temp.Y = height;
				UpdateVector.push_back(temp);
			}
			printf("1\n");
		}
		return UpdateVector;
	}

	void ScreenBuffer::Resize(int Width, int Height){
		NewBuffer.Resize(Width, Height);
		CurrentBuffer.Resize(Width, Height);
	}

	void ScreenBuffer::GetScreenSize(COORD *c){
		CONSOLE_SCREEN_BUFFER_INFO temp;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);
		c->X = temp.srWindow.Right+1;
		c->Y = temp.srWindow.Bottom;
	}

	mSIZE ScreenBuffer::_GetScreenSize(){
		CONSOLE_SCREEN_BUFFER_INFO temp;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);
		mSIZE returned;
		returned.width = temp.srWindow.Right+1;
		returned.height = temp.srWindow.Bottom+1;
		return returned;
	}

	void ScreenBuffer::_GenUpdateVector(std::vector<COORD> *LPVector){
		COORD temp;
		UpdateVector.clear();
		
		for (SHORT height = 0; height < NBuffersSize.X; height++)
		for (SHORT width = 0; width < NBuffersSize.Y; width++)
		if (NewBuffer.Get(height, width) != CurrentBuffer.Get(height, width)){
			temp.X = height; temp.Y = width;
			LPVector->push_back(temp);
		}
	}

	bool ScreenBuffer::PixelChanged(int x, int y){
		if (NewBuffer.Get(x, y) == CurrentBuffer.Get(x, y))
			return false;
		else
			return true;
	}

	void ScreenBuffer::Fill(Pixel pixel){
		NewBuffer.Clear(pixel);
	}

	void ScreenBuffer::Rectangle(int x, int y, int width, int height, Pixel Pix){
		for (int start_y = 0; start_y < height; start_y++)
		for (int start_x = 0; start_x < width; start_x++)
			Set(SB_NEWBUFFER, start_x + x, start_y + y, Pix);
	}

	void ScreenBuffer::LineHorisontal(int y, int Sx, int Ex, bool isDouble, ConsoleColor text, ConsoleColor background){
		int length = Ex-Sx;
		if (length < 0)
			for (int x = 0; x > length; x--)
				Set(SB_NEWBUFFER, Ex + x, y, Pixel::pixelGen(isDouble == true ? HD_LINE : HS_LINE, text, background));
		else
			for (int x = 0; x < length; x++)
				Set(SB_NEWBUFFER, Sx + x, y, Pixel::pixelGen(isDouble == true ? HD_LINE : HS_LINE, text, background));
	}

	void ScreenBuffer::LineVertical(int x, int Sy, int Ey, bool isDouble, ConsoleColor text, ConsoleColor background){
		int length = Ey-Sy;
		if (length < 0)
			for (int y = 0; y > length; y--)
				Set(SB_NEWBUFFER, x, Ey + y, Pixel::pixelGen(isDouble == true ? VD_LINE : VS_LINE, text, background));
		else
			for (int y = 0; y < length; y++)
				Set(SB_NEWBUFFER, x, Sy + y, Pixel::pixelGen(isDouble == true ? VD_LINE : VS_LINE, text, background));
	}

	void ScreenBuffer::Lable(int x, int y, char letter, ConsoleColor text, ConsoleColor background){
		Set(SB_NEWBUFFER, x, y, Pixel::pixelGen(letter, text, background));
	}

	void ScreenBuffer::Lable(int x, int y, const char *const str, unsigned int length, ConsoleColor text, ConsoleColor background){
		for (unsigned int l = 0; l < length; l++)
			if(str[l]!= '\0' && str[l] != '\n')
				Set(SB_NEWBUFFER, x + l, y, Pixel::pixelGen(str[l], text, background));
	}

	void ScreenBuffer::Lable(int x, int y, std::string str, ConsoleColor text, ConsoleColor background){
		for (int l = 0; l < int(str.length()); l++)
			if(str.at(l) != '\0' && str.at(l) != '\n')
				Set(SB_NEWBUFFER, x + l, y, Pixel::pixelGen(str.at(l), text, background));
	}

	void ScreenBuffer::Lable(int x, int y, std::string *str, ConsoleColor text, ConsoleColor background){
		for (int l = 0; l < int(str->length()); l++)
			if(str->at(l) != '\0' && str->at(l) != '\n')
				Set(SB_NEWBUFFER, x + l, y, Pixel::pixelGen(str->at(l), text, background));
	}

	void ScreenBuffer::ClearBuffer(){
		NewBuffer.Clear();
	}

	void ScreenBuffer::ClearScreen(){
		NewBuffer.Clear();
	}

	ScreenBuffer::~ScreenBuffer()
	{
	}
}