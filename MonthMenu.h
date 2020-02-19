#ifndef MONTHMENU_H
#define MONTHMENU_H

#include "Menu.h"
#include "project1_lib.h"
#include <fstream>
#include <string.h>

class MonthMenu : public Menu
{
	public:
	MonthMenu();
	~MonthMenu();

	void print() const;
	void print(int month, int year) const;
	std::string getName() const;
	void setTotalEvents(int numEvents);

	private:
	std::string m_menuName;
	int totalEvents;
	int* EventId;
	//point to event list
};

#endif
