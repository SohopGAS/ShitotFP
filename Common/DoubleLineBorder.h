#pragma once

#include <iostream>
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
	DoubleLineBorder() {};

public:
	void drawBorder(Graphics& g,short start_x, short start_y, short width, short height);


	static BorderType* getinstance();
	~DoubleLineBorder();

};
