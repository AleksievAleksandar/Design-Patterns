#ifndef DVD_PLAYER_H
#define DVD_PLAYER_H

#include "IHomeCinema.h"

#include <string>

class DVDPlayer : public IHomeCinema
{
private:
	bool isTurnedOn;
	IHomeCinema* amplifier;
public:
	DVDPlayer() = default;
	DVDPlayer(IHomeCinema* amplifier) :
		isTurnedOn(false), amplifier(amplifier) {}
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
		this->amplifier->turnOn();
	}
	void setDependencies(IHomeCinema* amplifier)
	{
		this->amplifier = amplifier;
	}
	std::string getInfo()
	{
		return this->isTurnedOn == true ? "DVD Player is turned on\n" : "DVD Player is turned Off\n";
	}
};

#endif // !DVD_PLAYER_H