#include <iostream>
#include "Graphics.h"
#include <vector>

using namespace std;

/* border type virtual class */
 class BorderType{
 private:

 public:
   virtual void drawBorder(COORD, COORD) = 0;
};
