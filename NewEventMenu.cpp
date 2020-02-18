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
void NewEventMenu::print()const
{
  clearScreen();
  std::cout << "\t =====New Event for: " << m_month << "=====" << std::endl;
}
std::string NewEventMenu::getName() const
{
	return m_menuName;
}
std::string NewEventMenu::getMonth() const
{
	return m_month;
}
