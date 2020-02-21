#include "ViewEventMenu.h"

ViewEventMenu::ViewEventMenu()
{
  m_menuName= "ViewEventMenu";
}

ViewEventMenu::~ViewEventMenu()
{
  
}

void ViewEventMenu::print() const
{
	clearScreen();	
}	

std::string ViewEventMenu::getName() const
{
	return m_menuName;
}
