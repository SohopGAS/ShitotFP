#pragma once
#include "../Common/Button.h"
#include "../Common/Panel.h"

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




class NumericBox : public Panel
{

protected:
	int val, maxVal, minVal;
	// lisner implements
	OnClickPlus plus_;
	OnClickMinus minus_;

	//  tow buttons and label
	Button plus, minus;
	Label label_value;

public:
	NumericBox();

	void init();

	// need
	void set_minVal(int _minVal) { this->minVal = _minVal; };
	void set_maxVal(int _maxVal) { this->maxVal = _maxVal; };
	// need
	void mousePressed(int x, int y, bool isLeft);


	// no need to handel keydown
	void keyDown(int keyCode, char charecter) {};

	//void SetValue(int val);
	void SetMaxValue(int val) { maxVal = val; }
	void SetMinValue(int val) { minVal = val; }

	int GetValue() { return val;
		// string to int converter
		// val=  label_value.getValue();
	}
	bool canGetFocus() { return false; }

	~NumericBox() {};
};
