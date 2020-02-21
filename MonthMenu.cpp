#include "MonthMenu.h"

MonthMenu::MonthMenu()
{
	m_menuName = "MonthMenu";
	totalEvents = 0; //placeholder
	EventID = nullptr;
}

MonthMenu::~MonthMenu()
{
	delete [] EventID;
	EventID = nullptr;
}

void MonthMenu::print() const
{

}
void MonthMenu::setTotalEvents(int numEvents)
{
	totalEvents = numEvents;
	EventID = new int[totalEvents];
	for(int i=0; i<totalEvents; i++)
	{
		EventID[i]=0;
	}
}
void MonthMenu::print(int month, int year) const
{
	clearScreen();
	int eventid = 0;
	int day;
	int eventmonth;
	int eventsINyear=0;
	int eventyear;
	int y = totalEvents;
	std::ifstream fin;
	std::string eventname;
	fin.open("./data/" + nameOfMonth(month)+".txt");
	std::cout << "\t ===== Events for " << nameOfMonth(month) << " " << year << " =====" << std::endl;
	for(int i = 1; i <= totalEvents; i++)
	{
		//print every event name
		do
		{
			fin>>eventname;
		}while(eventname != "Event:");
		fin>>eventid;
		fin.ignore(1,'\n');
		std::getline(fin,eventname);
		fin>>day>>eventmonth>>eventyear;
		if(eventyear == year)
		{
			EventID[totalEvents-y]=eventid;
			y--;
		}
		if(eventyear == year)
		{
			eventsINyear++;
			std::cout << "\n[" << eventsINyear << "]";
			std::cout<<eventname<<": "<<eventid;
		}
		if(totalEvents > 0)
		{
			if (i == totalEvents)
			{
				std::cout << "\n\n["<< i+1<< "] New Event" << std::endl<<std::endl;
			}
		}
	}
	if(totalEvents == 0)
	{
		std::cout << "[1] New Event" << std::endl;
	}
	/*for(int i = 0; i<totalEvents; i++)
	{
		std::cout<<EventID[i]<<std::endl;
	}
	*/
	std::cout << "[0] Back" << std::endl;
	fin.close();
}
int MonthMenu::returnID(int Eid)
{
	return EventID[Eid];
}
std::string MonthMenu::getName() const
{
	return m_menuName;
}

//m_month + ".txt" for file name
