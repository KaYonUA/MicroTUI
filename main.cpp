/*Examlpe for MicroTUI v0.1.59-beta18
  by Development KaYon`s Production
  Time: 11:44
  Date: 12.12.2014
 */

#include "MicroTUI\TUI\TUI.h"
#include "MicroTUI\TUI\Mouse.h"
#include "MicroTUI\Widget\GroupBox.h"
#include "MicroTUI\Widget\Label.h"
#include "MicroTUI\Widget\ProgressBar.h"
#include "MicroTUI\Widget\Button.h"
#include <mutex>
#include <conio.h>
using namespace std;
using namespace MicroTUI;
using namespace GUI;
using Color::Pixel;


int main()
{
	SetConsoleTitle(L"MicroTUI");
	SetCursor(NULL);
	ShowCursor(0);
	static TUI *gui = new TUI();	//Main class
	static string er = "0";
	Label PrAnyK(&er, 7, 18, 0, 0, false);
	COLOR Grey = Pixel::ColorToWord(Pixel::Black, Pixel::LightGray);					//Black text and Light-Grey background
	COLOR Green = Pixel::ColorToWord(Pixel::Black, Pixel::Green);						//Black text and Green background
	COLOR White = Pixel::ColorToWord(Pixel::Black, Pixel::White);						//Black text and White background
	COLOR Yellow = Pixel::ColorToWord(Pixel::Black, Pixel::Yellow);						 //Black text and Yellow background
	COLOR Blue = Pixel::ColorToWord(Pixel::Black, Pixel::LightBlue);					 //Black text and ligth blue background
	Window fullScreen("MicroTUI", 0, 0, 0, 0, W_VISIBLE | W_MAXIMIZED);					//Create new full screen window with empty border
	static Window simpleW("Beta", 20, 15, 50, 22, W_VISIBLE | W_BORDERED);							 //Create window 50x16 with border.
	GroupBox descr("Desription", 1, 1, 45, 6);												//Create group box
	GroupBox prgs("Progress Bar", 1, 8, 45, 8);												//Create group box
	Label lDescr("This is beta test MicroTUI v0.1.598 developed by KaYonUA.\n               vk.com/kayonua", 3, 3, 42, 3, true);//Create multiline label
	ProgressBar prgbar(3, 10, 37, 3);														//Create label
	ProgressBar prgbar2(3, 14, 37, 1);		//Create label
	Button btn("Test", 8, 4,8,3, []()->void{
		simpleW.MoveWindow(20, 25);
	});

	string procents = "0%"; char temp_n[5]; int _i_num = 0;
	Label procnt(&procents, 41, 12, 0, 0, false);

	static Mouse mou;

	gui->BackgroundColor = Color::_Transparent;										//Set background color to transparent (Black).
	fullScreen.WindowBackground = White;												//Set Window background color to White.
	lDescr.L_colr = Color::_Transparent;												//Set Label background color to transparent.
	prgbar._bg_Color = Yellow;															//Set Progressbar background color to Yellow
	prgbar._def_Color = Blue;															//Set Progressbar line color to Blue



	/*Adding widgets to window*/
	fullScreen.AddWidget(&btn);
	simpleW.AddWidget(&descr);
	simpleW.AddWidget(&lDescr);
	simpleW.AddWidget(&prgs);
	simpleW.AddWidget(&prgbar);
	simpleW.AddWidget(&prgbar2);
	simpleW.AddWidget(&procnt);
	simpleW.AddWidget(&PrAnyK);

	/*Adding windows to screen*/
	gui->AddWindow(&fullScreen);
	gui->AddWindow(&simpleW);

	gui->SetMouse(&mou);

	gui->MouseCursor([](BYTE byt, COORD cord)->void{
		//static char *temp;
		char temp[3];
		switch (byt)
		{
		case MOUSE_RBCLICKED_:
			er = "MOUSE_RBCLICKED_ ";
			gui->Click(cord.X, cord.Y);
			break;
		case MOUSE_LBCLICKED_:
			er = "MOUSE_LBCLICKED_";
			break;
		case MOUSE_BRELEAZED_:
			er = "MOUSE_BRELEAZED_";
			break;
		case MOUSE_DCLICKED_:
			er = "MOUSE_DCLICKED_";
			break;
		case MOUSE_WHEELED_:
			er = "MOUSE_WHEELED_";
			break;
		case MOUSE_MOVED_:
			er = "MOUSE_MOVED_";
			mou.MoveCursor(cord.X, cord.Y);
			break;
		default:
			break;
		}
		er += _itoa(cord.X, temp, 10);
		er += "x";
		er += _itoa(cord.Y, temp, 10);
	}, GetStdHandle(STD_INPUT_HANDLE));

	/*Updating (Render in buffer) and Show on screen*/
	while (true)
	{
		//_mutx.lock();
		gui->UpdateWindow();
		//_mutx.unlock();
		gui->ShowWindow();
		Sleep(50);
	}

	//getch();

	/*Show how work Progress bars and dynamic labels*/
	while(_i_num++ < 100)
	{
		itoa(_i_num, temp_n, 10);
		procents = temp_n;
		procents += '%';
		prgbar.SetProgress(_i_num);
		prgbar2.SetProgress(_i_num);
		gui->UpdateWindow();
		gui->ShowWindow();
		Sleep(100);
	}
	getch();
}