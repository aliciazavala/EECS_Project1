#ifndef TIMEMENU_H
#define TIMEMENU_H

#include <string>

#include "Menu.h"
#include "project1_lib.h"

class TimeMenu : public Menu
{
	public:
	TimeMenu();
	~TimeMenu();

	std::string getName() const;

	void print() const;
	bool run(char** timeArr,bool militaryTime);


	private:
	std::string m_name;
	int current_x;
	int current_y;
	
	void print(char** timeArr, bool militaryTime);
	
	void fillBlank(char** timeArr);
	void setY(char** timeArr);
	void setN(char** timeArr);
	void moveCursor(std::string direction);
	int getTimeSlot(int x);	
};

#endif
