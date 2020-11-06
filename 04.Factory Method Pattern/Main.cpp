#include <iostream>
#include <cstdlib>

#include "Animal.h"
#include "Planet.h"
#include "Factory.h"

#include <vector>

int main()
{
	std::vector<Animal*> animals;
	AnimalFactory animalFactory;

	for (size_t i = 0; i < 5; i++)
	{
		int random = rand() % 3;
		animals.push_back(animalFactory.create(random));
	}

	std::vector<Planet*> planets;
	PlanetFactory planetFactory;

	for (size_t i = 0; i < 5; i++)
	{
		int random = rand() % 3;
		planets.push_back(planetFactory.create(random));
	}


	//remove created obj
	for (size_t i = 0; i < 5; i++)
	{
		delete animals[i];
		delete planets[i];
	}
	return 0;
}
