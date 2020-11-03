#include <iostream>

#include "Beverage.h"

int main()
{
	Beverage* beverage = new Milk(new Caramel(new Espresso));
	std::cout << beverage->cost() << std::endl;

	Beverage* secondBeverage = new Caramel(new Espresso);
	std::cout << secondBeverage->cost() << std::endl;

	delete beverage;
	delete secondBeverage;

	return 0;
}
