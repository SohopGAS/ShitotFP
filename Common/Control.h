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
	Color bg, fg;
	BorderType* bt;


public:
	Control();
	Control(BorderType* _bt) :bt(_bt) {};
	Control(Graphics& g, short x, short y, short width, short height);
	// position setter
	void setTop(short Top) { this->top = Top; };
	void setLeft(short Left) { this->left = Left; };
	void setWidth(short Width) { this->width= Width; };
	void setHeight(short Height) { this->height = Height; };
	void setBorderType(BorderType* _bt) { this->bt= _bt;
	int z;
	};
	
	// position getter
	virtual	short getLeft() { return left; };
	virtual	short getTop() { return top; };
	virtual	short getWidth() { return width; };
	virtual	short getHeight() { return height; };
	BorderType* getBorderType() { return bt; };

	// set Color background and fourground 
	void setColor(Color BG, Color FG) { this->bg = BG; this->fg = FG; };
	// Colors getter
	Color getBackground() { return bg; };
	Color getFourground() { return fg; };

	// set foucus
	static void setFocus(Control& control) { static_control = &control; };
	// get fouces 
	static Control* getFocus() { return static_control; };
	
	// virual function implemnted by every component
	virtual void draw(Graphics& g, short x, short y, size_t z) ;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
    //virtual bool myPureFunction() = 0;
	
	
	~Control();
};

