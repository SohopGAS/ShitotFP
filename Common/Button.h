#pragma once

#include <iostream>
#include <vector>

#include "../Common/Label.h"
#include "../Common/MouseListener.h"
#include "Logger.h"

using namespace std;

class Button : public Label
{
private:
	vector<MouseListener*> listeners;
public:
	Button() { setHeight(1); };
	Button(string& _s) { this->setValue(_s); };
	~Button() {};

	// add listner to the Listeners
	void addListener(MouseListener &listener) { listeners.push_back(&listener); }

	// Control function
	bool canGetFocus() { return false; };
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD code, char charecter);


};
