#pragma once
#include "../Common/Label.h"

#include <iostream>
#include <vector>
#include "../Common/MouseListener.h"
#include "Logger.h"

using namespace std;

class Button : public Label
{
private:
<<<<<<< HEAD
	vector<MouseListener*> listeners;
=======
	
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
public:
	Button() { setHeight(1); };
	Button(string& _s) { this->setValue(_s); };
	~Button() {};
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);

<<<<<<< HEAD
	bool canGetFocus() { return false; };


};
=======
/*
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
