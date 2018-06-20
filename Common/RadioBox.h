#pragma once
#include "Control.h"
#include "Label.h"

class RadioBox : public Control
{
private:
	Label l1;
	Label l2;
	Label l3;
public:
	RadioBox() {
		string s = "radio box :";
		l1.setValue(s) ;
		l2.setValue(s);
		l3.setValue(s);
	};
	~RadioBox() {};
	void draw(Graphics& g, short x, short y, size_t z);

	void keyDown(int keyCode, char charecter) {};
	void mousePressed(int x, int y, bool isLeft) {};
	bool canGetFocus() { return true; };
	boolean SelectedItem(int index) {};
	boolean ClearSelection() {};


};

