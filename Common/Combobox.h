#pragma once

#include "Control.h"


class Combobox : public Control
{
public:
	Combobox();
	~Combobox();

	void draw(Graphics& g, short x, short y, size_t z);

<<<<<<< HEAD
	void mousePressed(int x, int y, bool isLeft){};
	void getAllControls(vector<Control*>* controls) {};
	virtual void keyDown(WORD keyCode, char charecter) {};
=======
	void keyDown(int keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
};
