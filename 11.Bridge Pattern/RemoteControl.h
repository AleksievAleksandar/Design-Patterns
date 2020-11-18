#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include "TV.h"

class IRemoteControl
{
protected:
	IDevice* device;
public:
	IRemoteControl(IDevice* device) :
		device(device) {}
	virtual ~IRemoteControl() = default;
	virtual void buttonOne() = 0;
	virtual void buttonTwo() = 0;
};

class RemoteControlForDevices : public IRemoteControl
{
public:
	RemoteControlForDevices(IDevice* device) :
		IRemoteControl(device) {}
public:
	void buttonOne() override
	{
		this->device->buttonOne();
	}
	void buttonTwo() override
	{
		this->device->buttonTwo();
	}
};

#endif // !REMOTE_CONTROL_H
