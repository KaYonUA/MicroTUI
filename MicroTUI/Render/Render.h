#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "ScreenBuffer.h"
#include "Cursor.h"

namespace MicroTUI
{
	class Render
	{
	public:
		Render();
		Render(ScreenBuffer *scrbuffer);
		void Connect(ScreenBuffer *scrbuffer);
		void UpdateChanged();
		void _UpdateChanged();
		void UpdateAll();
		void ClearScreen();
		~Render();
	private:
		ScreenBuffer *ScrBuff;
		Cursor curs;
	};
}


#endif

