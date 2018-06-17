#pragma once

#include <iostream>
#include "Graphics.h"
#include "BorderType.h"

#define TOP_LEFT '\xDA'
#define TOP_RIGHT '\xBF'
#define BTM_LEFT '\xC0'
#define BTM_RIGHT '\xD9'
#define LINE_VERTICAL '\xB3'
#define LINE_HORIZONTAL '\xC4'

class SingleLineBorder : public BorderType {
private:
	void drawBorder(short start_x, short start_y, short width, short height);
	static BorderType* instance;
	SingleLineBorder() {};

public:
	static BorderType* getinstance();

	~SingleLineBorder();
};
