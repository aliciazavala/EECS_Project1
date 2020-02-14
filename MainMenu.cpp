#include "MainMenu.h"

MainMenu::MainMenu()
{
	
}

MainMenu::~MainMenu()
{
	
}

void MainMenu::print() const
{
	std::cout << "\t=====CALENDAR APP=====";
	std::cout << "Chose a month: ";
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "[" << i << "] " << nameOfMonth(i) << std::endl;
	}
}
