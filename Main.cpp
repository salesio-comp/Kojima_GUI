#include <Siv3D.hpp>
#include <vector>
#define TATE 15
#define YOKO 12

class read
{
public:
	int32 _tate, _yoko;
	char32 _map;
	String _str;
	void dif(void) {
		TextReader reader(U"GUIfile/txtxt.txt");
		int32 i = 0;
		std::istringstream ss;
		while (reader.readChar(_map))
		{
			i++;

			
		}
	}
};

class click 
{
public:
	int32 _w = TATE, _h = YOKO, a_sq = 0, b_sq = 0, a_sq2 = 0, b_sq2 = 0; 
	double _x;
	void disp(double a, double b) {
		a_sq = 0; b_sq = 0;
		if (_w < _h) {
			_x = 750.0 / _h;
		}
		else {
			_x = 750.0 / _w;
		}
		a -= 100;
		b -= 50;
		while (a > _x) {
			a -= _x;
			a_sq++;
		}
		while (b > _x) {
			b -= _x;
			b_sq++;
		}
	}
	void disp2(double a, double b) {
		a_sq2 = 0; b_sq2 = 0;
		if (_w < _h) {
			_x = 750.0 / _h;
		}
		else {
			_x = 750.0 / _w;
		}
		a -= 100;
		b -= 50;
		while (a > _x) {
			a -= _x;
			a_sq2++;
		}
		while (b > _x) {
			b -= _x;
			b_sq2++;
		}
	}

};

void Main()
{
	Window::Resize(1540, 840);
	Window::SetTitle(U"purocon");
	Graphics::SetBackground(Color(255, 255, 255));
	int32 w = TATE, h = YOKO, Alp = 0, Alp2 = 0;
	click _check;
	read _txt;
	double x;
	if (w < h) {
		x = 750.0 / h;
	}
	else {
		x = 750.0 / w;
	}
	const Font font(x / 2);
	String text = U"A";

	while (System::Update())
	{
		ClearPrint();
		Print << Cursor::Pos();
		Print << x;
		Print << _check.a_sq;
		Print << _check.b_sq;
		Print << _txt._tate;

		if (MouseL.down())
		{
			_check.disp(Cursor::Pos().x, Cursor::Pos().y);
			Alp = 175;
			if (Cursor::Pos().x <= 100 || Cursor::Pos().x >= x * h + 100 || Cursor::Pos().y <= 50 || Cursor::Pos().y >= x * w + 50) {
				Alp = 0;
			}
		}
		if (Cursor::Pos().x >= 100 && Cursor::Pos().x <= x * h + 100 && Cursor::Pos().y >= 50 && Cursor::Pos().y <= x * w + 50) {
			Alp2 = 30;
		}
		else {
			Alp2 = 0;
		}
		_check.disp2(Cursor::Pos().x, Cursor::Pos().y);
		_txt.dif();
		Rect((100 + _check.a_sq * _check._x), (50 + _check.b_sq * _check._x), (_check._x), (_check._x)).draw(Color(255, 0, 0, Alp));
		Rect((100 + _check.a_sq2 * _check._x), (50 + _check.b_sq2 * _check._x), (_check._x), (_check._x)).draw(Color(255, 0, 0, Alp2));
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				//font(text).draw(Arg::topCenter = Vec2((100 + x / 2 + j * x), (50 + x / 6 + i * x)), Color(0, 0, 0));
			}
		}
		font(text).draw(100, 100, Color(0, 0, 0));
		for (int i = 0; i < w + 1; i++) {
			Line(100, 50 + i * x, 100 + x * h, 50 + i * x).draw(3, Color(0, 0, 0));
		}
		for (int i = 0; i < h + 1; i++) {
			Line(100 + i * x, 50, 100 + i * x, 50 + x * w).draw(3, Color(0, 0, 0));
		}
		if (SimpleGUI::Button(U"Close", Vec2(1380, 710), 150))
		{
			System::Exit();
		}

	}
}
