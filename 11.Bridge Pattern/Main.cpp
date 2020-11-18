#include <iostream>

#include "RemoteControl.h"
#include "TV.h"

int main()
{
	SimpleTV* tv = new SimpleTV();
	RemoteControlForDevices* remoteConstrol = new RemoteControlForDevices(tv);
	remoteConstrol->buttonOne();
	remoteConstrol->buttonTwo();

	ComplexTV* complexTV = new ComplexTV();
	RemoteControlForDevices* remoteControlForComplexDevices = new RemoteControlForDevices(complexTV);
	remoteControlForComplexDevices->buttonOne();
	remoteControlForComplexDevices->buttonTwo();

	delete tv;
	delete remoteConstrol;

	delete complexTV;
	delete remoteControlForComplexDevices;

	return 0;
}
