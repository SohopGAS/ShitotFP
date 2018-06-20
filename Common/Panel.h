#include "Control.h"

class Panel : public Control
{
protected:
	vector<Control*> controls;
public:
	Panel() {};
	~Panel() {};

	void draw(Graphics& g, short x, short y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) ;
	virtual void keyDown(int keyCode, char charecter) ;

	bool canGetFocus() { return TRUE; };
	void Add(Control* control);
	void getAllControls(vector<Control*>* Controls);
};

