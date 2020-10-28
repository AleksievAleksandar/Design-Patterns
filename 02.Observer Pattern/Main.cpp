#include <iostream>

#include "IObservable.h"
#include "Display.h"
#include "WeatherStation.h"

int main()
{
	WeatherStation* weatherStation = new WeatherStation();
	Display* displayOne = new Display(weatherStation);
	Display* displayTwo = new Display(weatherStation);

	weatherStation->add(displayOne);
	weatherStation->add(displayTwo);

	weatherStation->notify();

	delete displayOne;
	delete displayTwo;
	delete weatherStation;

	return 0;
}
