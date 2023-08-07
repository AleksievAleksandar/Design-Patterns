#ifndef FACTORY_H
#define FACTORY_H

#include "Predator.h"
#include "Herbivorous.h"

#include <cstdlib>

class Factory
{
public:
	virtual Predator* createPredator() = 0;
	virtual Herbivorous* createHerbivorous() = 0;

	virtual ~Factory() = default;
};

class AnimalFactory : public Factory
{
public:
	Predator* createPredator() override
	{
		int randomNumber = rand() % 2;

		switch (randomNumber)
		{
		case 0:
			return new Tiger(70);
		case 1:
			return new Lion(65);
		case 2:
			return new Puma(30);

		default:
			return new Predator();
		}
	}

	Herbivorous* createHerbivorous() override
	{
		int randomNumber = rand() % 2;

		switch (randomNumber)
		{
		case 0:
			return new Cow(270);
		case 1:
			return new Horse(125);
		case 2:
			return new Deer(40);

		default:
			return new Herbivorous();
		}
	}
};

#endif // !FACTORY_H
