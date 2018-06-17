#pragma once
#include "Control.h"

class MessageBox : public Control
{
public:
	MessageBox();
	~MessageBox();

	void draw(Graphics& g, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft) {};
	void keyDown(int keyCode, char charecter) {};

};

