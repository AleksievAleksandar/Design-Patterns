#ifndef I_HOME_CINEMA_H
#define I_HOME_CINEMA_H

struct IHomeCinema
{
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual std::string getInfo() = 0;
	virtual void setEquipment() = 0;
	virtual ~IHomeCinema() = default;
};

#endif // !I_HOME_CINEMA_H
