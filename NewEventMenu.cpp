#include"NewEventMenu.h"
NewEventMenu::NewEventMenu(int monthEvent)
{
  m_menuName = "NewEventMenu";
  m_month = nameOfMonth(monthEvent);
}
NewEventMenu::~NewEventMenu()
{

}
NewEventMenu::NewEventMenu(const NewEventMenu& original)
{
  m_menuName = original.m_menuName;
  m_month = original.m_month;
}
void NewEventMenu::print(int& m_month, int& m_year)const
{
  clearScreen();
  std::cout << "\t =====New Event for: " << nameOfMonth(m_month) <<" "<<m_year<< "=====" << std::endl;
}
void NewEventMenu::print()const
{

}
std::string NewEventMenu::getName() const
{
	return m_menuName;
}
std::string NewEventMenu::getMonth() const
{
	return m_month;
}
