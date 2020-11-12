#include <iostream>

#include "Duck.h"
#include "Turkey.h"
#include "TurkeyAdapter.h"

void printInfo(Duck* obj)
{
	std::cout << obj->fly();
	std::cout << obj->quack() << std::endl;
}

void printInfo(Turkey* obj)
{
	std::cout << obj->fly();
	std::cout << obj->gobble() << std::endl;
}

int main()
{
	Duck* mallarDuck = new MallardDuck();
	printInfo(mallarDuck);

	Turkey* turkey = new WildTurkey();
	printInfo(turkey);

	Duck* turkeyAdaptor = new TurkeyAdapter(turkey);
	printInfo(turkeyAdaptor);

	delete mallarDuck;
	delete turkey;
	delete turkeyAdaptor;

	return 0;
}
