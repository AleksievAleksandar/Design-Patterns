#include <iostream>

#include "Gate.h"

int main()
{
	Gate* gate = new Gate();
	gate->payOK();
	delete gate;
  
	return 0;
}
