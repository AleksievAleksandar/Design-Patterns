#ifndef TURKEY_ADAPTER_H
#define TURKEY_ADAPTER_H

#include "Duck.h"
#include "Turkey.h"

class TurkeyAdapter : public Duck
{
private:
	Turkey* turkey;
public:
	TurkeyAdapter(Turkey*& turkey) :
		turkey(turkey) {}
public:
	std::string quack() override
	{
		return "I'm adapter " + this->turkey->gobble();
	}
	std::string fly() override
	{
		return "I'm adapter " + this->turkey->fly();
	}
};

#endif // !TURKEY_ADAPTER_H
