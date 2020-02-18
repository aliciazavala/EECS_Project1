#include "SettingsMenu.h"

SettingsMenu::SettingsMenu()
{
	menuName = "SettingsMenu";
}

SettingsMenu::~SettingsMenu()
{
	//empty
}

std::string SettingsMenu::getName() const
{
	return menuName;
}

void SettingsMenu::print() const
{
	
}

void SettingsMenu::print(bool militaryTime) const
{
	clearScreen();
	std::cout << "\t===== SETTINGS =====\n";
	std::cout << "Current time: \n";///implement time
	if(militaryTime)
	{
		std::cout << "[1] Turn OFF military time";
	}
	else
	{
		std::cout << "[1] Turn ON military time";
	}
	clearScreen(5);
	std::cout << "\n[0] Back\n";
	
}
