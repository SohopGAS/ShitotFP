#include <iostream>
#include "Graphics.h"
#include <vector>
#include <windows.h>
#include "BorderType.h"

class DoubleLineBorder : public BorderType {

private:
	static BorderType* instance;

public:
	void drawBorder(COORD start, COORD size);
	DoubleLineBorder() {};

	static BorderType* getinstance();
	~DoubleLineBorder();

};
