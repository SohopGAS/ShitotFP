#pragma once
#include "Control.h"

class CheckList:public Control
{
	vector <string> _options;
	vector <bool> optionsSelected;
	int logicalPosition = 0;
public:
	CheckList();
	CheckList(int height, int width, vector<string> ListOfStrings, string Square_shape = "( ) ")  {
		int size = _options.size();
		for (int i = 0; i < size; i++) {
			_options[i].insert(0, Square_shape);
		}
		//cursorPosX = _left + 2;
		//cursorPosY = _top + 1;
		optionsSelected = vector<bool>(ListOfStrings.size());
	}
	~CheckList();
	void draw(Graphics& g, short x, short y, size_t z) ;

	void keyDown(WORD keyCode, char charecter) ;
	void mousePressed(int x, int y, bool isLeft) ;
	void Update();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	void selectOption();
	vector<size_t> GetSelectedIndexs();
	bool indexInVector();
};

