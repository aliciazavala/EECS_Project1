#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <string>

#include "Menu.h"
#include "project1_lib.h"

class SettingsMenu : public Menu
{
	public:
	SettingsMenu();
	~SettingsMenu();

	std::string getName() const;

	void print() const;
	void print(bool militaryTime, bool hideTimes) const;
	
	private:
	std::string menuName;
};

#endif
