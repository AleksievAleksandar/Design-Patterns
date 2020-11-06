#ifndef ANIMAL_H
#define ANIMAL_H

enum class AnimalTypes
{
	CAT     = 1,
	DOG     = 2,
	DUCK    = 3,

	UNKNOWN = 255
};

class Animal
{
public:
	Animal() :
		weight(0), animalType(AnimalTypes::UNKNOWN) {}

	Animal(double weight, AnimalTypes animalType) :
		weight(weight), animalType(animalType) {}

protected:
	double weight;
	AnimalTypes animalType;
};

class Dog : public Animal
{
public:
	Dog(double weight) :
		Animal(weight, AnimalTypes::DOG) {}
};

class Cat : public Animal
{
public:
	Cat(double weight) :
		Animal(weight, AnimalTypes::CAT) {}
};

class Duck : public Animal
{
public:
	Duck(double weight) :
		Animal(weight, AnimalTypes::DUCK) {}
};

#endif // !ANIMAL_H
