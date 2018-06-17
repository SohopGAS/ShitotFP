#include <iostream>
#include "Graphics.h"
#include "BorderType.h"



class SingleLineBorder : public BorderType {
private:
	static BorderType* getinstance();

public:
	void drawBorder(COORD start, COORD size);
	static BorderType* instance;
	SingleLineBorder() {};

	~SingleLineBorder();
};
