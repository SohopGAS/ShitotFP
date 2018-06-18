#pragma once
#include "Control.h"

class NumericBox : public Control
{
public:
	NumericBox() {};
	~NumericBox() {};
<<<<<<< HEAD

	// need
	void draw(Graphics& g, int x, int y, size_t z);

	// need
=======
	
	// need 
	void draw(Graphics& g, short x, short y, size_t z);
	
	// need 
>>>>>>> origin/master
	void mousePressed(int x, int y, bool isLeft);

	// no need to handel keydown
	void keyDown(int keyCode, char charecter) {};
};
