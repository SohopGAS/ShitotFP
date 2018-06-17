#pragma once
#include "Control.h"


class Combobox : public Control
{
public:
	Combobox();
	~Combobox();

	void draw(Graphics& g, int x, int y, size_t z);

	void keyDown(int keyCode, char charecter){};
	void mousePressed(int x, int y, bool isLeft){};
};

