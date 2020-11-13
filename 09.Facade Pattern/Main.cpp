#include <iostream>

#include "HomeCinemaFacade.h"

int main()
{
	Amplifier* amplifier = new Amplifier();
	DVDPlayer* dvdPlayer = new DVDPlayer();
	Tuner* tuner = new Tuner();

	HomeCinemaFacade system(amplifier, dvdPlayer, tuner);
	system.turnOnTheSystem();
	system.turnoOffTheSystem();

	return 0;
}
