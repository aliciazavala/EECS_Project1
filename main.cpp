#include "Executive.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		Executive exec;
		exec.run();
	}
	else if(argc == 2 && argv[1] == "debug")
	{
		//placeholder for debug mode
	}
	std::cout << "Exiting...\n";
	return 0;
}
