#include <iostream>

#include "Gate.h"

int main()
{
	Gate* gate = new Gate();

	gate->enter();
	gate->payFailed();
	gate->payOK();

	delete gate;
	return 0;
}
