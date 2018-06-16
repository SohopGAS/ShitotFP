#include "Label.h"
#include <iostream>
#include "Logger.h"
using namespace std;



class Button : public Label
{

	

public:
	Button() {};
	~Button() {};

	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, int x, int y, size_t z);

};

