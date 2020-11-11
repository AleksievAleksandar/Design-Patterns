#ifndef LAMP_H
#define LAMP_H

class Lamp
{
private:
	bool isTurnOn;
public:
	Lamp() :
		isTurnOn(false) {}
public:
	void action()
	{
		this->isTurnOn = !this->isTurnOn;
	}
};

#endif // !LAMP_H
