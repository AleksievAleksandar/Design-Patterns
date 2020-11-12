#ifndef TURKEY_H
#define TURKEY_H

#include <string>

struct Turkey
{
	virtual std::string gobble() = 0;
	virtual std::string fly() = 0;
	virtual ~Turkey() = default;
};

class WildTurkey : public Turkey
{
public:
	std::string gobble() override
	{
		return "I'm gobble.\n";
	}
	std::string fly() override
	{
		return "I'm turkey and I'm flying.\n";
	}
};

#endif // !TURKEY_H
