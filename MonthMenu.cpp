#include "MonthMenu.h"

MonthMenu::MonthMenu()
{
	EventID = nullptr;
	m_menuName = "MonthMenu";
	totalEvents = 0; //placeholder
}

MonthMenu::~MonthMenu()
{
	delete[] EventID;
}

void MonthMenu::print() const
{

}
void MonthMenu::setTotalEvents(int numEvents)
{
	totalEvents = numEvents;
	EventID = new int[totalEvents];
}
void MonthMenu::print(int month, int year) const
{
	clearScreen();
	int eventid = 0;
	int x = totalEvents;
	std::ifstream fin;
	std::string eventname;
	fin.open("./data/" + nameOfMonth(month)+".txt");
	std::cout << "\t ===== Events for " << nameOfMonth(month) << " " << year << " =====" << std::endl;
	for(int i = 1; i <= totalEvents; i++)
	{
		//print every event name
		std::cout << "\n[" << i << "]";
		do
		{
			fin>>eventname;
		}while(eventname != "Event:");
		fin>>eventid;
		EventID[totalEvents-x]=eventid;
		fin.ignore(1,'\n');
		std::getline(fin,eventname);
		std::cout<<eventname<<": "<<EventID[totalEvents-x];
		x--;
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
