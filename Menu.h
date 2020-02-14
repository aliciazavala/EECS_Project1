#ifndef MENU_H
#define MENU_H

#include "project1_lib.h"

#include <iostream>
#include <string>
#include <stdexcept>

class Menu
{
	public:
	virtual ~Menu() {}

	virtual void print() const = 0;
	

	private:
};

#endif
