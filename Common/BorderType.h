#include <iostream>
#include "Graphics.h"
#include <vector>



using namespace std;

/* border type virtual class */
 class BorderType{
 public:
	virtual void drawBorder(COORD, COORD) = 0;
	
};

 class BorderType
 {
 public:
	 BorderType();
	 ~BorderType();
 };


