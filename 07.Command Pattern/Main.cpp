#include <iostream>

#include "Invoker.h"

int main()
{
	Lamp lamp;
	Invoker* invoker = new Invoker(new OnCommand(lamp), new OffCommand(lamp));
	invoker->turnOn();
	invoker->turnOff();

	delete invoker;
	return 0;
}
