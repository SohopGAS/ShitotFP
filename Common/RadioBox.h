#pragma once
#include "../Common/Panel.h"
#include "../Common/Label.h"


class RadioBox : public Panel
{
private:
	// variable
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

	// set logical position to index
	boolean SelectedItem(int index);
	
	// set logical to 0
	boolean ClearSelection();

	// return logical position
	int getlogicalPosition() { return logicalPosition; };

	// initilize list 
	void SetList(vector<string> ListOfStrings,string Square_shape);
	
	// update select option
	void selectOption();
	
	// get the string value from choosen label
	string GetChosen() {Label *pp = (Label*)this->controls[logicalPosition];return  pp->getValue();	}
};

