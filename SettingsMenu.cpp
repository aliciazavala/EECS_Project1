#include "SettingsMenu.h"

SettingsMenu::SettingsMenu()
{
	menuName = "SettingsMenu"; //sets current menu name to "SettingsMenu"
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

void SettingsMenu::print(bool militaryTime, bool hideTimes) const
{
	clearScreen();
	std::cout << "\t===== SETTINGS =====\n";
	std::cout << "Current time: \n";///implement time
	if(militaryTime)
	{
		std::cout << "[1] Turn OFF 24-hour time";
	}
	else
	{
		std::cout << "[1] Turn ON 24-hour time";
	}
	std::cout << std::endl;
	if(hideTimes)
	{
		std::cout << "[2] Hide attendee times in Admin Mode";
	}
	else
	{
		std::cout << "[2] Show attendee times in Admin Mode";
	}
	clearScreen(5);
	std::cout << "\n[0] Back\n";
	
}
