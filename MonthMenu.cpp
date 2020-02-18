#include "MonthMenu.h"

MonthMenu::MonthMenu()
{
	m_menuName = "MonthMenu";
	totalEvents = 0; //placeholder
}

MonthMenu::~MonthMenu()
{
	
}

void MonthMenu::print() const
{
	
}

void MonthMenu::print(int month, int year) const
{
	clearScreen();
	std::cout << "\t ===== Events for " << nameOfMonth(month) << " " << year << " =====" << std::endl;
	for(int i = 1; i <= totalEvents; i++)
	{
		//print every event name
		if(i == totalEvents)
		{
			std::cout << "[" << i + 1 << "] New Event" << std::endl;
		}
	}
	if(totalEvents == 0)
	{
		std::cout << "[1] New Event" << std::endl;
	}
	std::cout << "[0] Back" << std::endl;
}

std::string MonthMenu::getName() const
{
	return m_menuName;
}

//m_month + ".txt" for file name
