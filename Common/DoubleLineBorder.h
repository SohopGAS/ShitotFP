#pragma once

#include <iostream>
#include "Graphics.h"
#include <vector>
#include <windows.h>
#include "BorderType.h"

#define TOP_LEFT_CORNER '\xC9'
#define TOP_RIGHT_CORNER '\xBB'
#define BTM_LEFT_CORNER '\xC8'
#define BTM_RIGHT_CORNER '\xBC'
#define LINE_VERTICAL '\xBA'
#define LINE_HORIZONTAL '\xCD'

class DoubleLineBorder : public BorderType {

private:
	static BorderType* instance;

public:
	void drawBorder(COORD start, COORD size);
	DoubleLineBorder() {};

	static BorderType* getinstance();
	~DoubleLineBorder();

};
