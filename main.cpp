/*Example for MicroTUI v0.1.59-beta18
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


int main()
{
	static TUI *gui = new TUI(140, 65, "Alpha MicroTUI");
	//gui->alphaChannel(true);

	static bool buttonPressed = false;

	Window fullScreen("MicroTUI", 0, 0, gui->Width(), gui->Height(), W_VISIBLE | W_FIXED);			
	static Window test("Beta", 16, 2, 50, 23, W_VISIBLE | W_BORDERED);							 
	static Window exitDialog("Exit", gui->Width() / 2 - 25, gui->Height() / 2 - 11, 45,15, W_BORDERED);

	GroupBox description("Desription", 1, 1, 45, 6);												
	GroupBox progressbar("Progress Bar", 1, 8, 45, 8);		

	Label exitConfirm("Vu deystvitelno hotite viyti?", 8, 5, 30, 1, false);
	Label descriptText("This is beta test MicroTUI v0.3.752-beta8 developed by KaYonUA.\n\
										vk.com/kayonua", 3, 3, 42, 3, true);
	
	ProgressBar progressBar(3, 10, 37, 3);
	ProgressBar progressBar2(3, 14, 37, 1);

	Button button("Button", 32, 17,12,3, []()->void{
		while (true){
			test.backgroundColor = cRed;
			Sleep(1000);
			test.backgroundColor = cWhite;
		}
	});

	Button yes("Yes", 27, 10, 12, 3, []()->void{
		exitDialog.setFlags(W_BORDERED | W_VISIBLE | W_SHADOW);
		Sleep(2000);
		exitDialog.backgroundColor = cYellow;
		Sleep(1000);
		exitDialog.backgroundColor = cLightBlue;
		Sleep(2000);
		exitDialog.backgroundColor = cTransparent;
		exitDialog.borderColor = cLightRed;
		Sleep(3000);
		exitDialog.ResizeWindow(50, 50);
		Sleep(3000);
		
	});
	Button no("No", 5, 10, 12, 3, []()->void{
		exitDialog.setFlags(W_BORDERED);
	});
	Button exit("Exit Program", gui->Width() - 20, gui->Height() - 5, 16, 3, []()->void{
		exitDialog.setFlags(W_VISIBLE | W_BORDERED);
	});
	
	string procents = "0%";
	Label progress(&procents, 41, 12, 0, 0, false);

	exit.setBackgroundColor(cTransparent);
	exit.setTextColor(cLightRed);
	exit.setColor(cLightGreen);
	gui->backgroundColor = cWhite;
	fullScreen.backgroundColor = cWhite;
	description.setBackgroundColor(cTransparent);
	progressBar.setBackgroundColor(cYellow);
	progressBar.setColor(cBlue);
	exitDialog.backgroundColor = cTransparent;

	test.AddWidget(&button);
	test.AddWidget(&descriptText);
	test.AddWidget(&description);
	test.AddWidget(&progressbar);
	test.AddWidget(&progressBar);
	test.AddWidget(&progressBar2);
	test.AddWidget(&progress);

	exitDialog.AddWidget(&yes);
	exitDialog.AddWidget(&no);
	exitDialog.AddWidget(&exitConfirm);

	fullScreen.AddWidget(&exit);

	gui->AddWindow(&fullScreen);
	gui->AddWindow(&test);
	gui->AddWindow(&exitDialog);

	gui->MouseCursor([](BYTE byt, COORD cord)->void{}, GetStdHandle(STD_INPUT_HANDLE));

	while (!buttonPressed){
		gui->UpdateWindow();
		gui->ShowWindow();
	}

	delete gui;
	return 0;
}