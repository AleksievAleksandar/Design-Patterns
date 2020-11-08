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
			break;
		case 1:
			return new Lion(65);
			break;
		case 2:
			return new Puma(30);
			break;

		default:
			return new Predator();
			break;
		}
	}

	Herbivorous* createHerbivorous() override
	{
		int randomNumber = rand() % 2;

		switch (randomNumber)
		{
		case 0:
			return new Cow(270);
			break;
		case 1:
			return new Horse(125);
			break;
		case 2:
			return new Deer(40);
			break;

		default:
			return new Herbivorous();
			break;
		}
	}
};

#endif // !FACTORY_H
