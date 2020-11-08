#ifndef PREDATOR_H
#define PREDATOR_H

enum class PredatorType
{
	TIGER   = 1,
	PUMA    = 2,
	LION    = 3,

	UNKNOWN = 255
};

class Predator
{
protected:
	double weight;
	PredatorType predatorType;

public:
	Predator() :
		weight(0), predatorType(PredatorType::UNKNOWN) {}

	Predator(double weight, PredatorType type) :
		weight(weight), predatorType(type) {}
};

class Tiger : public Predator
{
public:
	Tiger(double weight) :
		Predator(weight, PredatorType::TIGER) {}
};

class Lion : public Predator
{
public:
	Lion(double weight) :
		Predator(weight, PredatorType::LION) {}
};

class Puma : public Predator
{
public:
	Puma(double weight) :
		Predator(weight, PredatorType::PUMA) {}
};

#endif // !1
