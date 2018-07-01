#pragma once
#ifndef BORDERTYPE_H
#define BORDERTYPE_H


#include <iostream>
#include "Graphics.h"

#include <vector>

using namespace std;

/* border type virtual class */
 class BorderType{
 public:
	virtual void drawBorder(Graphics& g,short start_x, short start_y, short width, short height) = 0;
};

#endif 

