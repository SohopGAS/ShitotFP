#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{

protected:
	short left;
	short top;
	
public:
	Control();
	void setTop(short Top) { this->top = Top; };
	void setLeft(short Left) { this->left = Left; };

	virtual	short getLeft() { return left; };
	virtual	short getTop() { return top; };

	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	
	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
    //virtual bool myPureFunction() = 0;
	
	
	~Control();
};

