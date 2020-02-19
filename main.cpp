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
	else if(argc == 2 && std::string(argv[1]) == "test")
	{
		Executive exec;
		exec.run(1);
	}
	std::cout << "Exiting...\n";
	return 0;
}
