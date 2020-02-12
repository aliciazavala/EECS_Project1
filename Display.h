#ifndef DISPLAY_H
#define DISPLAY_H

#include "project1_lib.h"
#include "Calendar.h"
#include "Stack.h"

#include <cstdlib>

class Display
{
	public:
	Display();
	~Display();
	void drawMenu(int menuID);
	int getCurrent() const;
	int back() const;
	void clear();

	private:
	int m_xPos;
	int m_yPos;
	Stack<int>* m_history;
	
	void handleMainMenu();
};

#endif
