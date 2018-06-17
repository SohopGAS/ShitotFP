#include "Control.h"

class Panel : public Control
{
protected:
	vector<Control*> controls;
public:
	Panel();
	~Panel();

	void draw(Graphics& g, int x, int y, size_t z);

	void Add(Control* control);
	//void getAllControls(vector<Control*>* Controls) { controls= Controls; }
};
