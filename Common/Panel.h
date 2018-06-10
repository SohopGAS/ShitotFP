#include "Control.h"

class Panel : public Control
{
protected:
	vector<Control*>* controls;
public:
	Panel();
	~Panel();

	void Add(Control* control);
};

