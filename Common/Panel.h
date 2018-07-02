#pragma once

#include "Control.h"

class Panel : public Control
{
protected:
	vector<Control*> controls;
public:
	Panel() {};
	~Panel() {};

	void draw(Graphics& g, short x, short y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) ;
	virtual void keyDown(int keyCode, char charecter) ;
	void getAllControls(vector<Control*>* controls);
	bool canGetFocus() { return false; };
	void Add(Control* control);
	//vector<Control*> getControls() {return controls; };
	void focusOn() {
		OutputDebugStringW(L"focus on panel");
	}

};
