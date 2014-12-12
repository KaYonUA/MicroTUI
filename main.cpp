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
	COLOR Grey = Pixel::ColorToWord(Pixel::Black, Pixel::LightGray);
	COLOR Green = Pixel::ColorToWord(Pixel::Black, Pixel::Green);
	COLOR White = Pixel::ColorToWord(Pixel::Black, Pixel::White);
	int x = 6, y = 3;
	TUI screen;
	int w = 35;
	int h = 12;
	string num = "0%"; int _i_num=0;
	Window wind("MicroTUI", 6, 3, w, h, W_ONTOP  | W_VISIBLE| W_BORDERED);
	Window windB("Bender", 6, 18, w, h, W_ONTOP | W_VISIBLE | W_MAXIMIZED);
	GroupBox gb("Progress", 2, 3, 28, 4);
	Label lab2(&num, 25, 5);
	ProgressBar PB(4, 5, 20, 1);
	//wind.AddWidget(&gb);
	wind.AddWidget(&PB);
	wind.AddWidget(&lab2);
	wind.AddWidget(&gb);
	screen.AddWindow(&windB);
	screen.AddWindow(&wind);

	char temp[7];
	while (true)
	{
		switch (getch())
		{
		case 'o':
			PB.SetProgress(--_i_num);
			itoa(_i_num, temp, 10);
			num = temp;
			num += '%';
			break;
		case 'p':
			PB.SetProgress(++_i_num);
			itoa(_i_num, temp, 10);
			num = temp;
			num += '%';
			break;
		case 'q':
			while (_i_num++ < 100)
			{
				itoa(_i_num, temp, 10);
				num = temp;
				num += '%';
				PB.SetProgress(_i_num);
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