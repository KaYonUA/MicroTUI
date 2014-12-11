/*Examlpe for MicroTUI v0.1.47-beta
  by Development KaYon`s Production
  Time: 18:07
  Date: 11.12.2014
 */

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
	int w = screen.Width() / 2 - 5;
	int h = screen.Height() / 2 - 5;
	string num; int _i_num=0;
	Window wind("KaYonUA", 6, 3, screen.Width() / 2 - 5, screen.Height() / 2 - 5);
	GroupBox gb("<Vlad>", 2, 1, 18, 9);
	Lable lab("Test :)", 7, 6);
	Lable lab2(&num, 7, 5);
	wind.AddWidget(&gb);
	wind.AddWidget(&lab2);
	wind.AddWidget(&lab);
	screen.AddWindow(&wind);

	char temp[7];
	while (true)
	{
		switch (getch())
		{
		case 'q':
			while (_i_num++ < 100)
			{
				itoa(_i_num, temp, 10);
				num = temp;
				num += '%';
				screen.UpdateWindow();
				screen.ShowWindow();
				Sleep(30);
			}
			break;
		case 'w':
			wind.MoveWindow(x, --y);
			break;
		case 'a':
			wind.MoveWindow(--x, y);
			break;
		case 's':
			wind.MoveWindow(x, ++y);
			break;
		case 'd':
			wind.MoveWindow(++x, y);
			break;
		case 'f':
			wind.MoveWindow(0, 0);
			wind.ResizeWindow(screen.Width(), screen.Height());
			break;
		case 'l':
			wind.MoveWindow(x, y);
			wind.ResizeWindow(w, h);
			break;
		default:
			break;
		}
		screen.UpdateWindow();
		screen.ShowWindow();
	}
	getch();
}