#pragma once

#include "../Common/Panel.h"

class CheckList:public Panel
{
	vector <bool> optionsSelected;
	int logicalPosition = 0;


public:
	CheckList();
	~CheckList();

	// initialize list
	void setList(vector<string> ListOfStrings);

	// select option  - mark the choosen
	void selectOption();

	// Selec tIndex - choose the index
	void SelectIndex(size_t index);

	// Deselect Index
	void DeselectIndex(size_t index);

	// Get Selected Indexs
	vector<size_t> GetSelectedIndexs();
	bool indexInVector();

	// virtual function implement
	void focusOn();
	bool canGetFocus() { return true; };
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD code, char charecter);
	void mousePressed(int x, int y, bool isLeft);
};
