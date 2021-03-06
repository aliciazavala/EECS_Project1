#include "TimeMenu.h"

TimeMenu::TimeMenu() //initializes members to null
{
	m_name = "TimeMenu";
	current_x = 0;
	current_y = 0;
	m_timeStr = " ";

}

TimeMenu::TimeMenu(const TimeMenu& original) //makes deep copy of TimeMenu
{
	m_name = original.m_name;
	current_x = original.current_x;
	current_y = original.current_y;
	m_timeStr = original.m_timeStr;
}

TimeMenu::~TimeMenu()
{
	//empty destructor
}

std::string TimeMenu::getName() const
{
	return m_name;
}

void TimeMenu::print() const
{
	//This print function is not used, but it is required for inheritance
}

bool TimeMenu::run(char** timeArr, bool militaryTime, bool attendMode)
{
	char choice;
	//create a set of chars to use in getCharFromSet function
	char choiceSet[8] = {'w','a','s','d','y','n','F','Q'};

	//this loop handles inputs from choicSet above and only exits with the inputs F or Q
	while(1)
	{
		//the current state of the menu is printed at the beginning of every loop
		print(timeArr, militaryTime, attendMode);
		choice = getCharFromSet(8,choiceSet);
		if(choice == 'w')
		{
			moveCursor("up");
		}
		else if(choice == 'a')
		{
			moveCursor("left");
		}
		else if(choice == 's')
		{
			moveCursor("down");
		}
		else if(choice == 'd')
		{
			moveCursor("right");
		}
		else if(choice == 'y')
		{
			setY(timeArr);
		}
		else if(choice == 'n')
		{
			setN(timeArr);
		}
		else if(choice == 'F')
		{
			fillBlank(timeArr);
			return true;
		}
		else if(choice == 'Q')
		{
			return false;
		}
	}

}

//This functions fills the empty ('_') spots in the array with 'n' as a result of input 'F'
void TimeMenu::fillBlank(char** timeArr)
{
	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(timeArr[i][j] == '_')
			{
				timeArr[i][j] = 'n';
			}
		}
	}
}

//This function converts the current_x index in the menu to a valid index in timeArr and marks it with 'y'
//This is needed because the menu displays an extra row, 12:00, which is not represented in timeArr
void TimeMenu::setY(char** timeArr)
{
	if(current_x == 7)//prevent the user from enterring a time in row 12:00
	{
		return;
	}
	if(current_x < 7 && timeArr[current_x][current_y] != 'X')
	{
		timeArr[current_x][current_y] = 'y';
	}
	else if(timeArr[current_x-1][current_y] != 'X')//account for the extra row
	{
		timeArr[current_x-1][current_y] = 'y';
	}
}

//This function converts the current_x index in the menu to a valid index in timeArr and marks it with 'n'
void TimeMenu::setN(char** timeArr)
{
	if(current_x == 7)//prevent the user from enterring a time in row 12:00
	{
		return;
	}
	if(current_x < 7 && timeArr[current_x][current_y] != 'X')
	{
		timeArr[current_x][current_y] = 'n';
	}
	else if(timeArr[current_x-1][current_y] != 'X')//account for the extra row
	{
		timeArr[current_x-1][current_y] = 'n';
	}
}

//This function handles the visuals for the menu and is printed every time it is updated.
//This menu can be usedto allow entry for time slots in an existing with the parameter attendMode set to true
void TimeMenu::print(char** timeArr, bool militaryTime,bool attendMode)
{
	int currentHour = 5;
	clearScreen();
	if(attendMode)//different title for attending an event
	{
		std::cout << "\t ===== Select Available Time Slots to Attend =====\n";
	}
	else
	{
		std::cout << "\t ===== Select Times for the Event =====\n";
	}
	//This nested for loop prints out every row in the menu
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == current_x && j == current_y)//Check to see if the current location is selected
			{
				std::cout << " >";
			}
			else
			{
				std::cout << "  ";
			}
			//the available times to attend are in this if condition
			if((currentHour >= 5 && currentHour < 12)||(currentHour >=13 && currentHour <24))
			{
				if(currentHour < 12)
				{
					std::cout << timeArr[i][j];
				}
				else//account for the unavailable time slots (12:00 - 13:00)
				{
					std::cout << timeArr[i-1][j];
				}
			}
			else//prints X in row 12:00
			{
				std::cout << "X";
			}
			printTime(formatTime(currentHour, getTimeSlot(j)), militaryTime);
			std::cout << '\t';
		}
		std::cout << std::endl;
		currentHour++;
	}
	//Available user actions
	std::cout << "        up\t\t[y] Available to attend\n";
	std::cout << "       [w]\t\t[n] Not Available\n";
	std::cout << "left[a][s][d]right\t[F] Finish (blanks will be set to not available)\n";
	std::cout << "       down\t\t[Q] Quit without saving\n";
	std::cout << "Action: ";
}

void TimeMenu::moveCursor(std::string direction) //updates the "coordinates" of the cursor on the time slot array
{
	if(direction == "up" && current_x > 0)
	{
		current_x = current_x-1;
	}
	else if(direction == "right" && current_y < 2)
	{
		current_y = current_y+1;
	}
	else if(direction =="down" && current_x < 18)
	{
		current_x = current_x+1;
	}
	else if(direction == "left" && current_y > 0)
	{
		current_y = current_y-1;
	}
}

int TimeMenu::getTimeSlot(int x) //maps time slot to corresponding 20 minute slot.
{
	switch(x)
	{
		case 0: return (0);
		case 1: return (20);
		case 2: return (40);
		default: throw(std::runtime_error("time slot error"));
	}
}
