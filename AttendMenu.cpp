#include "AttebdMenu.h"

AttendMenu::AttendMenu(int id)
{
	m_menuName = ;
	m_ID = id;
}
AttendMenu::AttendMenu(){}


AttendMenu::~AttendMenu(){}

void AttendMenu::print()
{
	std::string name;
	std::ofstream attendees;
	attendees.open("./data/Attendees.txt",std::fstream::app);
	clearScreen();
	std::cout << "\t ===== Attending Event =====" << std::endl;
	std::cout << " Enter name: ";
	std::cin >> name;
	attendees<<m_ID<<" "<<name<<std::endl;
}

void print()const{}

std::string AttendMenu::getName() const
{
	return (m_menuName);
}

    string m_name;


};
#endif
