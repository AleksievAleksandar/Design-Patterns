#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>
#include <iostream>

class Singleton
{
public:
	int value;
private:
	static Singleton* singleton;

private:
	Singleton() = default;
	Singleton(const Singleton& other) = delete;
	~Singleton() = default;

private:
	Singleton operator=(const Singleton& other) = delete;

public:
	static Singleton* getSingleton()
	{
		if (singleton == nullptr)
		{
			singleton = new Singleton();
		}
		return singleton;
	}

	static void releaseMemory()
	{
		delete Singleton::singleton;
	}

	std::string getInfo() const
	{
		return "I'm alive and unique!";
	}

	friend class SingletonDestroyer;
};

Singleton* Singleton::singleton = nullptr;

class SingletonDestroyer {
public:
	~SingletonDestroyer()
	{ 
		delete Singleton::singleton; 
	}
};

#endif // !SINGLETON_H
