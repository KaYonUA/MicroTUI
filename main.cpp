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

int main()
{
	system("title MicroTUI");
	//setlocale(LC_ALL,"Russian");
	COLOR Grey = Pixel::ColorToWord(Pixel::Black, Pixel::LightGray);
	COLOR Green = Pixel::ColorToWord(Pixel::Black, Pixel::Green);
	COLOR White = Pixel::ColorToWord(Pixel::Black, Pixel::White);

	TUI scrn; scrn.BackgroundColor = Grey;

	Window test("MicroTUI",20,10,35,12,W_VISIBLE | W_BORDERED);
	//test.WindowBackground = White;
	//test.Border = Green;
	string sss = "This is test\n text\n for testing\n multi line system developed by KaYonUA, best programmer in world!!!";
	Label lbl(sss,0,1,33,7,true);

	test.AddWidget(&lbl);
	scrn.AddWindow(&test);

	scrn.UpdateWindow();
	scrn.ShowWindow();

	getch();
}