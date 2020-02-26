#include "MainMenu.h"

MainMenu::MainMenu()
{
	//empty constructor
}

MainMenu::~MainMenu()
{
	//empty destructor
}

std::string MainMenu::getName() const
{
	return ("MainMenu");
}

void MainMenu::print()const
{
	
}


void MainMenu::print(int year) const //this function displays the main menu of the program in a formatted way.
{
	clearScreen();
	std::cout << "\t===== "<< year << " CALENDAR =====\n";
	std::cout << "[b] Previous Year\tNext Year[n]\n";
	std::cout << "\tChose a month:\n";
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "[" << i << "] " << nameOfMonth(i); //prints the name of the month with the corresponding number by it
		if(i == 1)
		{
			std::cout << "\t\t[s] Settings"; //prints settings option on same line as january
		}
		else if(i == 2)
		{
			std::cout << "\t\t[q] Quit"; //prints quit option on same line as february
		}
		std::cout << std::endl;
	}
		
		
}

