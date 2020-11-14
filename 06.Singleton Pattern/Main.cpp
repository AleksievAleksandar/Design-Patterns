#include <iostream>
#include <vector>

#include "Singleton.h"

// Below line will automatic reliase the alocated memory of Singleton, after program terminates
//SingletonDestroyer destroyer;

//Singleton*& instance = Singleton::getSingleton();
//Singleton*& theSameInstance = Singleton::getSingleton();

int main()
{
	Singleton::getSingleton()->value = 15;
	std::cout << Singleton::getSingleton()->getInfo();
	Singleton::releaseMemory();

	return 0;
}
