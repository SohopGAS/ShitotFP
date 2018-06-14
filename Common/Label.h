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
	void draw(Graphics& g, int x, int y, size_t z);
	bool myPureFunction() {}
	
};