#include "AttendMenu.h"
//attendMenu constructor
AttendMenu::AttendMenu(int id)
{
	m_menuName = "AttendMenu";
	m_ID = id;
}
AttendMenu::AttendMenu(){
  m_menuName = "AttendMenu";
}

//Empty destructor
AttendMenu::~AttendMenu(){}
//This method Opens attendees file, takes attendee's name and writes it to file
void AttendMenu::print()
{
	std::string name;
	std::ofstream attendees;
	attendees.open("./data/Attendees.txt",std::fstream::app);
	clearScreen();
	std::cout << "\t ===== Attending Event =====" << std::endl;
	std::cout << " Enter name: ";
	std::cin.ignore();
	std::getline(std::cin,name);
	attendees<<m_ID<<" "<<name<<std::endl;//write the event ID first and then the attendee's name to file

	attendees.close();
}

void AttendMenu::print()const{}//virtual print(not used)

std::string AttendMenu::getName() const
{
	return (m_menuName);//Getter for the name of the menu
}
