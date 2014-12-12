#include "Buffer.h"

namespace MicroTUI
{

	Buffer::Buffer()
	{

	}

	void Buffer::Clear(Color::Pixel attribut)
	{
		for (size_t height = 0; height <= ScreenHeight; height++)
		for (size_t width = 0; width <= ScreenWidth; width++)
			buffer[width][height] = attribut;
	}

	Color::Pixel Buffer::Get(int x, int y)
	{
		if (x >= ScreenWidth || y >= ScreenHeight)
			return Color::Pixel('\b');
		else
			return buffer[x][y];
	}

	void Buffer::Set(Color::Pixel attr, int x, int y)
	{
		if (x <= ScreenWidth || y <= ScreenHeight)
			if (attr.Color == Color::_Transparent)
				buffer[x][y].letter = attr.letter;
			else
				buffer[x][y] = attr;
	}

	Color::Pixel **Buffer::BufferCopy()
	{
		return buffer;
	}

	void Buffer::SetBuffer(Color::Pixel **buffer)
	{
		this->buffer = buffer;
	}

	void Buffer::Resize(int Width, int Height)
	{
		/*if (ScreenWidth > 0 && ScreenWidth<5000)
			delete[] buffer;*/
		ScreenWidth = Width;
		ScreenHeight = Height;
		buffer = new Color::Pixel*[ScreenWidth];
		for (size_t h = 0; h <= ScreenWidth; h++)
			buffer[h] = ArrayInit<Color::Pixel>(ScreenHeight, 
			Color::Pixel(' ', Color::Pixel::ColorToWord(Color::Pixel::White, Color::Pixel::Black),
			EMPTY));
	}

	Buffer::~Buffer()
	{
		/*for (size_t h = 0; h < ScreenHeight; h++)
			delete[] buffer[h];*/
		delete[] buffer;
	}
}