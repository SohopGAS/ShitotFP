#pragma once

#include <string>

#include "Control.h"
#include "Graphics.h"

using namespace std;

class Label : public Control
{
private:
	string value="";
public:
	Label() { setHeight(1); };
	Label(string);
	void setValue(string);
	string getValue() { return value; };

	// virtual function implement.
	bool canGetFocus() { return false; };
	void mousePressed(int x, int y, bool isLeft) {};
	void keyDown(WORD code, char charecter) {};
	void draw(Graphics& g, short x, short y, size_t z);
};
