#ifndef TIMEMENU_H
#define TIMEMENU_H

#include <string>

#include "Menu.h"
#include "project1_lib.h"

class TimeMenu : public Menu
{
	public:
	TimeMenu();
	TimeMenu(std::string timeStr);
	TimeMenu(const TimeMenu& original);
	~TimeMenu();

	std::string getName() const;

	void print() const;
	bool run(char** timeArr,bool militaryTime, bool attendMode = 0);


	private:
	std::string m_name;
	std::string m_timeStr;
	int current_x;
	int current_y;
	bool m_attendMode;

	void print(char** timeArr, bool militaryTime, bool attendMode);

	void fillBlank(char** timeArr);
	void setY(char** timeArr);
	void setN(char** timeArr);
	void moveCursor(std::string direction);
	int getTimeSlot(int x);
};

#endif
