#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Event.h"
#include "Calendar.h"
#include "Menu.h"
#include "MainMenu.h"
#include "MonthMenu.h"
#include "StackInterface.h"
#include "Stack.h"


class Executive
{
	public:
	Executive();
	~Executive();

	void run();

	private:
	bool load();
	void save();

	void handleMainMenu();
	void handleMonthMenu();
	void handleNewEventMenu();
	void handleBack();
	void handleSettingsMenu();

	int loadedYear;
	std::string m_fileName;
	Calendar* m_calendar;
	Stack<Menu*>* m_menuStack;

};

#endif
