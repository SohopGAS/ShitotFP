#include <iostream>
#include "Graphics.h"
#include "BorderType.h"



class SingleLineBorder : public BorderType {
	void drawBorder(COORD start, COORD size);
	static BorderType* instance;
	SingleLineBorder() {};

public:

	static SingleLineBorder* getinstance();

};

class SingleLineBorder
{
public:
	SingleLineBorder();
	~SingleLineBorder();
};
