#ifndef COMMAND_H
#define COMMAND_H

#include "Lamp.h"

struct ICommand
{
	virtual void execute() = 0;
	virtual void unExecute() = 0;
	virtual ~ICommand() = default;
};

class OnCommand : public ICommand
{
private:
	Lamp& lamp;
public:
	OnCommand(Lamp& lamp) :
		lamp(lamp) {}
public:
	void execute() override
	{
		this->lamp.action();
	}
	void unExecute() override
	{
		this->lamp.action();
	}
};

class OffCommand : public ICommand
{
private:
	Lamp& lamp;
public:
	OffCommand(Lamp& lamp):
		lamp(lamp) {}
public:
	void execute() override
	{
		this->lamp.action();
	}
	void unExecute() override
	{
		this->lamp.action();
	}
};

#endif // !COMMAND_H
