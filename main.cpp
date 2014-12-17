/*Examlpe for MicroTUI v0.1.59-beta18
  by Development KaYon`s Production
  Time: 11:44
  Date: 12.12.2014
 */

#include "MicroTUI\TUI.h"
#include "MicroTUI\GroupBox.h"
#include "MicroTUI\Label.h"
#include "MicroTUI\ProgressBar.h"
#include <conio.h>
using namespace std;
using namespace MicroTUI;
using namespace GUI;
using Color::Pixel;

void Obrabot(BYTE bt)
{
	switch (bt)
	{
	case 1:
		cout << "1" <<endl;
		break;
	case 2:
		cout << "2" << endl;
		break;
	case 3:
		cout << "3" << endl;
		break;
	default:
		break;
	}
}

int main()
{
	system("title MicroTUI");
	TUI sd;
	sd.MouseCursor(Obrabot);
	COLOR Grey = Pixel::ColorToWord(Pixel::Black, Pixel::LightGray);					//Black text and Light-Grey background
	COLOR Green = Pixel::ColorToWord(Pixel::Black, Pixel::Green);						//Black text and Green background
	COLOR White = Pixel::ColorToWord(Pixel::Black, Pixel::White);						//Black text and White background
	COLOR Yellow = Pixel::ColorToWord(Pixel::Black, Pixel::Yellow);						 //Black text and Yellow background
	COLOR Blue = Pixel::ColorToWord(Pixel::Black, Pixel::LightBlue);					 //Black text and ligth blue background
	TUI gui;	//Main class
	Window fullScreen("MicroTUI", 0, 0, 0, 0, W_VISIBLE | W_MAXIMIZED);					//Create new full screen window with empty border
	Window simpleW("Beta",30,15,50,22,W_VISIBLE|W_BORDERED);							 //Create window 50x16 with border.
	GroupBox descr("Desription",1,1,45,6);												//Create group box
	GroupBox prgs("Progress Bar",1,8,45,8);												//Create group box
	Label lDescr("This is beta test MicroTUI v0.1.598 developed by KaYonUA.\n               vk.com/kayonua",3,3,42,3,true);//Create multiline label
	Label PrAnyK("Press any key to start process...",7,18,0,0,false);
	ProgressBar prgbar(3,10,37,3);														//Create label
	ProgressBar prgbar2(3,14,37,1);														//Create label

	string procents = "0%";char temp_n[5];int _i_num = 0;
	Label procnt(&procents,41,12,0,0,false);

	gui.BackgroundColor = Color::_Transparent;											//Set background color to transparent (Black).
	fullScreen.WindowBackground = White;												//Set Window background color to White.
	lDescr.L_colr = Color::_Transparent;												//Set Label background color to transparent.
	prgbar._bg_Color = Yellow;															//Set Progressbar background color to Yellow
	prgbar._def_Color = Blue;															//Set Progressbar line color to Blue



	/*Adding widgets to window*/
	simpleW.AddWidget(&descr);
	simpleW.AddWidget(&lDescr);
	simpleW.AddWidget(&prgs);
	simpleW.AddWidget(&prgbar);
	simpleW.AddWidget(&prgbar2);
	simpleW.AddWidget(&procnt);
	simpleW.AddWidget(&PrAnyK);

	/*Adding windows to screen*/
	gui.AddWindow(&fullScreen);
	gui.AddWindow(&simpleW);

	/*Updating (Render in buffer) and Show on screen*/
	gui.UpdateWindow();
	gui.ShowWindow();
	gui.ShowWindow();
	gui.ShowWindow();

	getch();

	/*Show how work Progress bars and dynamic labels*/
	while(_i_num++ < 100)
	{
		itoa(_i_num,temp_n,10);
		procents = temp_n;
		procents += '%';
		prgbar.SetProgress(_i_num);
		prgbar2.SetProgress(_i_num);
		gui.UpdateWindow();
		gui.ShowWindow();
		Sleep(100);
	}
	getch();
}