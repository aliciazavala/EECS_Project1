#include "ViewEventMenu.h"

ViewEventMenu::ViewEventMenu(int eventId)
{
  m_menuName= "ViewEventMenu";
  m_eventId = eventId;
}

ViewEventMenu::ViewEventMenu()
{
	
}

ViewEventMenu::~ViewEventMenu()
{
  
}

void ViewEventMenu::print() const
{
	clearScreen();
	std::ifstream fin;
    std::string temp;
    std::string creatorName;
    std::string eventName;
	std::string timeArray;
    int eventId;
    int month;
    int day;
    int year;
    int userChoice;

	fin.open("./data/" + nameOfMonth(m_loadedMonth)+".txt");//open file month
    while(fin>>temp)
    {
		fin>>eventId;
		std::getline(fin,eventName);
		std::getline(fin,eventName);
		fin>>month;
		fin>>day;
		fin>>year;
		std::getline(fin,creatorName);
		std::getline(fin,creatorName);
		std::getline(fin,timeArray);

		if (eventId == m_eventId)
		{
			std::cout << "\t ===== " << eventName << " =====" << std::endl;
			//USE LIBRARY TO ALSO GET DAY OF THE WEEK??
			std::cout<<"Date: "<< nameOfMonth(m_loadedMonth) <<", "<< dayOfWeek(m_loadedMonth,day,m_loadedYear) << " "<<day<<" "<< m_loadedYear << "\n" ;
			std::cout<<"Event Creator: "<<creatorName<<"\n";
			std::cout<<"Attendees: "<<"\n";
			//READ ATTENDEES
			std::ifstream attendees;
			std::string attendeeName;
			int id;

			attendees.open("./data/Attendees.txt");
			while(attendees>>id)
			{
			if(id == m_eventId)
			{
			std::getline(attendees,attendeeName);
			std::getline(attendees,timeArray);

			std::cout<<attendeeName<<std::endl;
			//Line missing: print attending time
			}


			//gets attendee's name line and attendee's time line and skips them
			else
			{
			std::getline(attendees,attendeeName);
			std::getline(attendees,timeArray);
			}

			}

			std::cout<<"\n";
			attendees.close();
			
		}
				
	}
	
	std::cout << "[1] Attend" << std::endl;
	std::cout << "[0] Back" << std::endl;

}	

std::string ViewEventMenu::getName() const
{
	return m_menuName;
}
