#include "Render.h"


namespace MicroTUI
{
	void Render::Connect(ScreenBuffer *scrbuffer){
		ScrBuff = scrbuffer;
	}

	void Render::UpdateChanged(){
		std::vector<COORD> temp;
		temp = ScrBuff->GenUpdateVector();
		for (size_t upd = 0; upd < temp.size(); upd++)
			curs.Print(temp[upd].X, temp[upd].Y, ScrBuff->Get(SB_CURRENTBUFFER,temp[upd].X, temp[upd].Y));
	}

	void Render::_UpdateChanged(){
		COORD size = ScrBuff->GetBuffersSize(SB_NEWBUFFER);
		for (SHORT height = 0; height < size.Y; height++)
		{
			for (SHORT width = 0; width < size.X; width++)
				if (ScrBuff->PixelChanged(width, height)){
					curs.Print(width, height, ScrBuff->Get(SB_NEWBUFFER, width, height));
				}

		}
		curs.SetCoord({ 0, 0 });
	}

	void Render::UpdateAll(){
		COORD size = ScrBuff->GetBuffersSize(SB_NEWBUFFER);
		for (SHORT height = 0; height < size.Y; height++)
		for (SHORT width = 0; width < size.X; width++)
			curs.Print(width, height, ScrBuff->Get(SB_NEWBUFFER, width, height));
	}

	void Render::ClearScreen(){
		ScrBuff->ClearScreen();
		UpdateAll();
	}

	Render::~Render()
	{
	}
}