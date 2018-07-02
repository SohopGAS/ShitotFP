#pragma once

#include <iostream>
#include <vector>
#include "Logger.h"
#include "../Common/MouseListener.h"
#include "../Common/Label.h"

using namespace std;

class Button : public Label
{
private:
	vector<MouseListener*> listeners;
public:
	Button();
	Button(string& s);
	~Button() {};
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	virtual void implement_function() {};
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);
	bool canGetFocus() { return false; };


};
