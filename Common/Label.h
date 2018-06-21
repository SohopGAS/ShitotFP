#include "Control.h"
#include "Graphics.h"
#include <string>


using namespace std;

class Label : public Control
{
private:
	string value="";
public:
	Label() {};
	Label(string);
	string getValue() { return value; };
	void setValue(string);
	void draw(Graphics& g, short x, short y, size_t z);
	void getAllControls(vector<Control*>* controls) {};
	virtual void keyDown(WORD keyCode, char charecter) {};

	void mousePressed(int x, int y, bool isLeft) {};
	bool myPureFunction() {}

};
