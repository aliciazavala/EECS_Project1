#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Event.h"
#include "Calendar.h"
#include "Display.h"
#include "Menu.h"
#include "MainMenu.h"
#include "MonthMenu.h"
#include "StackInterface.h"


class Executive
{
	public:
	Executive();
	~Executive();

	void run();

	private:
	bool load();
	void save();
	void pushMenu(std::string menuName);

	std::string m_fileName;
	Calendar* m_calendar;
	Stack<Menu*>* m_menuStack;

};

#endif
