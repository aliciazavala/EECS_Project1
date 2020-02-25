#include "EventMenu.h"

EventMenu::EventMenu()
{

}
EventMenu::EventMenu(int id, bool militaryTime, bool adminMode)
{
  m_menuName = "EventMenu";
  m_eventTime = " ";
  m_ID = id;
  m_militaryTime = militaryTime;
  m_adminMode = false;
}
EventMenu::~EventMenu()
{

}
void EventMenu::print()const
{

}
void EventMenu::print(int loadedmonth, int loadedyear)
{
    clearScreen();
    std::ifstream fin;
    std::string temp;
    std::string creatorName;
    std::string eventName;
	std::string timeString;
    int eventId;
    int month;
    int day;
    int year;
    std::string password;

	fin.open("./data/" + nameOfMonth(loadedmonth)+".txt");//open file month
    while(fin>>temp)
    {
		fin>>eventId;
		std::getline(fin,eventName);//whitespace
		std::getline(fin,eventName);
		fin>>month;
		fin>>day;
		fin>>year;
		std::getline(fin,creatorName);//whitepsace
		std::getline(fin,creatorName);
		std::getline(fin,timeString);
		std::getline(fin,password);
		if (eventId == m_ID)
		{
      m_eventTime = timeString.substr(1,timeString.size() - 1);//remove space from front
			m_password = password.substr(1,password.size() - 1);//remove space from front

      if(m_adminMode)
      {
        std::cout << "\t ===== Status for " << eventName << " =====" << std::endl;
      }
      else
      {
        std::cout << "\t ===== " << eventName << " =====" << std::endl;

      }
			//USE LIBRARY TO ALSO GET DAY OF THE WEEK??
			std::cout<< "Date: " << nameOfMonth(loadedmonth) <<", "<< dayOfWeek(loadedmonth,day,loadedyear) << " " << day << " " << loadedyear << "\n" ;
			std::cout<< "Admin: " <<creatorName<<"\n";
      std::cout << "Event Time(s) : " << stringToTime(m_eventTime, m_militaryTime) << "\n";

			//READ ATTENDEES
			std::ifstream attendees;
			std::string attendeeName;
			int id;
      
      //admin mode output
      if(m_adminMode)
      {
        std::cout<< "Attendees: " <<"\n";
  			attendees.open("./data/Attendees.txt");
  			while(attendees>>id)
  			{
    			if(id == m_ID)
      			{
      			std::getline(attendees,attendeeName);
      			std::getline(attendees,timeString);
            timeString = timeString.substr(1,timeString.size() - 1);//remove space from front
      			std::cout << attendeeName << stringToTime(timeString, m_militaryTime)<< std::endl;
      			//Line missing: print attending time
  			     }

    			//gets attendee's name line and attendee's time line and skips them
    			else
    			{
      			std::getline(attendees,attendeeName);
      			std::getline(attendees,timeString);
    			}
  			}
      }

			std::cout<<"\n";
			attendees.close();
		}

	}

	std::cout << "[1] Attend" << std::endl;
	std::cout << "[2] Admin Mode" << std::endl;
	std::cout << "[0] Back" << std::endl;
}
std::string EventMenu::getName() const
{
  return m_menuName;
}

std::string EventMenu::getTime() const
{
	return m_eventTime;
}

std::string EventMenu::getPassword() const
{
	return m_password;
}
