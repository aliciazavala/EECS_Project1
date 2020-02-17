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

void MainMenu::print() const
{
	clearScreen();
	std::cout << "\t===== "<< getCurrentYear() << " CALENDAR =====\n";
	std::cout << "Chose a month:\n";
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "[" << i << "] " << nameOfMonth(i) << std::endl;
		
		if(i == 12)
		{
			std::cout <<  "[0] Quit" << std::endl;
		}
	}
}

