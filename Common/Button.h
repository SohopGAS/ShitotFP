#include "Label.h"
#include <iostream>
#include "Logger.h"
#include  "ActionListener.h"
using namespace std;



class Button : public Label
{

	

public:
	Button() {};
	Button(string& s);
	~Button() {};

	void mousePressed(int x, int y, bool isLeft);
	void expand_string(string &s);
	void draw(Graphics& g, int x, int y, size_t z);
	virtual void setValue(string s) ;
};

