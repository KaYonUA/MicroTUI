#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include "Color.hpp"
#include <algorithm>

namespace MicroTUI
{
	template<typename T>
	inline T* ArrayInit(size_t lenght, T init)
	{
		T* temp = new T[lenght];
		for (size_t l = 0; l < lenght; l++)
			temp[l] = init;
		return temp;
	}

	class Buffer
	{
	public:
		Buffer();
		Buffer(const Buffer& copy)
			: ScreenWidth(copy.ScreenWidth),
			ScreenHeight(copy.ScreenHeight),
			buffer(new Color::Pixel*[copy.ScreenWidth])
		{
			for (size_t h = 0; h <= ScreenWidth; h++)
				buffer[h] = ArrayInit<Color::Pixel>(ScreenHeight,
				Color::Pixel(' ', Color::Pixel::ColorToWord(Color::Pixel::White, Color::Pixel::Black),
				EMPTY));
			for (size_t h = 0; h <= ScreenWidth; h++)
				std::copy(copy.buffer[h], copy.buffer[h] + copy.ScreenHeight, buffer[h]);
		}
		~Buffer();
		Color::Pixel Get(int x, int y);
		void Set(Color::Pixel attr, int x, int y);
		Color::Pixel **BufferCopy();
		void SetBuffer(Color::Pixel **buffer);
		void Resize(int Width, int Height);
		void Clear(Color::Pixel attribut = Color::Pixel(' ', Color::Pixel::ColorToWord(
			Color::Pixel::White, Color::Pixel::Black), EMPTY));
		void Copy(const Buffer& copy)
		{
			for (size_t h = 0; h <= ScreenWidth; h++)
				std::copy(copy.buffer[h], copy.buffer[h] + copy.ScreenHeight, buffer[h]);
		}
		unsigned int ScreenWidth;
		unsigned int ScreenHeight;
	private:
		Color::Pixel **buffer;
		
	};
}


#endif