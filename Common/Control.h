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
	Color bg, fg;

public:
	Control();
	void setTop(short Top) { this->top = Top; };
	void setLeft(short Left) { this->left = Left; };
	void setWidth(short Width) { this->width= Width; };
	void setHeight(short Height) { this->height = Height; };

	void setColor(Color BG, Color FG) { this->bg = BG; this->fg = FG; };

	virtual	short getLeft() { return left; };
	virtual	short getTop() { return top; };
	virtual	short getWidth() { return width; };
	virtual	short getHeight() { return height; };

	static Control* getFocus() { return static_control; };
	static void setFocus(Control& control) {static_control = &control; };
	
	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
    //virtual bool myPureFunction() = 0;
	
	
	~Control();
};

