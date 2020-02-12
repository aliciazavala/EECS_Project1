#include "Display.h"

Display::Display()
{
	m_xPos = 0;
	m_yPos = 0;
	m_history = new Stack<int>;
	
}

int Display::getCurrent() const
{
	return (m_history->peek());
}

int Display::back() const
{
	if(!m_history->isEmpty())
	{
		m_history->pop();
		return (m_history->peek());
	}
	return MAIN_MENU;
}

void drawMenu(int menuID)
{
	switch (menuID)
	{
		case MAIN_MENU:
			break;
		default:
			break;
	}
}

void clear()
{	
	std::system("clear");
}

void handleMainMenu()
{
	
}
