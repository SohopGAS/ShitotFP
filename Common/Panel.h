#include "Control.h"

class Panel : public Control
{
protected:
	vector<Control*> controls;
public:
	Panel() {};
	~Panel() {};

	void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) ;
	virtual void keyDown(int keyCode, char charecter) ;


	void Add(Control* control);
	//void getAllControls(vector<Control*>* Controls) { controls= Controls; }
};

