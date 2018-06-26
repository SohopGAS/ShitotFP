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
		this->setHeight(height);
		this->setWidth(width);
	}
	~CheckList();
	void draw(Graphics& g, short x, short y, size_t z);
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
	void focusOn() {
		OutputDebugStringW(L"focus on checklist\n");
		graphic.moveTo(left+1, top + logicalPosition );
		graphic.setCursorVisibility(true);
	};
	void getAllControls(vector<Control*>* controls) {
	};

	bool canGetFocus() { return true; };
};

