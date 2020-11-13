#ifndef HOME_CINEMA_FACADE_H
#define HOME_CINEMA_FACADE_H

#include "Amplifier.h"
#include "DVDPlayer.h"
#include "Tuner.h"

class HomeCinemaFacade
{
private:
	Amplifier*& amplifier;
	DVDPlayer*& dvdPlayer;
	Tuner*& tuner;
public:
	HomeCinemaFacade(Amplifier*& amplifier, DVDPlayer*& dvdPlayer, Tuner*& tuner) :
		amplifier(amplifier), dvdPlayer(dvdPlayer), tuner(tuner) 
	{
		this->amplifier->setDependencies(this->tuner);
		this->dvdPlayer->setDependencies(this->amplifier);
		this->tuner->setDependencies(this->amplifier);
	}
	~HomeCinemaFacade()
	{
		delete this->amplifier;
		this->amplifier = nullptr;

		delete this->dvdPlayer;
		this->dvdPlayer = nullptr;

		delete this->tuner;
		this->tuner = nullptr;
	}

public:
	void turnOnTheSystem()
	{
		this->amplifier->turnOn();
		this->dvdPlayer->turnOn();
		this->tuner->turnOn();

		std::cout << this->amplifier->getInfo();
		std::cout << this->dvdPlayer->getInfo();
		std::cout << this->tuner->getInfo();
	}
	void turnoOffTheSystem()
	{
		this->amplifier->turnOff();
		this->dvdPlayer->turnOff();
		this->tuner->turnOff();

		std::cout << this->amplifier->getInfo();
		std::cout << this->dvdPlayer->getInfo();
		std::cout << this->tuner->getInfo();
	}
};

#endif // !HOME_CINEMA_FACADE_H
