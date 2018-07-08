#include "Graphics.h"

Graphics::Graphics(DWORD stdHandle)
	: _console(GetStdHandle(stdHandle)), _background(ColorType::Black), _foreground(ColorType::White)
{
	updateConsoleAttributes();
}

void Graphics::clearScreen()
{
	DWORD d;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(_console, &csbi);
	auto size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputAttribute(_console, csbi.wAttributes, size, { 0, 0 }, &d);
	FillConsoleOutputCharacter(_console, L' ', size, { 0, 0 }, &d);
}

void Graphics::moveTo(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(_console, c);
}

void Graphics::setBackground(ColorType color)
{
	_background = color;
	updateConsoleAttributes();
}

void Graphics::setForeground(ColorType color)
{
	_foreground = color;
	updateConsoleAttributes();
}

void Graphics::write(string s)
{
	WriteConsoleA(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(wstring s)
{
	WriteConsoleW(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(int x, int y, string s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::write(int x, int y, wstring s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::setCursorVisibility(bool isVisible)
{
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(_console, &cci);
	cci.bVisible = isVisible;
	SetConsoleCursorInfo(_console, &cci);
}

void Graphics::updateConsoleAttributes()
{
	DWORD attributes = 0;

	switch (_foreground)
	{
		case ColorType::Black:	break;
		case ColorType::Blue:	attributes |= FOREGROUND_BLUE; break;
		case ColorType::Green:	attributes |= FOREGROUND_GREEN; break;
		case ColorType::Red:	attributes |= FOREGROUND_RED; break;
		case ColorType::Cyan:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
		case ColorType::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
		case ColorType::Orange: attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break;
		case ColorType::White:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
	}

	switch (_background)
	{
		case ColorType::Black:	break;
		case ColorType::Blue:	attributes |= BACKGROUND_BLUE; break;
		case ColorType::Green:	attributes |= BACKGROUND_GREEN; break;
		case ColorType::Red:	attributes |= BACKGROUND_RED; break;
		case ColorType::Cyan:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN; break;
		case ColorType::Purple:	attributes |= BACKGROUND_BLUE | BACKGROUND_RED; break;
		case ColorType::Orange: attributes |= BACKGROUND_GREEN | BACKGROUND_RED; break;
		case ColorType::White:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
	}

	SetConsoleTextAttribute(_console, attributes);
}

typedef long long long64;


bool isInside(int x, int y, int left, int top, int width, int height)
{
	x -= left;
	y -= top;
	return x >= 0 && y >= 0 && x < width && y < height;
}
