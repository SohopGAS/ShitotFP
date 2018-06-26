#pragma once
#include "Control.h"
#include "Label.h"
#include "Panel.h"

class RadioBox : public Panel
{

public:
	RadioBox();
	~RadioBox() {};
	void draw(Graphics& g, short x, short y, size_t z);

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};

	boolean SelectedItem(int index) {};
	boolean ClearSelection() {};

	bool canGetFocus() { return true; };

};

