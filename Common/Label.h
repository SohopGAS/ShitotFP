#pragma once
#include "Control.h"
#include "Graphics.h"
#include <string>

using namespace std;

class Label : public Control
{
private:
	string value="";
public:
	Label() { setHeight(1); };
	Label(string);
	string getValue() { return value; };
	void setValue(string);
	void draw(Graphics& g, short x, short y, size_t z);
	virtual void keyDown(WORD keyCode, char charecter);

	bool canGetFocus() { return false; };

	void mousePressed(int x, int y, bool isLeft) {};
	
	
	//bool myPureFunction() {}

};
