#include "ViewEventMenu.h"

ViewEventMenu::ViewEventMenu()
{
  m_menuName= "ViewEventMenu";
}

ViewEventMenu::~ViewEventMenu()
{
  
}

std::string ViewEventMenu::getName() const
{
	return m_menuName;
}
