#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"

class Invoker
{
private:
	ICommand* on;
	ICommand* off;
public:
	Invoker(ICommand* on, ICommand* off) :
		on(on), off(off) {}
	~Invoker()
	{
		delete this->on;
		delete this->off;
	}
public:
	void turnOn()
	{
		this->on->execute();
	}
	void turnOff()
	{
		this->off->execute();
	}
};

#endif // !INVOKER_H
