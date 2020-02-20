#include "Event.h"

Event::Event()
{
	m_month = "January";//placeholder
}

void Event::setMonth(std::string month)
{
    m_month = month;
}

std::string Event::getMonth() const
{
    return m_month;
}

int Event::getID() const
{
	return m_ID;
}

void Event::setID(int num)
{
	m_ID = num;
}
