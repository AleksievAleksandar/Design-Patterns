#ifndef AMPLIFIER_H
#define AMPLIFIER_H

#include "IHomeCinema.h"

#include <string>

class Amplifier : public IHomeCinema
{
private:
	bool isTurnedOn;
	IHomeCinema* tuner;
public:
	Amplifier() = default;
	Amplifier(IHomeCinema* tuner) :
		isTurnedOn(false), tuner(tuner) {}
public:
	void turnOn()
	{
		this->isTurnedOn = true;
	}
	void turnOff()
	{
		this->isTurnedOn = false;
	}
	void setEquipment() override
	{
		this->tuner->turnOn();
	}
	void setDependencies(IHomeCinema* tuner)
	{
		this->tuner = tuner;
	}
	std::string getInfo()
	{
		return this->isTurnedOn == true ? "Amplifier is turned on\n" : "Amplifier is turned Off\n";
	}
};

#endif // !AMPLIFIER_H
