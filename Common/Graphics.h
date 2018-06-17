#pragma once

#include <string>
#include <windows.h>

using namespace std;

enum class ColorType { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Graphics
{
private:
	HANDLE _console;
	ColorType _background, _foreground;
	void updateConsoleAttributes();

public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void moveTo(int x, int y);
	void setBackground(ColorType color);
	void setForeground(ColorType color);
	void write(string s);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(int x, int y, wstring s);
	void setCursorVisibility(bool isVisible);
};

bool isInside(int x, int y, int left, int top, int width, int height);
