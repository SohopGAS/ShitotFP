#pragma once

#include "Panel.h"
#include "../Common/Label.h"

class RadioBox : public Panel
{
private:
	Label lab1;
	Label lab2;
	Label lab3;

public:
	RadioBox() {};
	
	~RadioBox() {};

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};
	void init();
	boolean SelectedItem(int index);
	boolean ClearSelection();

	bool canGetFocus() { return true; };

};

