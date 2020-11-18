#ifndef TV_H
#define TV_H

#include <iostream>

struct IDevice
{
	virtual void buttonOne() = 0;
	virtual void buttonTwo() = 0;
	virtual ~IDevice() = default;
};

class SimpleTV : public IDevice
{
	int volumeLevel;
public:
	SimpleTV() :
		volumeLevel(0) {}
public:
	void buttonOne() override
	{
		std::cout << "Simple TV volume UP\n";
		this->volumeLevel++;
	}
	void buttonTwo() override
	{
		std::cout << "Simple TV volume DOWN\n";
		this->volumeLevel--;
	}
};

class ComplexTV : public IDevice // let's says that this class is for TV and DVD Player in one
{
	bool hasInsertedDisk;
public:
	ComplexTV() :
		hasInsertedDisk(false) {}
public:
	void buttonOne() override
	{
		std::cout << "Complex TV - disk inserted\n";
		this->hasInsertedDisk = true; // insert disk
	}
	void buttonTwo() override
	{
		std::cout << "Complex TV - disk ejected\n";
		this->hasInsertedDisk = false; // insert disk
	}
};

#endif // !TV_H
