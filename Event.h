#ifndef EVENT_H
#define EVENT_H

#include<string>

class Event
{
	public:
		Event();

		void setMonth(std::string month);
		std::string getMonth() const;
	private:
		std::string mMonth;
};

#endif
