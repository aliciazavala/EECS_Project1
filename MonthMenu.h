#ifndef MONTHMENU_H
#define MONTHMENU_H

#include "Menu.h"
#include "project1_lib.h"

class MonthMenu : public Menu
{
	public:
	MonthMenu();
	~MonthMenu();

	void print() const;
	void print(int month, int year) const;
	std::string getName() const;

	private:
	std::string m_menuName;
	int totalEvents;
	//point to event list
};

#endif
