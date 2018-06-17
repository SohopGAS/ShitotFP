#pragma once
#include "Control.h"

class RadioBox : public Control
{
public:
	RadioBox();
	~RadioBox();
	void draw(Graphics& g, int x, int y, size_t z);

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};
};

