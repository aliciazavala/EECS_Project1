#ifndef MENU_H
#define MENU_H

#include "project1_lib.h"
#include "Event.h"

#include <iostream>
#include <string>
#include <stdexcept>

class Menu
{
	public:
	virtual ~Menu() {}
	
	virtual void print() const = 0;
	virtual std::string getName() const = 0;
	void clearScreen(int lines = 100) const;

	private:
};

#endif
