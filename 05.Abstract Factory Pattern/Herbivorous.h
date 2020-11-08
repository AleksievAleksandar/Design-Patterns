#ifndef HERBIVOROUS_H
#define HERBIVOROUS_H

enum class HerbivorousType
{
	HORSE  = 1,
	COW     = 2,
	DEER    = 3,
	UNKNOWN = 255
};

class Herbivorous
{
protected:
	double weight;
	HerbivorousType herbivorousType;
public:
	Herbivorous() :
		weight(0), herbivorousType(HerbivorousType::UNKNOWN) {}

	Herbivorous(double weight, HerbivorousType type) :
		weight(weight), herbivorousType(type) {}
};

class Horse : public Herbivorous
{
public:
	Horse(double weight) :
		Herbivorous(weight, HerbivorousType::HORSE) {}
};

class Cow : public Herbivorous
{
public:
	Cow(double weight) :
		Herbivorous(weight, HerbivorousType::COW) {}
};

class Deer : public Herbivorous
{
public:
	Deer(double weight) :
		Herbivorous(weight, HerbivorousType::DEER) {}
};

#endif // !HERBIVOROUS_H
