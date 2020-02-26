#include"NewEventMenu.h"
NewEventMenu::NewEventMenu(int monthEvent)
{
  m_menuName = "NewEventMenu";//assigns name
  m_month = nameOfMonth(monthEvent);//assigns name of month
}
NewEventMenu::~NewEventMenu()//Empty destructor
{}
//Copy constructor
NewEventMenu::NewEventMenu(const NewEventMenu& original)
{
  m_menuName = original.m_menuName;
  m_month = original.m_month;
}
//print method that just prints a header for the menu
void NewEventMenu::print(int& m_month, int& m_year)const
{
  clearScreen();
  std::cout << "\t =====New Event for: " << nameOfMonth(m_month) <<" "<<m_year<< "=====" << std::endl; // Prints a header for the new event
}
void NewEventMenu::print()const//virtual print(not used)
{}
std::string NewEventMenu::getName() const
{
	return m_menuName;//returns name of menu
}
std::string NewEventMenu::getMonth() const
{
	return m_month; //Returns current month
}
