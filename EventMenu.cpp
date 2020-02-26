#include "EventMenu.h"

EventMenu::EventMenu()
{

}
//EventMenu constructor that takes an int for the Event id and two bools
EventMenu::EventMenu(int id, bool militaryTime, bool adminMode)
{
  m_menuName = "EventMenu";
  m_eventTime = " ";
  m_eventname = " ";
  m_ID = id;
  m_militaryTime = militaryTime;
  m_adminMode = adminMode;
  times = new std::vector<std::string>;
  //if adminMode = true, this EventMenu object uses added features for admin users
  if(adminMode == true)
  {
    m_menuName = "AdminMenu";
  }
}
EventMenu::~EventMenu()
{
  delete times;
}
//virtual print(does not get used)
void EventMenu::print()const
{

}
void EventMenu::print(int loadedmonth, int loadedyear, bool& pass, bool hideTimes)
{
  //declare variables to be used in this method call
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
    std::string user_password;

	fin.open("./data/" + nameOfMonth(loadedmonth)+".txt");//open file month read necessary information
    while(fin>>temp)
    {
		fin>>eventId;
		std::getline(fin,eventName);//whitespace
		std::getline(fin,eventName);//read event's name
		fin>>month;
		fin>>day;
		fin>>year;
		std::getline(fin,creatorName);//whitepsace
		std::getline(fin,creatorName);//read event's admin's name
		std::getline(fin,timeString);//read time string for the event
		std::getline(fin,password);//read admin's password
		if (eventId == m_ID)//when matching ID for event is found in file, read event time string and admin password
		{
      m_eventTime = timeString.substr(1,timeString.size() - 1);//remove space from front
			m_password = password.substr(1,password.size() - 1);//remove space from front
      if(m_adminMode == true && pass == false)//if EventMenu is on adminMode, prompt for saved password
      {
        termios t_original, t_hideInput;
        tcgetattr(STDIN_FILENO, &t_original);

      	t_hideInput = t_original;
      	t_hideInput.c_lflag &= ~ECHO;
      	tcsetattr(STDIN_FILENO, TCSANOW, &t_hideInput);
        do{
          std::cout<<"Enter your admin password: "<<std::endl;
          std::cin>>user_password;
        }while(user_password != m_password);
        pass = true;
        clearScreen();
        std::cout << "\t ===== Status for " << eventName << " =====" << std::endl;
        m_eventname = eventName;
        tcsetattr(STDIN_FILENO, TCSANOW, &t_original);
      }
      else//if EventMenu is not on adminMode, print event's information
      {
        std::cout << "\t ===== " << eventName << " =====" << std::endl;
      }
			std::cout<< "Date: " << nameOfMonth(loadedmonth) <<", "<< dayOfWeek(loadedmonth,day,loadedyear) << " " << day << " " << loadedyear << "\n" ;
			std::cout<< "Admin: " <<creatorName<<"\n";
      std::cout << "Event Time(s) : " << stringToTime(m_eventTime, m_militaryTime) << "\n";

			//READ ATTENDEES
			std::ifstream attendees;
			std::string attendeeName;
			int id;

      //if EventMenu is on adminMode, print attendees list and Availability information
      if(m_adminMode == true)
      {
        std::cout<< "Attendees: " <<"\n"<<"\n";
        //open attendees text file
  			attendees.open("./data/Attendees.txt");
  			while(attendees>>id)
  			{
    			if(id == m_ID)//if matching event ID, read attendee's name and time Availability string
      			{
      			std::getline(attendees,attendeeName);
      			std::getline(attendees,timeString);
            timeString = timeString.substr(1,timeString.size() - 1);//remove space from front
            times->push_back(timeString);
      			std::cout << attendeeName;
            if(hideTimes)//option to hide Availability of attendee and just print the name
            {
                std::cout << ": "<< stringToTime(timeString, m_militaryTime)<< std::endl<<std::endl;
            }
            else
            {
              std::cout << std::endl;
            }
      			//Line missing: print attending time
  			     }

    			//Gets attendee's name line and attendee's time line and skips them
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
	if(m_adminMode != true)//If not on adminMode, give the option to enter adminMode or to attend event
  {
    std::cout << "[1] Attend" << std::endl;
    std::cout << "[2] Admin Mode" << std::endl;
  }
  else//When in adminMode give options to print event Availability, go to setting menu and go to previous menu
  {
    std::cout << "[1] Print Availability" << std::endl;
    std::cout << "[2] Settings" <<std::endl;
  }
	std::cout << "[0] Back" << std::endl;
}
int EventMenu::getTimeSlot(int x)
{
	switch(x)
	{
		case 0: return (0);
		case 1: return (20);
		case 2: return (40);
		default: throw(std::runtime_error("time slot error"));
	}
}

int EventMenu::countAttendees(int index)
{
	int totalCount = 0;
	if(times->size() > 1)
	{
		for(unsigned int i = 0;i < times->size(); i++)
		{
			if((times->at(i)).at(index) == '1')
			{
				totalCount++;
			}
		}
	}
	else
	{
		if((times->at(0)).at(index) == '1')
		{
			totalCount++;
		}
	}
	return totalCount;
}

void EventMenu::printAvailability()
{
  clearScreen();
  std::cout << "  ===== Availability for " << m_eventname << " =====" << std::endl;
	int currentHour = 5;
	int currentSlot = 0;
	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << " ";
			printTime(formatTime(currentHour, getTimeSlot(j)), m_militaryTime);
			std::cout << " - " << countAttendees(currentSlot) << "\t";
      currentSlot++;
		}
    if(currentHour == 11)
    {
      std::cout << "\n ";
      printTime("12:00", m_militaryTime);
      std::cout << " - " << "X" << "\t";
      std::cout << " ";
      printTime("12:20", m_militaryTime);
      std::cout << " - " << "X" << "\t";
      std::cout << " ";
      printTime("12:40", m_militaryTime);
      std::cout << " - " << "X" << "\t";
      currentHour++;
    }
		std::cout << std::endl;
		currentHour++;
	}
}
//Getter for the menu's name
std::string EventMenu::getName() const
{
  return m_menuName;
}
//Getter for time of the event
std::string EventMenu::getTime() const
{
	return m_eventTime;
}
//Getter for password picked by admin user for the event
std::string EventMenu::getPassword() const
{
	return m_password;
}
