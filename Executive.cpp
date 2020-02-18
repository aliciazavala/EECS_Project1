#include "Executive.h"
Executive::Executive()
{
	//both should be empty at startup
	m_calendar = nullptr;
	m_menuStack = nullptr;

	m_fileName = "data.txt"; //file name should be constant
}

Executive::~Executive()
{
	if(m_calendar != nullptr)
	{
		delete m_calendar;
	}
	if(m_menuStack != nullptr)
	{
		delete m_menuStack;
	}
}

void Executive::run()
{
	if(load())//executes load
	{
		m_menuStack = new Stack<Menu*>;

		Menu* newMenu = new MainMenu;
		m_menuStack->push(newMenu);

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
		else if(currentMenu == "SettingsMenu")
		{
			handleSettingsMenu();
		}
	}
	save();
}

bool Executive::load()
{
	//read from file then return true or return false if file cannot be openned

	int eventsLoaded = 1;//should be read from file
	m_calendar = new Calendar(eventsLoaded);

	return true;//placeholder return
}

void Executive::save()
{
	//save to file
	//possible feature: encrypt the save file to prevent it from being read or altered
	//			ex: convert chars to bits (8 bits) and then use XOR encryption
	//				   x XOR key = y, where x, y, and key are 8bit strings
	//				=> y XOR key = x


	std::cout << "save complete\n";//placeholder return
}

void Executive::handleMainMenu()
{
	(m_menuStack->peek())->print();//print

	std::string validInputs[16] = {"q","1","2","3","4","5","6","7","8","9","10","11","12","b","n","s"};
	std::string monthArr[12] = {"1","2","3","4","5","6","7","8","9","10","11","12"};
	std::string input = getStrFromSet(16, validInputs);//ask user for input

	if(containsStr(input, 12, monthArr))
	{
		Menu* newMenu = new MonthMenu(stoi(input));
		LoadedMonth = input;
		m_menuStack->push(newMenu);

	}
	else if(input == "q")
	{
		handleBack();
	}
	else if(input == "b")
	{
		// move year bakc
	}
	else if(input == "n")
	{
		//move year forward
	}
	else if(input == "s")
	{
		//push settings menu
	}
	
}

void Executive::handleMonthMenu()
{
	(m_menuStack->peek())->print();
	//read number of events in a month from that file
	int input = getIntRangeFromUser(0,2);
	if(input == 0)
	{
		handleBack();
	}
	else if(input == 1)
	{
		Menu* temp = new NewEventMenu(1);
		m_menuStack->push(temp);
	}
	//ask user to chose event or make event
	//if make event, then create event menu and push
}

void Executive::handleNewEventMenu()
{
	(m_menuStack->peek())->print();
	std::string creatorName;
	std::string EventName;
	std::ofstream events;
		NewEventMenu temp = NewEventMenu(LoadedMonth);
		std::string FileName =	temp.getMonth();
		events.open(FileName + ".txt", std::fstream::app);
		std::cout<<"Enter name of event creator: ";
		std::cin>>creatorName;
		std::cout<<"Enter name of the event: ";
		std::cin.ignore(); // ignores \n that cin >> str has lefted (if user pressed enter key)
		std::getline (std::cin,EventName);
		events<<creatorName<<'\t'<<EventName<<std::endl;
	events.close();
	std::cout << "[0] Back" << std::endl;
	int input = getIntRangeFromUser(0,0);
	if(input == 0)
	{
		handleBack();
	}
	//ask user for each event parameter
	//output to file
}

void Executive::handleBack()
{
	m_menuStack->pop();
}

void Executive::handleSettingsMenu()
{

}
