#pragma once
#include "Control.h"

class NumericBox : public Control
{
public:
	NumericBox() {};
	~NumericBox() {};
	
	// need 
	void draw(Graphics& g, short x, short y, size_t z);
	
	// need 
	void mousePressed(int x, int y, bool isLeft);
	
	// no need to handel keydown
	void keyDown(int keyCode, char charecter) {};
};

