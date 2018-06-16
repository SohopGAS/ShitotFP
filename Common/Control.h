#pragma once
#include "Graphics.h"
#include <vector>

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
	vector<Control*>* controls;
	bool visable;
	bool hasChildren;


public:
	Control();
	Control(short _left, short _top, short _width, short _height);
	// position setter
	void setTop(short _top) { this->top = _top; };
	void setLeft(short _left) { this->left = _left; };
	void setWidth(short _width) { this->width= _width; };
	void setHeight(short _height) { this->height = _height; };


	// position getter
	virtual	short getTop() { return top; };
	virtual	short getLeft() { return left; };
	virtual	short getWidth() { return width; };
	virtual	short getHeight() { return height; };

	// set ColorType background and foreground
	void setColor(ColorType _bg, ColorType _fg) { this->bg = _bg; this->fg = _fg; };

	// Colors getter
	ColorType getBackground() { return bg; };
	ColorType getForeground() { return fg; };

	// Color setter
	void setBackground(ColorType _bg) {this->bg = _bg;};
	void setForeground(ColorType _fg) {this->fg = _fg;};
	// set foucus
	static void setFocus(Control& control) ;

	// get fouces
	static Control* getFocus() ;
	
	// virual function implemnted by every component
	virtual void draw(Graphics& g, int x, int y, size_t z) ;
	virtual void mousePressed(int x, int y, bool isLeft) ;
	virtual void keyDown(int keyCode, char charecter) ;

	 vector<Control*>* getAllControls(vector<Control*>* controls) ;
	 void setAllControls(vector<Control*>* controls) ;
	 void addControl(Control* newC);
	virtual bool canGetFocus() { return FALSE; };
    //virtual bool myPureFunction() = 0;


	~Control();
};
