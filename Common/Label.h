#pragma once
#include "Control.h"
#include "Graphics.h"
#include <string>


using namespace std;

class Label : public Control
{
protected:
	string value;
public:
	Label() {};
	Label(string val);
	string getValue() { return value; };
	void setValue(string s);
	void draw(Graphics& g, short x, short y, size_t z);

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};
	bool myPureFunction() {};

};
