#pragma once
#include <vector>

class IListener;

using namespace std;

class IObserveable {

	vector<IListener*> listeners;

public:
	IObserveable() {};

	void add(IListener*);
	void notify();

};


class IListener
{
	friend class IObserveable;
private:
	virtual void action(IObserveable*) = 0;

public:
	IListener() {};

};