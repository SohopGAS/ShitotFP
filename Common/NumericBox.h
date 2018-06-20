#pragma once
#include "Control.h"
#include "../Common/Button.h"
#include"../Common/Panel.h"


class OnClickPlus : public MouseListener
{
public:
	bool addNum = false;
	int currentNumber;
	void MousePressed(int x, int y, bool isLeft)
	{
		addNum = true;
	}
};

class OnClickMinus : public MouseListener
{
public:
	bool subNum = false;
	int currentNumber;
	void MousePressed(int x, int y, bool isLeft) {
		subNum = true;
	}
};




class NumericBox : public Control
{

protected:
	int val, maxVal, minVal;
	OnClickPlus plus_;
	OnClickMinus minus_;

	Button plus, minus;
	Label label_value;



public:
	NumericBox(int minVal, int maxVal) ;
	

	// need 
	void draw(Graphics& g, short x, short y, size_t z);
	
	// need 
	void mousePressed(int x, int y, bool isLeft);
	
	// no need to handel keydown
	void keyDown(int keyCode, char charecter) {};


	//void SetValue(int val);
	void SetMaxValue(int val) { maxVal = val; }
	void SetMinValue(int val) { minVal = val; }
	int GetValue() { return val; }
	bool canGetFocus() { return false; }
	~NumericBox() {};
};

