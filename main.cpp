/**
*	@file main.cpp
*	@brief creates executive object, executes the executive::run object
*
*	@author Manuel Sadoval, Angel Guerrero, Alicia Zavala, Elena Zavala, Joseph Duong
*	@date 2/21/20
*
*/

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
