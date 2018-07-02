#pragma once
#include "Control.h"
#include "Label.h"
#include "Button.h"
#include "RadioBox.h"
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
	OnClick c;
	Label l;
	Button b;
	RadioBox r;
	vector <string> _options;
	vector <bool> optionsSelected;
	int logicalPosition = 0;
	bool hasChosen;
public:
	Combobox();
	~Combobox();
	void func();
	bool canGetFocus() { return true; };

	void draw(Graphics& g, short x, short y, size_t z);
	void SetList(vector<string> ListOfStrings,string Square_shape);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(WORD  code, char charecter);


	void focusOn() {

		if (c.visable == true) {
			this->setFocus(r);
			r.focusOn();
		}
		else {
			graphic.setCursorVisibility(false);
			
		}
	};

	};