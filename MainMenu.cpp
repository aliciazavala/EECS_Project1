#include "MainMenu.h"

MainMenu::MainMenu()
{
	
}

MainMenu::~MainMenu()
{
	
}

std::string MainMenu::getName() const
{
	return ("MainMenu");
}

void MainMenu::print()const
{
	
}


void MainMenu::print(int year) const
{
	clearScreen();
	std::cout << "\t===== "<< year << " CALENDAR =====\n";
	std::cout << "[b] Previous Year\tNext Year[n]\n";
	std::cout << "\tChose a month:\n";
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "[" << i << "] " << nameOfMonth(i);
		if(i == 1)
		{
			std::cout << "\t\t[s] Settings";
		}
		else if(i == 2)
		{
			std::cout << "\t\t[q] Quit";
		}
		std::cout << std::endl;
	}
		
		
}

