#pragma once

#include "Control.h"
#include "Label.h"
#include "Button.h"
#include "RadioBox.h"

// ComboBox open list button listener.
class OnClick : public MouseListener
{
public:
	bool visable = false;

	void MousePressed(int x, int y, bool isLeft)
	{
		OutputDebugStringW(L"mouse preesed + \n");
		if (visable == false)
			visable = true;
		else
			visable = false;
	}
};

class Combobox : public Panel
{
private:
	// ComboBox variable.
	OnClick c;						// Mouse listener.
	Label l;							// Title to update string variable.
	Button b;							// Button ">".
	RadioBox r;						// RadioBox for the list.
	bool hasChosen;				// Checck if press already or not.

public:
	Combobox();
	~Combobox();

	// Initialize the numaric box.
	void init();

	// Function implemnted.
	void draw(Graphics& g, short x, short y, size_t z);
	void SetList(vector<string> ListOfStrings, string Square_shape);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(WORD code, char charecter);
	void focusOn();
	bool canGetFocus() { return false; };
	};
