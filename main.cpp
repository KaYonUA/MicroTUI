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
	SetConsoleTitle(L"MicroTUI x64");
	SetCursor(NULL);
	ShowCursor(0);

	static TUI *gui = new TUI();	//Main class
	static string er = "0";
	static bool buttonPressed = false;

	Label PrAnyK(&er, 7, 18, 0, 0, false);

	COLOR Grey = Pixel::ColorToWord(Pixel::Black, Pixel::LightGray);					
	COLOR dGrey = Pixel::ColorToWord(Pixel::Black, Pixel::DarkGray);
	COLOR Green = Pixel::ColorToWord(Pixel::Black, Pixel::Green);
	COLOR White = Pixel::ColorToWord(Pixel::Black, Pixel::White);
	COLOR Yellow = Pixel::ColorToWord(Pixel::Black, Pixel::Yellow);	
	COLOR Blue = Pixel::ColorToWord(Pixel::Black, Pixel::LightBlue);		
	COLOR Red = Pixel::ColorToWord(Pixel::Black, Pixel::LightRed);

	Window fullScreen("MicroTUI", 0, 0, gui->Width(), gui->Height(), W_VISIBLE | W_FIXED);			
	static Window simpleW("Beta", 16, 2, 50, 23, W_VISIBLE | W_BORDERED);							 
	static Window simple("Exit", gui->Width() / 2 - 25, gui->Height() / 2 - 11, 45,15, W_BORDERED);
	GroupBox descr("Desription", 1, 1, 45, 6);												
	GroupBox prgs("Progress Bar", 1, 8, 45, 8);												
	Label lDescr("This is beta test MicroTUI v0.3.752-beta8 developed by KaYonUA.\n\
										vk.com/kayonua", 3, 3, 42, 3, true);
	Label confirm("Vu deystvitelno hotite viyti?", 8, 5, 30, 1, false);
	ProgressBar prgbar(3, 10, 37, 3);														//Create label
	ProgressBar prgbar2(3, 14, 37, 1);		//Create label
	Button btn("Button", 32, 17,12,3, []()->void{
	});
	Button btn2("Yes", 27, 10, 12, 3, []()->void{
		exit(0);
	});
	Button btn3("No", 5, 10, 12, 3, []()->void{
		simple.setFlags(W_BORDERED);
	});
	Button btn4("Exit Program", gui->Width() - 20, gui->Height() - 5, 16, 3, []()->void{
		simple.setFlags(W_VISIBLE | W_BORDERED);
	});
	btn4.setBackgroundColor(Color::Pixel::White);
	btn4.setTextColor(Color::Pixel::LightRed);

	string procents = "0%"; char temp_n[5]; int _i_num = 0;
	Label procnt(&procents, 41, 12, 0, 0, false);

	static Mouse mou;

	gui->BackgroundColor = Color::_Transparent;	
	fullScreen.WindowBackground = White;
	lDescr.L_colr = Color::_Transparent;
	prgbar._bg_Color = Yellow;		
	prgbar._def_Color = Blue;



	/*Adding widgets to window*/
	simpleW.AddWidget(&btn);
	simpleW.AddWidget(&descr);
	simpleW.AddWidget(&lDescr);
	simpleW.AddWidget(&prgs);
	simpleW.AddWidget(&prgbar);
	simpleW.AddWidget(&prgbar2);
	simpleW.AddWidget(&procnt);
	simpleW.AddWidget(&PrAnyK);
	simple.AddWidget(&btn2);
	simple.AddWidget(&btn3);
	simple.AddWidget(&confirm);

	fullScreen.AddWidget(&btn4);

	/*Adding windows to screen*/
	gui->AddWindow(&fullScreen);
	gui->AddWindow(&simpleW);
	gui->AddWindow(&simple);
	gui->SetMouse(&mou);
	gui->MouseCursor([](BYTE byt, COORD cord)->void{}, GetStdHandle(STD_INPUT_HANDLE));

	while (!buttonPressed){
		gui->UpdateWindow();
		gui->ShowWindow();
	}
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
	delete gui;
	getch();
	return 0;
}