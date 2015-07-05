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
			buffer(new Pixel*[copy.ScreenWidth])
		{
			for (int h = 0; h <= ScreenWidth; h++)
				buffer[h] = ArrayInit<Pixel>(ScreenHeight,Pixel(' ', cWhite, cBlack));
			for (int h = 0; h <= ScreenWidth; h++)
				memcpy(buffer[h], copy.buffer[h], copy.ScreenHeight);
		}
		~Buffer();
		Pixel Get(int x, int y);
		void Set(Pixel attr, int x, int y);
		Pixel **BufferCopy();
		void SetBuffer(Pixel **buffer);
		void Resize(int Width, int Height);
		void Clear(Pixel attribut = Pixel(' ',cWhite, cBlack));
		void Copy(const Buffer& copy){
			for (int h = 0; h <= ScreenWidth; h++)
				memcpy(buffer[h],copy.buffer[h], sizeof(Pixel)*copy.ScreenHeight);
		}
		int ScreenWidth;
		int ScreenHeight;
	private:
		Pixel **buffer;
		
	};
}


#endif