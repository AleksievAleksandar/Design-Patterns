#include <iostream>

#include "Factory.h"

int main()
{
	AnimalFactory factory;

	Predator* predator = factory.createPredator();
	Herbivorous* herbivorous = factory.createHerbivorous();

	delete predator;
	delete herbivorous;

	return 0;
}
