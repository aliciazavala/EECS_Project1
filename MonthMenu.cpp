#include "MonthMenu.h"

MonthMenu::MonthMenu() //constructor initializes members to null
{
	EventID = nullptr;
	m_menuName = "MonthMenu";
	totalEvents = 0;
	m_eventsInYear = 0;
	EventID = nullptr;
}

MonthMenu::~MonthMenu()	//destructor deletes EventID array
{
	delete[] EventID;
}

void MonthMenu::print() const
{

}
void MonthMenu::setTotalEvents(int numEvents) //creates an array big enough to store events.
{
	totalEvents = numEvents;
	EventID = new int[totalEvents];
	for(int i=0; i<totalEvents; i++)
	{
		EventID[i]=0; //initializes ID numbers for all events to be zero.
	}

}
//this menu prints the events scheduled for a specific month and year
void MonthMenu::print(int month, int year)
{
	//clears screens and initializes variables
	clearScreen();
	int eventid = 0;
	int day;
	int eventmonth;
	int eventyear;
	int eventsLeft = totalEvents;
	std::string eventTimes;
	std::ifstream fin;
	std::string eventname;
	//open month text file to read event information
	fin.open("./data/" + nameOfMonth(month)+".txt");
	std::cout << "\t ===== Events for " << nameOfMonth(month) << " " << year << " =====" << std::endl;
	//loop through the text file 
	for(int i = 1; i <= totalEvents; i++)
	{
		//find keyword "Event"
		do
		{
			fin>>eventname;
		}while(eventname != "Event:");
		//get info for found event
		fin >> eventid;
		fin.ignore(1,'\n');
		std::getline(fin,eventname);
		fin >> day >> eventmonth >> eventyear;
		fin.ignore(1,'\n');
		getline(fin, eventTimes);
		eventTimes = eventTimes.substr(1, eventTimes.length() - 1);
		//check for matching year
		//if year of event matches, pass event ID to the array
		if(eventyear == year)
		{
			EventID[totalEvents - eventsLeft]=eventid;
			eventsLeft--;
			m_eventsInYear++;
			std::cout << "\n[" << m_eventsInYear << "]" << eventname << ": " << eventid;
		}
		//printing the option to create a new event
		if(totalEvents > 0)
		{
			if (i == totalEvents)
			{
				std::cout << "\n\n["<< m_eventsInYear+1<< "] New Event" << std::endl<<std::endl;
			}
		}
	}
	//if there are no events in given month and year, give option to create one
	if(totalEvents == 0)
	{
		std::cout << "[1] New Event" << std::endl;
	}
	std::cout << "[0] Back" << std::endl;
	fin.close();
}

int MonthMenu::getEventsInYear() const //returns number of events in a given year.
{
	return m_eventsInYear;
}

int MonthMenu::returnID(int Eid) //returns ID for a given event
{
	return EventID[Eid];
}


std::string MonthMenu::getName() const //returns name of current menu (MonthMenu)
{
	return m_menuName;
}

//m_month + ".txt" for file name
