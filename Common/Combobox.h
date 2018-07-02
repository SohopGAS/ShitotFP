#pragma once
#include "Control.h"
#include "Label.h"
#include "Button.h"
#include "RadioBox.h"

// comboBox open list button listner
class OnClick : public MouseListener
{
public:
	bool visable = false;
	void MousePressed(int x, int y, bool isLeft)
	{
		OutputDebugStringW(L"mouse preesed + \n");
		if (visable == false)visable = true;
		else visable = false;

	}
};

class Combobox : public Panel
{
private:
	// ComboBox variable

		
	OnClick c;						// mouse listner 
	Label l;						// title to update string variable
	Button b;						// button ">"
	RadioBox r;						// RadioBox for the list
	bool hasChosen;					// checck if press already ro not
public:
	Combobox();
	~Combobox();

	// initialize the numaric box 
	void init();

	// function implemnted 
	void draw(Graphics& g, short x, short y, size_t z);
	void SetList(vector<string> ListOfStrings,string Square_shape);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(WORD  code, char charecter);
	void focusOn();
	bool canGetFocus() { return false; };
	};