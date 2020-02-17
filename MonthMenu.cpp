#include "MonthMenu.h"

MonthMenu::MonthMenu(int month)
{
	m_menuName = "MonthMenu";
	m_month = nameOfMonth(month);
	totalEvents = 0; //placeholder
}

MonthMenu::~MonthMenu()
{
	
}

void MonthMenu::print() const
{
	clearScreen();
	std::cout << "\t =====Events for " << m_month << "=====" << std::endl;
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

std::string MonthMenu::getMonth() const
{
	return m_month;
} 
//m_month + ".txt" for file name
