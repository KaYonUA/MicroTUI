#include "Buffer.h"

namespace MicroTUI
{

	Buffer::Buffer(){

	}

	void Buffer::Clear(Pixel attribut){
		for (int height = 0; height <= ScreenHeight; height++)
		for (int width = 0; width <= ScreenWidth; width++)
			buffer[width][height] = attribut;
	}

	Pixel Buffer::Get(int x, int y){
		if (x < ScreenWidth && x >= 0){
			if (y < ScreenHeight && y >= 0)
				return buffer[x][y];
		}
		return Pixel('\b');
	}

	void Buffer::Set(Pixel attr, int x, int y){
		if (x < ScreenWidth && x >=0){
			if (y < ScreenHeight && y >= 0){
				buffer[x][y] = attr;
			}
		}
	}

	Pixel **Buffer::BufferCopy(){
		return buffer;
	}

	void Buffer::SetBuffer(Pixel **buffer){
		this->buffer = buffer;
	}

	void Buffer::Resize(int Width, int Height){
		ScreenWidth = Width;
		ScreenHeight = Height;
		buffer = new Pixel*[ScreenWidth];
		for (int h = 0; h <= ScreenWidth; h++)
			buffer[h] = ArrayInit<Pixel>(ScreenHeight, Pixel(' ', cWhite, cBlack));
	}

	Buffer::~Buffer(){
		delete[] buffer;
	}
}