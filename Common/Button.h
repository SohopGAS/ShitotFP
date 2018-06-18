#include "Label.h"
#include <iostream>
#include <vector>
#include "../Common/MouseListener.h"

#include "Logger.h"
using namespace std;

class Button : public Label
{
private:
	vector<MouseListener*> listeners;
public:
	Button() {};
	Button(string& s);
	~Button() {};
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }


	virtual void implement_function() {};
	void mousePressed(int x, int y, bool isLeft);
	void expand_string(string &s);
	void draw(Graphics& g, int x, int y, size_t z);
	virtual void setValue(string s) ;
};
