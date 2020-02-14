#include "MainMenu.h"

void MainMenu::print() const
{
	std::cout << "\t=====CALENDAR APP=====";
	std::cout << "Chose a month: ";
	for (int i = 1; i <= 12; i++)
	{
		std::cout << "[" << i << "] " << getMonthName(i) << std::endl;
	}
}
