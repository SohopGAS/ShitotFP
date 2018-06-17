#pragma once
#include "Control.h"

class CheckList : public Control
{
public:
	CheckList();
	~CheckList();
	void draw(Graphics& g, int x, int y, size_t z) {};

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};
};
