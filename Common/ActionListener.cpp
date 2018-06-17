#include "ActionListener.h"

using namespace std;

void IObserveable::add(IListener* l)
{
	listeners.push_back(l);
}

void IObserveable::notify()
{
	for (auto l : this->listeners)
	{
		l->action(this);
	}
}