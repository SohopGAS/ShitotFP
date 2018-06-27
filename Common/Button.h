#pragma once
#include "../Common/Label.h"

#include <iostream>
#include <vector>
#include "../Common/MouseListener.h"

#include "Logger.h"
using namespace std;

class Button : public Label
{
public:
	vector<MouseListener*> listeners;
	Button() { setHeight(1); };
	Button(string& _s) { this->setValue(_s); };
	~Button() {};
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);

	bool canGetFocus() { return false; };


};
