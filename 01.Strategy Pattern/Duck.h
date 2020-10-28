#ifndef DUCK_H
#define DUCK_H

#include <iostream>

class Duck
{
public:
	class IQuackBehavior
	{
	public:
		virtual void apply() = 0;
	};
	class IFlyBehavior
	{
	public:
		virtual void apply() = 0;
	};

private:
	IQuackBehavior* quackBehavior;
	IFlyBehavior* flyBehavior;

public:
	Duck(IQuackBehavior* quackBeh, IFlyBehavior* flyBeh) :
		quackBehavior(quackBeh),
		flyBehavior(flyBeh) {}

	void quacking() const
	{
		this->quackBehavior->apply();
	}
	void flying() const
	{
		this->flyBehavior->apply();
	}
};

class Fly : public Duck::IFlyBehavior
{
public:
	void apply() override
	{
		std::cout << "I Fly\n";
	}
};

class CanNotFly : public Duck::IFlyBehavior
{
public:
	void apply() override
	{
		std::cout << "I can not fly\n";
	}
};

class Quack : public Duck::IQuackBehavior
{
public:
	void apply() override
	{
		std::cout << "Quackkkkkk\n";
	}
};

#endif // !DUCK_H
