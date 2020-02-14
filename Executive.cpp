#include "Executive.h"

Executive::Executive()
{
	//both should be empty at startup
	m_calendar = nullptr;
	m_menuStack = nullptr;
	
	m_fileName = "data.txt"; //file name should be constant
}

Executive::~Executive()
{
	if(m_calendar != nullptr)
	{
		delete m_calendar;
	}
	if(m_menuStack != nullptr)
	{
		delete m_menuStack;
	}
}

void Executive::run()
{
	if(load())//executes load
	{
		m_menuStack = new Stack<Menu>;
		pushMenu("MainMenu");
		
	}
	while(!m_menuStack->isEmpty())//loops as long as there are menus
	{
		
	}
	save();
}

bool Executive::load()
{
	//read from file then return true or return false if file cannot be openned

	int eventsLoaded = 1;//should be read from file
	m_calendar = new Calendar(eventsLoaded);

	return true;//placeholder return
}

void Executive::save()
{
	//save to file
	//possible feature: encrypt the save file to prevent it from being read or altered
	//			ex: convert chars to bits (8 bits) and then use XOR encryption
	//				   x XOR key = y, where x, y, and key are 8bit strings
	//				=> y XOR key = x


	std::cout << "save complete\n";//placeholder return
}

void Executive::pushMenu(std::string menuName)
{
	
}
