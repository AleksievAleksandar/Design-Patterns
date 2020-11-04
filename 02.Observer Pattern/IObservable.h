#ifndef I_OBSERVABLE_H
#define I_OBSERVABLE_H

class IObserver
{
public:
	virtual void update() = 0;
	virtual ~IObserver() = default;
};

class IObservable
{
public:
	virtual void add(IObserver* observer) = 0;
	virtual void remove(IObserver* observer) = 0;
	virtual void notify() = 0;
	virtual ~IObservable() = default;
};

#endif // !I_OBSERVABLE_H
