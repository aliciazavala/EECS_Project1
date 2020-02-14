#ifndef EVENT_H
#define EVENT_H

#include "project1_lib.h"

#include <string>

class Event
{
	public:
	Event();//this constructor should not be used
	
	std::string getMonth();
	private:
	std::string m_month;
};

#endif
