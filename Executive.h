#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Calendar.h"
#include "Display.h"
#include "MainMenu.h"
#include "MonthMenu.h"


class Executive
{
	public:
	
	private:
	Calendar* eventList;
	Stack<Menu>* menuStack;
};

#endif
