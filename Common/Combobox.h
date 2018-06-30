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
	void draw(Graphics& g, short x, short y, size_t z);
	void SetList(vector<string> ListOfStrings);
	void mousePressed(int x, int y, bool isLeft);
	void getAllControls(vector<Control*>* controls) {};
	virtual void keyDown(WORD keyCode, char charecter) {};
};

//#pragma once
//#include "../Common/Panel.h"
//#include "../Common/Label.h"
//#include "../Common/Button.h"
//
//
//class Combobox : public Panel
//{
//private:
//	Button down_arraw;
//	Label text;
//	vector <string> _options;
//	vector <bool> optionsSelected;
//	int logicalPosition = 0;
//
//public:
//	Combobox();
//	~Combobox();
//
//	void draw(Graphics& g, short x, short y, size_t z);
//
//	void mousePressed(int x, int y, bool isLeft){};
//	void getAllControls(vector<Control*>* controls) {};
//	void keyDown(WORD keyCode, char charecter) {};
//	void func();
//
//
//	void SetList(vector<string> ListOfStrings);
//
//};

