#include "ViewEventMenu.h"
#include "NewEventMenu.h"
#include <fstream>
#include <iostream>


ViewEventMenu::ViewEventMenu(std::string eventName)
{
    m_eventName = eventName;
}

ViewEventMenu::~ViewEventMenu()
{

}

std::string ViewEventMenu::getName() const
{
  return m_eventName;
}

