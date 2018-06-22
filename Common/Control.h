#pragma once

#include "Graphics.h"
#include <vector>
#include "BorderType.h"
#include "SingleLineBorder.h"

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



public:
	// Constructors & Destructors.
	Control();
	Control(BorderType* _bt) : bt(_bt) {};
	Control(Graphics& g, short x, short y, short width, short height);
	~Control();

	// Setters functions.
	void setTop(short _top) {  this->top = _top; };
	void setLeft(short _left) 		{ this->left = _left; 		};
	void setWidth(short _width) 	{ this->width= _width; 		};
	void setHeight(short _height) { this->height = _height; };
	void setBackground(ColorType _bg) {this->bg = _bg; };
	void setForeground(ColorType _fg) {this->fg = _fg; };
	void setColor(ColorType _bg, ColorType _fg) { this->bg = _bg; this->fg = _fg; };
	static void setFocus(Control& control) ;
	void setBorderType(BorderType* _bt) { bt = _bt; };

	// Getter functions. (1) virtual.
	virtual	short getLeft() { return left; };
	virtual	short getTop() { return top; };
	virtual	short getWidth() { return width; };
	virtual	short getHeight() { return height; };
	virtual void getAllControls(vector<Control*>* controls) {};

	// Getter functions. (2) Other.
	BorderType* getBorderType() { return bt; };
	static Control* getFocus() { return static_control; };

	// More virual function implemnted by every component.
	virtual void draw(Graphics& g, short x, short y, size_t z) ;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(WORD keyCode, char charecter) {};
	virtual bool canGetFocus() { return false; };
	virtual void focusOn() {};
	// virtual bool myPureFunction() = 0;

};
