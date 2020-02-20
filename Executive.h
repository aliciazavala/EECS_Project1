#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include<iostream>
#include<fstream>
#include<string.h>
#include "Event.h"
#include "Calendar.h"
#include "Menu.h"
#include "MainMenu.h"
#include "MonthMenu.h"
#include "StackInterface.h"
#include "Stack.h"
#include "NewEventMenu.h"
#include "SettingsMenu.h"
#include "TimeMenu.h"
#include "ViewEventMenu.h"


class Executive
{
	public:
	Executive();
	~Executive();

	void run();

	private:
	//Current state
	int m_loadedYear;
	int m_loadedMonth;
	bool m_militaryTime;
	std::string m_eventId; 
	int m_loadedDay;

	//std::string m_fileName;
	Calendar* m_calendar;
	Stack<Menu*>* m_menuStack;


	bool load();
	void save();

	void handleMainMenu();
	void handleMonthMenu();
	void handleNewEventMenu();
	void handleViewEventMenu();
	void handleSettingsMenu();
	void handleTimeMenu();
	void handleBack();
	int EventsInMonth(int month);


};

#endif
