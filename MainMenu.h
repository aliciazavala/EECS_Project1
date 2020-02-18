#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>

#include "Menu.h"
#include "project1_lib.h"

class MainMenu : public Menu
{
	public:
	MainMenu();
	~MainMenu();

	std::string getName() const;

	void print() const;
	void print(int year) const;
	
	private:
	
	
};

#endif
