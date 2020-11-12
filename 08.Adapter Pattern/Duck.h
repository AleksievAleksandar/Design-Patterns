#ifndef DUCK_H
#define DUCK_H

#include <string>

struct Duck
{
	virtual std::string quack() = 0;
	virtual std::string fly() = 0;
	virtual ~Duck() = default;
};

class MallardDuck : public Duck
{
public:
	std::string quack() override
	{
		return "quaaaack\n";
	}
	std::string fly() override
	{
		return "I'm flying over the clouds\n";
	}
};

#endif // !DUCK_H
