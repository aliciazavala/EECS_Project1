#include "ViewEventMenu.h"
#include "NewEventMenu.h"
#include <fstream>
#include <iostream>


ViewEventMenu::ViewEventMenu(int eventId)
{
    m_eventId = eventId;
}

ViewEventMenu::~ViewEventMenu()
{}

std::string ViewEventMenu::getName() const
{
  return "ViewEventMenu";
}

int ViewEventMenu::getEventId() const
{
    return m_eventId;
}

void ViewEventMenu::print()const{}
