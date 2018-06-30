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
	
	void draw(Graphics& g, short x, short y, size_t z);
	void keyDown(WORD  code, char charecter);
	void mousePressed(int x, int y, bool isLeft);
	boolean SelectedItem(int index);
	boolean ClearSelection();

	// return label value 
	//string getResult() { return lab1.getValue();  };

	bool canGetFocus() { return true; };

	void focusOn() {
		OutputDebugStringW(L"focus on RadioBox\n");
		graphic.moveTo(left + 1, top + logicalPosition);
		graphic.setCursorVisibility(true);
	};

	void SetList(vector<string> ListOfStrings);

	void selectOption();


};

