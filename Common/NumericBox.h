#pragma once
#include "../Common/Button.h"
#include "../Common/Panel.h"
#include "../Common/BorderType.h"
#include "../Common/SingleLineBorder.h"

class OnClickPlus : public MouseListener
{
public:
	int plus_id = 2;
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
	int minus_id = 1;
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
	// listner implements
	OnClickPlus plus_;
	OnClickMinus minus_;

	//  tow buttons and label
	Button plus, minus;
	Label label_value;
	
public:
	NumericBox();

	void init();

	// setter Minimum and Maximum
	void set_minVal(int _minVal) { this->minVal = _minVal; };
	void set_maxVal(int _maxVal) { this->maxVal = _maxVal; };
	
	// getters Minimum and Maximum
	int get_minVal() { return minVal; };
	int get_maxVal() { return maxVal; };
	
	//void SetValue(int val);
	void SetMaxValue(int val) { maxVal = val; }
	void SetMinValue(int val) { minVal = val; }
	//void onClikck_plus();
	int GetValue() { return val;	}

	
	// function implement
	bool canGetFocus() { return false; }
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(WORD code, char charecter) {};
	

	~NumericBox() {};
};
