#include "EventMenu.h"

EventMenu::EventMenu()
{

}
EventMenu::EventMenu(int id, bool militaryTime, bool adminMode)
{
  m_menuName = "EventMenu";
  m_eventTime = " ";
  m_eventname = " ";
  m_ID = id;
  m_militaryTime = militaryTime;
  m_adminMode = adminMode;
  times = new std::vector<std::string>;
  if(adminMode == true)
  {
    m_menuName = "AdminMenu";
  }
}
EventMenu::~EventMenu()
{
  delete times;
}
void EventMenu::print()const
{

}
void EventMenu::print(int loadedmonth, int loadedyear, bool& pass, bool hideTimes)
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
    std::string user_password;

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
      if(m_adminMode == true && pass == false)
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
      if(m_adminMode == true)
      {
        std::cout<< "Attendees: " <<"\n"<<"\n";
  			attendees.open("./data/Attendees.txt");
  			while(attendees>>id)
  			{
    			if(id == m_ID)
      			{
      			std::getline(attendees,attendeeName);
      			std::getline(attendees,timeString);
            timeString = timeString.substr(1,timeString.size() - 1);//remove space from front
            times->push_back(timeString);
      			std::cout << attendeeName;
            if(hideTimes)
            {
                std::cout << ": "<< stringToTime(timeString, m_militaryTime)<< std::endl<<std::endl;
            }
            else
            {
              std::cout << std::endl;
            }
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
	if(m_adminMode != true)
  {
    std::cout << "[1] Attend" << std::endl;
    std::cout << "[2] Admin Mode" << std::endl;
  }
  else
  {
    std::cout << "[1] Print Availability" << std::endl;
    std::cout << "[2] Settings" <<std::endl;
  }
	std::cout << "[0] Back" << std::endl;
}

//This helper function makes the nested for loop in printAvailability readable.
//The loop's control variable iterates from 0 to 2, which gets transalted into
//one of the available time slots(XX:00, XX:20, XX:40)
int EventMenu::getTimeSlot(int x)
{
	switch(x)
	{
		case 0: return (0);
		case 1: return (20);
		case 2: return (40);
    //The way this function is called does not require a catch as this throw will not happen
		default: throw(std::runtime_error("time slot error"));
	}
}

//This function accesses the time vector to count how many attendees are
//available at a time slot, represented by index, for each time string
int EventMenu::countAttendees(int index)
{
  //Initialize the counting varibable that will be returned
	int totalCount = 0;
  //The case for when the times vector has multiple time strings
	if(times->size() > 1)
	{
    //i represents the vector's index
		for(unsigned int i = 0;i < times->size(); i++)
		{
      //any 1s in the time strings will increment the totalCount by 1
			if((times->at(i)).at(index) == '1')
			{
				totalCount++;
			}
		}
	}
  //the case for when the only attendee is the admin
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
