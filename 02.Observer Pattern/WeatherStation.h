#ifndef WEATHER_STATION_H
#define WEATHER_STATION_H

#include <vector>

#include "IObservable.h"

class WeatherStation : public IObservable
{
private:
	double temp = 31;
	std::vector<IObserver*> observers;

public:
	void add(IObserver* observer) override
	{
		this->observers.push_back(observer);
	}

	virtual void remove(IObserver* observer) override
	{
		this->observers.pop_back();
	}

	virtual void notify() override
	{
		for (size_t i = 0; i < this->observers.size(); i++)
		{
			this->observers[i]->update();
		}
	}

	double getTemp() const
	{
		return this->temp;
	}
};

#endif // !WEATHER_STATION_H
