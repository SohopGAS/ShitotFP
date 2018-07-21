#pragma once

#include "Control.h"

class Panel : public Control
{
protected:
	// vector to hold control* component
	vector<Control*> controls;
public:
	Panel() {};
	~Panel() {};

	// add control* to Vector controls
	void add(Control* control);

	// function implemnted
	void draw(Graphics& g, short x, short y, size_t z);
	void getAllControls(vector<Control*>* controls);
	bool canGetFocus() { return true; };
	void focusOn() { graphic.setCursorVisibility(false); };
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(WORD code, char charecter) {};
};
