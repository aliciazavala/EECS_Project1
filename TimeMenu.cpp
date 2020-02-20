#include "TimeMenu.h"

TimeMenu::TimeMenu()
{
	m_name = "TimeMenu";
	current_x = 0;
	current_y = 0;
	m_timeStr = " ";
	m_attendMode = 0;
}

TimeMenu::TimeMenu(const TimeMenu& original)
{
	m_name = original.m_name;
	current_x = original.current_x;
	current_y = original.current_y;
	m_timeStr = original.m_timeStr;
	m_attendMode = original.m_attendMode;
}

TimeMenu::~TimeMenu()
{

}

std::string TimeMenu::getName() const
{
	return m_name;
}

void TimeMenu::print() const
{

}

bool TimeMenu::run(char** timeArr, bool militaryTime)
{
	char choice;
	char choiceSet[8] = {'w','a','s','d','y','n','F','E'};
	if(timeArr[0][0] != '_')
	{
		m_attendMode = 1;
	}
	while(1)
	{
		print(timeArr, militaryTime);
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
		else if(choice == 'E')
		{
			return false;
		}
	}

}

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

void TimeMenu::setY(char** timeArr)
{
	if(current_x == 7)
	{
		return;
	}
	if(current_x < 7 && timeArr[current_x][current_y] != 'X')
	{
		timeArr[current_x][current_y] = 'y';
	}
	else if(timeArr[current_x-1][current_y] != 'X')
	{
		timeArr[current_x-1][current_y] = 'y';
	}
}

void TimeMenu::setN(char** timeArr)
{
	if(current_x == 7)
	{
		return;
	}
	if(current_x < 7 && timeArr[current_x][current_y] != 'X')
	{
		timeArr[current_x][current_y] = 'n';
	}
	else if(timeArr[current_x-1][current_y] != 'X')
	{
		timeArr[current_x-1][current_y] = 'n';
	}
}

void TimeMenu::print(char** timeArr, bool militaryTime)
{
	int currentHour = 5;
	clearScreen();
	if(m_attendMode)
	{
		std::cout << "\t ===== Select Available Time Slots to Attend =====\n";
	}
	else
	{
		std::cout << "\t ===== Select Times for the Event =====\n";
	}

	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == current_x && j == current_y)
			{
				std::cout << " >";
			}
			else
			{
				std::cout << "  ";
			}
			if((currentHour >= 5 && currentHour < 12)||(currentHour >=13 && currentHour <24))
			{
				if(currentHour < 12)
				{
					std::cout << timeArr[i][j];
				}
				else
				{
					std::cout << timeArr[i-1][j];
				}
			}
			else
			{
				std::cout << "X";
			}
			printTime(formatTime(currentHour, getTimeSlot(j)), militaryTime);
			std::cout << '\t';
		}
		std::cout << std::endl;
		currentHour++;
	}
	std::cout << "        up\t\t[y] Available to attend\n";
	std::cout << "       [w]\t\t[n] Not Available\n";
	std::cout << "left[a][s][d]right\t[F] Finish (blanks will be set to not available)\n";
	std::cout << "       down\t\t[Q] Quit without saving\n";
	std::cout << "Action: ";
}

void TimeMenu::moveCursor(std::string direction)
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

int TimeMenu::getTimeSlot(int x)
{
	switch(x)
	{
		case 0: return (0);
		case 1: return (20);
		case 2: return (40);
		default: throw(std::runtime_error("time slot error"));
	}
}
