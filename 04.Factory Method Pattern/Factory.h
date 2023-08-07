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
		case 1:
			return new Dog(25.7);
		case 2:
			return new Duck(1.2);

		default:
			return new Animal();
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
		case 1:
			return new Uranus(8.6);
		case 2:
			return new Jupiter(1.9);

		default:
			return new Planet();
		}
	}
};

#endif // !FACTORY_H
