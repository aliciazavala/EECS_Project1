#include "Executive.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		Executive exec;
		exec.run();
	}
	std::cout << "Exiting...\n";
	return 0;
}
