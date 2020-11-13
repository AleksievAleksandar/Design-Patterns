#ifndef TUNER_H
#define TUNER_H

#include "IHomeCinema.h"

#include <string>

class Tuner : public IHomeCinema
{
private:
	bool isTurnedOn;
	IHomeCinema* amplifier;
public:
	Tuner() = default;
	Tuner(IHomeCinema* amplifier) :
		isTurnedOn(false), amplifier(amplifier) {}
public:
	void turnOn() override
	{
		this->isTurnedOn = true;
	}
	void turnOff() override
	{
		this->isTurnedOn = false;
	}
	void setEquipment() override
	{
		this->amplifier->turnOn();
	}
	void setDependencies(IHomeCinema* amplifier)
	{
		this->amplifier = amplifier;
	}
	std::string getInfo() override
	{
		return this->isTurnedOn == true ? "Tuner is turned on\n" : "Tuner is turned Off\n";
	}
};

#endif // !TUNER_H
