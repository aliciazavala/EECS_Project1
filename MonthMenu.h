#ifndef MONTHMENU_H
#define MONTHMENU_H

#include "Menu.h"
#include "project1_lib.h"

class MonthMenu : public Menu
{
	public:
	MonthMenu(int month);
	~MonthMenu();

	void print() const;
	std::string getName() const;
	std::string getMonth() const;

	private:
	std::string m_menuName;
	std::string m_month;
	int totalEvents;
	//point to event list
};

#endif
