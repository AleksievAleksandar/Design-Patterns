#include <iostream>

#include "Duck.h"

void printBehavior(Duck*& duck)
{
	duck->flying();
	duck->quacking();

	std::cout << "==========================\n";
}

int main()
{
	// Strategies
	Quack* quackBehavior = new Quack();
	Fly* flyBehavior = new Fly();
	CanNotFly* canNotFlyBehavior = new CanNotFly();
	// Strategies end

	Duck* duck = new Duck(quackBehavior, canNotFlyBehavior);
	Duck* duckTwo = new Duck(quackBehavior, flyBehavior);

	printBehavior(duck);
	printBehavior(duckTwo);
	
	delete quackBehavior;
	delete flyBehavior;
	delete canNotFlyBehavior;

	delete duck;
	delete duckTwo;
	
	return 0;
}
