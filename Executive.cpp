#include "Executive.h"
Executive::Executive()
{
	m_menuStack = nullptr;

	m_loadedYear = getCurrentYear();
	m_militaryTime = false;
	m_hideTimes = false;
	loggedin = false;

	m_timeArr = new char*[18];
	for(int i = 0; i < 18; i++)
	{
		m_timeArr[i] = new char[3];
	}
	clearTimeArr();
}

Executive::~Executive()
{
	if(m_menuStack != nullptr)
	{
		delete m_menuStack;
	}
	if(m_timeArr != nullptr)
	{
		for(int i = 0; i < 18; i++)
		{
			delete[] m_timeArr[i];
		}
		delete[] m_timeArr;
	}
}

void Executive::run(bool test)
{

	m_menuStack = new Stack<Menu*>;

	Menu* newMenu = new MainMenu;
	m_menuStack->push(newMenu);

	if(test)
	{
		loadTimeArr(std::string("000000000011111111110000000000111111111100000000000000"));
		handleAttendTimeMenu();
		//handleAttendTimeMenu();
		//Menu* testMenu = new TimeMenu;
		//m_menuStack->push(testMenu);
	}

	while(!m_menuStack->isEmpty())//loops as long as there are menus
	{
		std::string currentMenu = (m_menuStack->peek())->getName();

		if(currentMenu == "MainMenu")
		{
			handleMainMenu();
		}
		else if(currentMenu == "MonthMenu")
		{
			handleMonthMenu();
		}
		else if(currentMenu == "NewEventMenu")
		{
			handleNewEventMenu();
		}
		else if(currentMenu == "EventMenu")
		{
			handleEventMenu();
		}
		else if(currentMenu == "TimeMenu")
		{
			handleTimeMenu();
		}
		else if(currentMenu == "SettingsMenu")
		{
			handleSettingsMenu();
		}
		else if(currentMenu == "AttendMenu")
		{
			handleAttendMenu();
		}
		else if(currentMenu == "AdminMenu")
		{
			handleAdminMenu();
		}
	}
}
void Executive::handleMainMenu()
{
	MainMenu temp;
	temp.print(m_loadedYear);//print

	std::string validInputs[16] = {"q","1","2","3","4","5","6","7","8","9","10","11","12","b","n","s"};
	std::string monthArr[12] = {"1","2","3","4","5","6","7","8","9","10","11","12"};
	std::string input = getStrFromSet(16, validInputs);//ask user for input

	if(containsStr(input, 12, monthArr))
	{
		m_loadedMonth = stoi(input);
		Menu* newMenu = new MonthMenu();
		m_menuStack->push(newMenu);

	}
	else if(input == "q")
	{
		handleBack();
	}
	else if(input == "b")// move back 1 year
	{
		m_loadedYear = m_loadedYear - 1;
	}
	else if(input == "n")// move forward 1 year
	{
		m_loadedYear = m_loadedYear + 1;//currently no upper limit for year
	}
	else if(input == "s")
	{
		Menu* newMenu = new SettingsMenu();
		m_menuStack->push(newMenu);
	}

}

void Executive::handleMonthMenu()
{
	//create temp
	MonthMenu temp;
	//read number of events in a month from that file
	int range = 0;
	temp.setTotalEvents(EventsInMonth(m_loadedMonth));
	temp.print(m_loadedMonth, m_loadedYear);
	range = temp.getEventsInYear();
	int input = getIntRangeFromUser(0,range+1);
	if(input == 0)
	{
		handleBack();
	}
	else if(input == range+1)
	{
		Menu* temp = new NewEventMenu(m_loadedMonth);
		m_menuStack->push(temp);
	}
	else if(input>0 && input<range+1)
	{
		m_eventId = temp.returnID(input-1);
		Menu* temp = new EventMenu(m_eventId, m_militaryTime, false);
		m_menuStack->push(temp);
	}
	//ask user to chose event or make event
	//if make event, then create event menu and push
}
void Executive::handleEventMenu()
{
	EventMenu temp(m_eventId, m_militaryTime, false);
	temp.print(m_loadedMonth,m_loadedYear,loggedin);
	int input=getIntRangeFromUser(0,3);
	m_eventTime = temp.getTime();
	if(input==0)
	{
		handleBack();
	}
	else if(input == 1)
	{
		Menu* newMenu = new AttendMenu();
		m_menuStack->push(newMenu);
	}
	else if(input == 2)
	{
		loggedin = false;
		Menu* adminMenu = new EventMenu(m_eventId, m_militaryTime, true);
		m_menuStack->push(adminMenu);
	}
}
void Executive::handleAdminMenu()
{
	EventMenu temp(m_eventId,m_militaryTime,true);
	temp.print(m_loadedMonth,m_loadedYear,loggedin);
	int input = getIntRangeFromUser(0,2);
	if(input == 1)
	{
		temp.printAvailability();
		std::cout << "\n[0] Finish" << std::endl;
	 	input = getIntRangeFromUser(0,0);
	}
	else if(input == 2)
	{
		Menu* settings = new SettingsMenu();
		m_menuStack->push(settings);
		//input = getIntRangeFromUser(0,2);
	}
	else if(input == 0)
	{
		handleBack();
	}
}
void Executive::handleAttendMenu()
{
	std::string m_eventName;
	std::ofstream attendees;
	attendees.open("./data/Attendees.txt",std::fstream::app);
	AttendMenu temp(m_eventId);
	temp.print();
	//m_eventTime = temp.getTime();
	TimeMenu* object = new TimeMenu();
	m_menuStack->push(object);
	loadTimeArr(m_eventTime);
	handleAttendTimeMenu();
	std::string array = ConvertArray();
	attendees << " " << array << std::endl;
	attendees.close();
	handleBack();
}
void Executive::PrintEventsInMonth()
{

}

void Executive::handleNewEventMenu()
{
	NewEventMenu temp = NewEventMenu(m_loadedMonth);
	temp.print(m_loadedMonth,m_loadedYear);

	std::string creatorName;
	std::string EventName;
	int day;

	std::ofstream events;
	std::ofstream attendees;
	std::string FileName =	nameOfMonth(m_loadedMonth);
	events.open("./data/" + FileName + ".txt", std::fstream::app);
	attendees.open("./data/Attendees.txt",std::fstream::app);

	std::cout<<"Enter name of event creator: ";
	std::cin.ignore();
	std::getline(std::cin, creatorName);
	std::cout<<"Enter name of the event: ";
	//std::cin.ignore(); // ignores \n that cin >> str has lefted (if user pressed enter key)
	std::getline(std::cin, EventName);

	do{

		std::cout<<"Enter day of event (1 - " << daysInMonth(m_loadedMonth,m_loadedYear) <<"): ";
		std::cin>>day;
		if(!isValidDate(m_loadedMonth,day,m_loadedYear))
		{
			std::cout<<"Date not valid! "<<std::endl;
		}
	}while(!isValidDate(m_loadedMonth,day,m_loadedYear));

	std::cout<<"Enter time of your event: "<<std::endl;
	TimeMenu* object = new TimeMenu();
	m_menuStack->push(object);

	handleTimeMenu();
	if(m_timeArr[0][0] != '_')//check to see if user did not quit without saving
	{
		std::string array = ConvertArray();
		int id = generateID();

		std::cout << "\t ===== Admin Password =====\n\n\n";
		std::string password = getPassword();

		events << "Event: "<< id <<std::endl << " " << EventName << std::endl;
		events << " " << m_loadedMonth << '\t' << day << '\t' << m_loadedYear << std::endl;
		events << " " << creatorName << std::endl;
		events << " " << array << std::endl;
		events << " " << password << std::endl;

		attendees << id << " " <<creatorName << std::endl;
		attendees << " " << array << std::endl;
	}
	attendees.close();
	events.close();
	std::cout << "\n[0] Finish" << std::endl;
	int input = getIntRangeFromUser(0,0);
	if(input == 0)
	{
		handleBack();
	}
	//ask user for each event parameter
	//output to file
}

std::string Executive::ConvertArray()
{
	std::string time = "                                                      ";
	int x = 0;
	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(m_timeArr[i][j] == 'n' || m_timeArr[i][j]=='_' || m_timeArr[i][j] == 'X')
			{
				time[x] = '0';
			}
			else
			{
				time[x] = '1';
			}
			x++;
		}
	}
	return time;
}
int Executive::EventsInMonth(int month)
{
	std::ifstream fin;
	std::string line;
 	fin.open("./data/" + nameOfMonth(month)+".txt");
	int count = 0;
	while(!fin.eof())
	{
		std::getline(fin,line);
		if(line.substr(0,5)=="Event")
		{
			count++;
		}
	}
	fin.close();
	return count;

}
void Executive::handleSettingsMenu()
{
	int input;
	SettingsMenu temp = SettingsMenu();
	//allow the user to repeatedly change the time setting:
	do
	{
		temp.print(m_militaryTime,m_hideTimes);
		input  = getIntRangeFromUser(0,2);
		if(input == 1)
		{
			m_militaryTime = !m_militaryTime;
		}
		if(input == 2)
		{
			m_hideTimes = !m_hideTimes;
		}
	}while(input != 0);
	//go back one menu
	handleBack();
}
void Executive::handleTimeMenu()//change text for admin
{
	TimeMenu temp;

	clearTimeArr();
	if(!temp.run(m_timeArr, m_militaryTime))
	{
		clearTimeArr();
	}
	handleBack();
}

void Executive::handleAttendTimeMenu()
{
	TimeMenu temp;
	if(!temp.run(m_timeArr, m_militaryTime))
	{
		clearTimeArr();
	}
	handleBack();
}
void Executive::handleBack()
{
	m_menuStack->pop();
}
void Executive::clearTimeArr()
{
	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			m_timeArr[i][j] = '_';
		}
	}
}

void Executive::loadTimeArr(std::string timeString)
{
	int index = 0;
	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(timeString.at(index) == '0')
			{
				m_timeArr[i][j] = 'X';
			}
			else
			{
				m_timeArr[i][j] = '_';
			}
			index++;
		}
	}
}
