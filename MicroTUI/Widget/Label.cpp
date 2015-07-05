#include "Label.h"

namespace MicroTUI
{
	void Label::_Render_func(ScreenBuffer *buffer, COORD _w_Coord)
	{
		COORD _g_widgCord; _g_widgCord.X = WidgetCoord.X + _w_Coord.X;
		_g_widgCord.Y = WidgetCoord.Y + _w_Coord.Y;

		if (_f_isML == false)
			buffer->Lable(_g_widgCord.X, _g_widgCord.Y, widgettitle.empty() ?
			_p_str->c_str() :
			widgettitle.c_str(), textColor, backgroundColor);
		else{
			buffer->Rectangle(_g_widgCord.X, _g_widgCord.Y, WidgetSize.width, WidgetSize.height, Pixel::pixelGen(' ', textColor, backgroundColor));
			std::string temp = widgettitle;
			int avalib_sp = WidgetSize.width,
				next_wp = 0,
				wrd_leng = 0,
				w_line = 0;

			for (int _t_len = 0; int(temp.size()) >= _t_len; _t_len++){
				if (temp[_t_len] == ' ' || temp[_t_len] == '\n' || temp[_t_len] == '\0'){
					wrd_leng = ++_t_len;
					if (temp[_t_len - 1] == '\n')
						wrd_leng -= 1;
					if (avalib_sp >= wrd_leng){
						buffer->Lable(_g_widgCord.X + next_wp, _g_widgCord.Y + w_line, temp.substr(0, _t_len).c_str(), textColor, backgroundColor);
						avalib_sp -= wrd_leng;
					}
					else{
						w_line++;
						next_wp = 0;
						avalib_sp = WidgetSize.width - wrd_leng;
						buffer->Lable(_g_widgCord.X + next_wp, _g_widgCord.Y + w_line, temp.substr(0, _t_len).c_str(), textColor, backgroundColor);

					}
					if (temp[_t_len - 1] == '\n'){
						avalib_sp = 0;
						_t_len += 1;
					}
					next_wp += wrd_leng;
					temp.erase(0, _t_len);
					_t_len = 0;
				}
			}
		}
	}
}