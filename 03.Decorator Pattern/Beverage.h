#ifndef BEVERAGE_H
#define BEVERAGE_H

class Beverage
{
public:
	virtual double cost() = 0;
	virtual ~Beverage() = default;
};

class AddDecorator : public Beverage
{
public:
	virtual double cost() = 0;
	virtual ~AddDecorator() = default;
};

class Espresso : public Beverage
{
public:
	double cost() override
	{
		return 1.5;
	}
};

class Caramel : public AddDecorator
{
protected:
	Beverage* beverage;

public:
	Caramel(Beverage* beverage) :
		beverage(beverage) {}
	~Caramel()
	{
		delete this->beverage;
	}
public:
	double cost() override
	{
		return this->beverage->cost() + 2.3;
	}
};

class Milk : public AddDecorator
{
protected:
	Beverage* beverage;

public:
	Milk(Beverage* beverage) :
		beverage(beverage) {}
	~Milk()
	{
		delete this->beverage;
	}
public:
	double cost() override
	{
		return this->beverage->cost() + 1.4;
	}
};

#endif // !BEVERAGE_H
