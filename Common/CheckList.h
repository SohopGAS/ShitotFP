#pragma once
#include "../Common/Panel.h"

/// public panel 
class CheckList:public Panel
{
	// using controls form panel - using labels
	vector <bool> optionsSelected;
	int logicalPosition = 0;


public:
	CheckList();

	~CheckList();
	void draw(Graphics& g, short x, short y, size_t z);
	//int getSize() { return _options.size(); };
	void keyDown(WORD keyCode, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	void SetList(vector<string> ListOfStrings);
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	void selectOption();
	vector<size_t> GetSelectedIndexs();
	bool indexInVector();
	void focusOn() {
		OutputDebugStringW(L"focus on checklist\n");
		graphic.moveTo(left+1, top + logicalPosition );
		//graphic.setCursorVisibility(true);

	};
	

	bool canGetFocus() { return true; };
};

