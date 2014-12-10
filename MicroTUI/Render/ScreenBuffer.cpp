#include "ScreenBuffer.h"
//#include <iostream>

namespace MicroTUI
{
	ScreenBuffer::ScreenBuffer()
	{
		mSIZE size = _GetScreenSize();
		Resize(size.width, size.height);
	}

	void ScreenBuffer::Set(WORD _SwBuff,int x, int y, Color::Pixel attrib)
	{
		switch (_SwBuff)
		{
		case SB_NEWBUFFER:
			NewBuffer.Set(attrib, x, y);
			break;
		case SB_CURRENTBUFFER:
			CurrentBuffer.Set(attrib, x, y);
			break;
		}
	}

	Color::Pixel ScreenBuffer::Get(WORD _SwBuff,int x, int y)
	{
		switch (_SwBuff)
		{
		case SB_NEWBUFFER:
			return NewBuffer.Get(x, y);
			break;
		case SB_CURRENTBUFFER:
			return CurrentBuffer.Get(x, y);
			break;
		}
	}

	void ScreenBuffer::SwapBuffers()
	{
		CurrentBuffer.Copy(NewBuffer);
	}

	COORD ScreenBuffer::GetBuffersSize(WORD _SwBuff)
	{
		COORD temp;
		switch (_SwBuff)
		{
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

	void ScreenBuffer::_GetBuffersSize(COORD *coord, WORD _SwBuff)
	{
		switch (_SwBuff)
		{
		case SB_NEWBUFFER:
			coord->X = NewBuffer.ScreenWidth;
			coord->Y = NewBuffer.ScreenHeight;
			break;
		case SB_CURRENTBUFFER:
			coord->X = CurrentBuffer.ScreenWidth;
			coord->Y = CurrentBuffer.ScreenHeight;
			break;
		default:
			coord->X = CGUI_ERROR;
			coord->Y = CGUI_ERROR;
			break;
		}
		
	}

	bool ScreenBuffer::isResized(WORD _ResSw)
	{
		mSIZE newSize = _GetScreenSize();
		if (newSize.width == ScreenSize.X && newSize.height == ScreenSize.Y)
			return false;
		else
		{
			if (_ResSw == IR_SAVE)
			{
				ScreenSize.X = newSize.width;
				ScreenSize.Y = newSize.height;
			}
			return true;
		}
	}

	std::vector<COORD> ScreenBuffer::GenUpdateVector()
	{
		COORD temp;
		UpdateVector.clear();
		//Test na ohibku..
		for (size_t height = 0; height <= NBuffersSize.Y; height++)
		{
			for (size_t width = 0; width <= NBuffersSize.X; width++)
			if (NewBuffer.Get(width, height) != CurrentBuffer.Get(width, height))
			{
				temp.X = width; temp.Y = height;
				UpdateVector.push_back(temp);
			}
			printf("1\n");
		}
		return UpdateVector;
	}

	void ScreenBuffer::Resize(int Width, int Height)
	{
		NewBuffer.Resize(Width, Height);
		CurrentBuffer.Resize(Width, Height);
	}

	void ScreenBuffer::GetScreenSize(COORD *c)
	{
		CONSOLE_SCREEN_BUFFER_INFO temp;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);
		c->X = temp.srWindow.Right+1;
		c->Y = temp.srWindow.Bottom;
	}

	mSIZE ScreenBuffer::_GetScreenSize()
	{
		CONSOLE_SCREEN_BUFFER_INFO temp;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);
		mSIZE returned;
		returned.width = temp.srWindow.Right+1;
		returned.height = temp.srWindow.Bottom;
		return returned;
	}

	void ScreenBuffer::_GenUpdateVector(std::vector<COORD> *LPVector)
	{
		COORD temp;
		UpdateVector.clear();
		//Test...
		for (size_t height = 0; height < NBuffersSize.X; height++)
		for (size_t width = 0; width < NBuffersSize.Y; width++)
		if (NewBuffer.Get(height, width) != CurrentBuffer.Get(height, width))
		{
			temp.X = height; temp.Y = width;
			LPVector->push_back(temp);
		}
	}

	bool ScreenBuffer::PixelChanged(int x, int y)
	{
		if (NewBuffer.Get(x, y) == CurrentBuffer.Get(x, y))
			return false;
		else
			return true;
	}

	void ScreenBuffer::Fill(Color::Pixel pixel)
	{
		NewBuffer.Clear(pixel);
		//CurrentBuffer.Clear(pixel);
		//NewBuffer.Clear(pixel);
	}

	void ScreenBuffer::Rectangle(int x, int y, int width, int height, Color::Pixel Pix)
	{
		for (int start_y = 0; start_y < height; start_y++)
		for (int start_x = 0; start_x < width; start_x++)
			NewBuffer.Set(Pix, start_x + x, start_y + y);
	}

	void ScreenBuffer::LineHorisontal(int y, int Sx, int Ex, bool isDouble, COLOR cr)
	{
		int length = Ex-Sx;
		if (length < 0)
			for (int x = 0; x > length; x--)
				NewBuffer.Set(Color::Pixel(isDouble == true ? HD_LINE : HS_LINE, cr), Ex + x, y);
		else
			for (int x = 0; x < length; x++)
				NewBuffer.Set(Color::Pixel(isDouble == true ? HD_LINE : HS_LINE, cr), Sx + x, y);
	}

	void ScreenBuffer::LineVertical(int x, int Sy, int Ey, bool isDouble, COLOR cr)
	{
		int length = Ey-Sy;
		if (length < 0)
			for (int y = 0; y > length; y--)
				NewBuffer.Set(Color::Pixel(isDouble == true ? VD_LINE : VS_LINE, cr), x, Ey + y );
		else
			for (int y = 0; y < length; y++)
				NewBuffer.Set(Color::Pixel(isDouble == true ? VD_LINE : VS_LINE, cr),x, Sy + y);
	}

	void ScreenBuffer::Label(int x, int y, char l, COLOR cr)
	{
		NewBuffer.Set(Color::Pixel(l, cr), x, y);
	}

	void ScreenBuffer::Label(int x, int y, const char *const str,unsigned int length, COLOR cr)
	{
		for (int l = 0; l < length; l++)
			NewBuffer.Set(Color::Pixel(str[l], cr), x + l, y);
	}

	void ScreenBuffer::Label(int x, int y, std::string str, COLOR cr)
	{
		for (int l = 0; l < str.length(); l++)
			NewBuffer.Set(Color::Pixel(str.at(l), cr), x + l, y);
	}

	void ScreenBuffer::Label(int x, int y, std::string *str, COLOR cr)
	{
		for (int l = 0; l < str->length(); l++)
			NewBuffer.Set(Color::Pixel(str->at(l), cr), x + l, y);
	}

	void ScreenBuffer::ClearBuffer()
	{
		NewBuffer.Clear();
	}

	void ScreenBuffer::ClearScreen()
	{
		NewBuffer.Clear();
	}

	ScreenBuffer::~ScreenBuffer()
	{
	}
}