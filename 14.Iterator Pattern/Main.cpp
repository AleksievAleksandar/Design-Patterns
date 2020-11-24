#include <iostream>

#include "Person.h"

int main()
{
	Person person("Harry", 29);
	
	for (std::string& data : person)
	{
		std::cout << data << std::endl;
	}

	return 0;
}
