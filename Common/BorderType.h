#include <iostream>
#include "Graphics.h"
#include "Control.h"
#include <vector>



using namespace std;

/* border type virtual class */
 class BorderType{
 public:
	virtual void drawBorder(COORD, COORD) = 0;
	
};


