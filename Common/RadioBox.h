#pragma once
#include "Control.h"

class RadioBox : public Control
{
public:
	RadioBox();
	~RadioBox();
	void draw(Graphics& g, short x, short y, size_t z);

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};
};

