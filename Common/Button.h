
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
	vector<MouseListener*> listeners;
	string name_button;
public:
	Button() {};
	Button(string& _s) :Label(_s) { };
	~Button() {};
	
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);

	bool canGetFocus() { return false; };


};
