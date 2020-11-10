#include <iostream>
#include <vector>

#include "Singleton.h"

// Below line will automatic reliase the alocated memory of Singleton, after program terminates
//SingletonDestroyer destroyer;

Singleton* instance = Singleton::getSingleton();
Singleton* theSameInstance = Singleton::getSingleton();


int main()
{
	instance->value = 69;
	std::cout << instance->getInfo();

	Singleton::releaseMemory();

	return 0;
}
