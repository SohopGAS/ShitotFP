#include <iostream>
#include "Graphics.h"
#include <vector>
#include <windows.h>
#include "BorderType.h"



class DoubleLineBorder : public BorderType {
	void drawBorder(COORD start, COORD size);
	static BorderType* instance;
	DoubleLineBorder() {};

public:

	static DoubleLineBorder* getinstance();

};

class DoubleLineBorder
{
public:
	DoubleLineBorder();
	~DoubleLineBorder();
};
