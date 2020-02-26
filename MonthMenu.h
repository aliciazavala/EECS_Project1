#ifndef MONTHMENU_H
#define MONTHMENU_H

#include "Menu.h"
#include "project1_lib.h"
#include <fstream>
#include <string.h>
#include "Executive.h"

class MonthMenu : public Menu
{
	public:
	MonthMenu();
	~MonthMenu();

	void print() const;
	void print(int month, int year);
	std::string getName() const;
	void setTotalEvents(int numEvents);
	int getEventsInYear() const;
	int returnID(int Eid);

	private:
	std::string m_menuName;
	int totalEvents;
	int* EventID;
	int m_eventsInYear;
	//point to event list
};

#endif
