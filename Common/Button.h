#pragma once
#include "Label.h"
#include <iostream>
#include <vector>
#include "../Common/MouseListener.h"

#include "Logger.h"
using namespace std;

class Button : public Label
{


private:
	string name_button;
	vector<MouseListener*> listeners;
public:
	Button() {};
	Button(string &s) : Label(s) { };
	~Button() {};
	void setValue(string s) { value = s; };
	void setTop(short _top) { this->top = _top; };
	void setLeft(short _left) { this->left = _left; };
	void setWidth(short _width) { this->width = _width; };
	void setHeight(short _height) { this->height = _height; };
	void setBackground(ColorType _bg) { this->bg = _bg; };
	void setForeground(ColorType _fg) { this->fg = _fg; };
	void setColor(ColorType _bg, ColorType _fg) { this->bg = _bg; this->fg = _fg; };
	static void setFocus(Control& control) { static_control = &control; };
	void setBorderType(BorderType* _bt) { bt = _bt; };
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
};
