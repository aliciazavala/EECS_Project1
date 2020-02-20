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
#include "project1_lib.h"



class Executive
{
	public:
	Executive();
	~Executive();

	void run(bool test = 0);

	private:
	//Current state
	int m_loadedYear;
	int m_loadedMonth;
	bool m_militaryTime;
	char** m_timeArr;//18x3 2D array
	//see bottom of class for index mapping
	std::string m_eventId;

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
	void clearTimeArr();

	int EventsInMonth(int month);
	void PrintEventsInMonth();

/**	m_timeArr index mapping:
	hour:	index:
	5:00	[0][0]
	6:00	[1][0]
	7:00	[2][0]
	8:00	[3][0]
	9:00	[4][0]
	10:00	[5][0]
	11:00	[6][0]
	13:00	[7][0]	12 is skipped
	14:00	[8][0]
	15:00	[9][0]
	16:00	[10][0]
	17:00	[11][0]
	18:00	[12][0]
	19:00	[13][0]
	20:00	[14][0]
	21:00	[15][0]
	22:00	[16][0]
	23:00	[17][0]

	time slots example:
	5:00 => [0][0], 5:20 => [0][1], 5:40 => [0][2]
	*/
};

#endif
