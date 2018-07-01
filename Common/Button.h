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
public:
	Button();
	Button(string& s);
	~Button() {};
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }


	virtual void implement_function() {};
=======
<<<<<<< HEAD
	vector<MouseListener*> listeners;
=======
	
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
public:
	Button() { setHeight(1); };
	Button(string& _s) { this->setValue(_s); };
	~Button() {};
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
>>>>>>> master
	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD keyCode, char charecter);

<<<<<<< HEAD
	bool canGetFocus() { return false; };


};
<<<<<<< HEAD
=======
=======
/*
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
>>>>>>> master
