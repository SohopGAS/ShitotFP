#pragma once
#include "Control.h"


class Combobox : public Control
{
public:
	Combobox();
	~Combobox();

	void draw(Graphics& g, short x, short y, size_t z);

	void mousePressed(int x, int y, bool isLeft){};
	void getAllControls(vector<Control*>* controls) {};
	virtual void keyDown(WORD keyCode, char charecter) {};
};

