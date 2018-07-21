#pragma once

#include "../Common/Panel.h"
#include "../Common/Label.h"

class RadioBox : public Panel
{
private:
	int logicalPosition = 0;
	vector <bool> optionsSelected;

public:
	RadioBox() {};
	~RadioBox() {};

	// function implemnted
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD  code, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	bool canGetFocus() { return true; };
	void focusOn() { graphic.moveTo(left + 1, top + logicalPosition); graphic.setCursorVisibility(true); };

	// Set logical position to index.
	boolean selectedItem(int index);

	// Set logical to 0.
	boolean clearSelection();

	// Return logical position.
	int getlogicalPosition() { return logicalPosition; };

	// Initilize list.
	void setList(vector<string> ListOfStrings,string Square_shape);

	// Update select option.
	void selectOption();

	// Get the string value from choosen label.
	string getChosen() {
		Label *pp = (Label*)this->controls[logicalPosition];
		return pp->getValue();
	}

};
