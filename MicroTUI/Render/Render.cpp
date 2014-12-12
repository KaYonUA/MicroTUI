#include "Render.h"


namespace MicroTUI
{
	Render::Render()
	{
		curs.RestoreCursorAttributes(false);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	}

	Render::Render(ScreenBuffer *scrbuffer)
	{
		ScrBuff = scrbuffer;
	}
	void Render::Connect(ScreenBuffer *scrbuffer)
	{
		ScrBuff = scrbuffer;
	}

	void Render::UpdateChanged()
	{
		std::vector<COORD> temp;
		temp = ScrBuff->GenUpdateVector();
		for (size_t upd = 0; upd < temp.size(); upd++)
			curs.Print(temp[upd].X, temp[upd].Y, ScrBuff->Get(SB_CURRENTBUFFER,temp[upd].X, temp[upd].Y));
	}

	void Render::_UpdateChanged()
	{
		COORD size = ScrBuff->GetBuffersSize(SB_NEWBUFFER);
		for (size_t height = 0; height < size.Y; height++)
		for (size_t width = 0; width < size.X; width++)
		if (ScrBuff->PixelChanged(width, height))
		{
			curs.Print(width, height, ScrBuff->Get(SB_NEWBUFFER, width, height));
			//Sleep(50);
		}
		size.X = 0; size.Y = 0;
		curs.SetCoord(size);
	}

	void Render::UpdateAll()
	{
		/*COORD size = ScrBuff->GetBuffersSize(CGUI_CURRENTBUFFER);
		for (size_t height = 0; height < size.Y; height++)
		for (size_t width = 0; width < size.X; width++)
			curs.Print(width, height, ScrBuff->Get(CGUI_CURRENTBUFFER,width, height));
		Sleep(5000);*/
		COORD size = ScrBuff->GetBuffersSize(SB_NEWBUFFER);
		for (size_t height = 0; height < size.Y; height++)
		for (size_t width = 0; width < size.X; width++)
			curs.Print(width, height, ScrBuff->Get(SB_NEWBUFFER, width, height));
	}

	void Render::ClearScreen()
	{
		ScrBuff->ClearScreen();
		UpdateAll();
	}

	Render::~Render()
	{
	}
}