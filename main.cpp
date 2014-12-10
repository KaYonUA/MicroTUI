#include "MicroTUI\TUI.h"
#include "MicroTUI\GroupBox.h"
#include "MicroTUI\Lable.h"
#include <conio.h>
using namespace std;
using namespace MicroTUI;
using namespace GUI;
using Color::Pixel;

int main()
{
	system("title MicroTUI");
	int x = 6, y = 3;
	TUI screen;
	Window wind("KaYonUA", 6, 3, screen.Width() / 2 - 5, screen.Height() / 2 - 5);
	Window wind4("Green", 10, screen.Height() / 2, screen.Width() / 2 - 5, screen.Height() / 2 - 5);
	GroupBox gb("<Vlad>", 2, 1, 18, 9);
	GroupBox gb2("!!Ilia!!", 6, 1, 18, 9);
	Lable lab("Test :)", 12, 5);
	Lable lab2("All OK!", 7, 5);
	wind.AddWidget(&gb);
	wind.AddWidget(&lab2);
	wind4.AddWidget(&gb2);
	wind4.AddWidget(&lab);
	screen.AddWindow(&wind);
	//screen.AddWindow(&wind2);
	//screen.AddWindow(&wind3);
	screen.AddWindow(&wind4);
	while (true)
	{
		screen.UpdateWindow();
		screen.ShowWindow();
		getch();
		wind.MoveWindow(x++, y);
	}
	getch();
}