#pragma once

#include "../Common/Control.h"

/// public panel
class CheckList:public Control
{
	// using controls form panel - using labels
	vector <string> _options;

	vector <bool> optionsSelected;
	int logicalPosition = 0;


public:
	CheckList();
	CheckList(int height, int width, vector<string> ListOfStrings, string Square_shape = "( ) ");
	~CheckList();
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(int keyCode, char charecter);
	int getSize() { return _options.size(); };
	void keyDown(WORD keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	void Update();
	void SetList(vector<string> ListOfStrings, string Square_shape);
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	void selectOption();
	vector<size_t> GetSelectedIndexs();
	bool indexInVector();
	void focusOn() ;


	bool canGetFocus() { return true; };
};
