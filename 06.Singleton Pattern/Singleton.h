#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>
#include <iostream>

class Singleton
{
private:
	static Singleton* singleton;
public:
	int value;
private:
	Singleton() = default;
	Singleton(const Singleton& other) = delete;
	~Singleton() = default;
private:
	Singleton& operator=(const Singleton& other) = delete;
public:
	static Singleton*& getSingleton()
	{
		if (Singleton::singleton == nullptr)
		{
			Singleton::singleton = new Singleton();
		}
		return Singleton::singleton;
	}

	static void releaseMemory()
	{
		if (Singleton::singleton != nullptr)
		{
			delete Singleton::singleton;
			Singleton::singleton = nullptr;
		}
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
		if (Singleton::singleton != nullptr)
		{
			delete Singleton::singleton;
			Singleton::singleton = nullptr;
		}		
	}
};

#endif // !SINGLETON_H

