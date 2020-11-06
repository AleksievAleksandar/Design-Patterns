#ifndef FACTORY_H
#define FACTORY_H

#include "Animal.h"
#include "Planet.h"

template<typename Object>
class Factory
{
	virtual Object* create(int) = 0;
};

class AnimalFactory : public Factory<Animal>
{
public:
	Animal* create(int random) override
	{
		switch (random)
		{
		case 0:
			return new Cat(5.7);
			break;
		case 1:
			return new Dog(25.7);
			break;
		case 2:
			return new Duck(1.2);
			break;

		default:
			return new Animal();
			break;
		}		
	}
};

class PlanetFactory : public Factory<Planet>
{
public:
	Planet* create(int random) override
	{
		switch (random)
		{
		case 0:
			return new Earth(5.9);
			break;
		case 1:
			return new Uranus(8.6);
			break;
		case 2:
			return new Jupiter(1.9);
			break;

		default:
			return new Planet();
			break;
		}
	}
};

#endif // !FACTORY_H
