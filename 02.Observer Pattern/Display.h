#ifndef DISPLAY_H
#define DISPLAY_H

#include "IObservable.h"
#include "WeatherStation.h"

class Display : public IObserver
{
private:
	WeatherStation*& station;
	double tempToDisplay = 0;

public:
	Display(WeatherStation*& station) :
		station(station) {}

	void update() override
	{
		this->tempToDisplay = this->station->getTemp();
	}
};

#endif // !DISPLAY_H
