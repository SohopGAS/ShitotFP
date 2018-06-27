#pragma once
#include "Graphics.h"
#include <vector>
#include "BorderType.h"

using namespace std;

class Control
{

protected:

	short left;
	short top;
	short width;
	short height;
	static Control* static_control;
	ColorType bg, fg;
	BorderType* bt;	
	
	Graphics graphic;

public:
	Control();
	Control(BorderType* _bt) : bt(_bt) {};
	Control(Graphics& g, short x, short y, short width, short height);
	// position setter
	
	void setTop(short _top) {  this->top = _top; };
	void setLeft(short _left) 		{ this->left = _left; 		};
	void setWidth(short _width) 	{ this->width= _width; 		};
	void setHeight(short _height) { this->height = _height; };
	void setBackground(ColorType _bg) {this->bg = _bg; };
	void setForeground(ColorType _fg) {this->fg = _fg; };
	void setColor(ColorType _bg, ColorType _fg) { this->bg = _bg; this->fg = _fg; };
	static void setFocus(Control& control) { static_control = &control; static_control->focusOn(); };
	void setBorderType(BorderType* _bt) { bt = _bt; };
	// position getter
	virtual void focusOn() {
		OutputDebugStringW(L"focus on Control");
	};
	virtual	short getLeft() { return left; };
	virtual	short getTop() { return top; };
	virtual	short getWidth() { return width; };
	virtual	short getHeight() { return height; };
	BorderType* getBorderType() { return bt; };

	// get fouces
	static Control* getFocus() { return static_control; };

	// virual function implemnted by every component
	virtual void draw(Graphics& g, short x, short y, size_t z) ;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(WORD code, char charecter) {};

	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return false; };
    //virtual bool myPureFunction() = 0;	


	virtual void nowInFocus() {};

	~Control();
};
