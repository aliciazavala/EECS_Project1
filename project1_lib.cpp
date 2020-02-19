#include "project1_lib.h"

int daysInMonth(int m, int y)
{
	if(m == 2)
	{
		if(y % 4 != 0)
		{
			return 28;
		}
		else if(y % 100 != 0)
		{
			return 29;
		}
		else if(y % 400 != 0)
		{
			return 28;
		}
		else
		{
			return 29;
		}
	}
	else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		return 31;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		return 30;
	}
	else
	{
		throw(std::runtime_error("invalid month"));
	}
}

std::string nameOfMonth(int m)
{
	switch(m)
	{
		case 1: return ("January");
			break;
		case 2: return ("February");
			break;
		case 3: return ("March");
			break;
		case 4: return ("April");
			break;
		case 5: return ("May");
			break;
		case 6: return ("June");
			break;
		case 7: return ("July");
			break;
		case 8: return ("August");
			break;
		case 9: return ("September");
			break;
		case 10: return ("Octcober");
			break;
		case 11: return ("November");
			break;
		case 12: return ("December");
			break;
		default: throw(std::runtime_error("Not a month"));
			break;
	}
}

std::string dayOfWeek(int m, int d, int y)
{
	if(m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}
	int N = d + 2*m + floor((3*(m+1))/5) + y + floor(y/4) - floor(y/100) + floor(y/400) + 2;
	switch(N%7)	
	{
		case 1: return ("Sunday");
			break;
		case 2: return ("Monday");
			break;
		case 3: return ("Tuesday");
			break;
		case 4: return ("Wednesday");
			break;
		case 5: return ("Thursday");
			break;
		case 6: return ("Friday");
			break;
		case 0: return ("Saturday");
			break;
		default: return ("undefined");
			break;
	}
}

bool isValidDate(int m, int d, int y)
{
	if(m < 0 || m > 12)
	{
		return false;
	}
	if(y < 1582)//first gregorian calendar year
	{
		return false;
	}
	if(y == 1582)//first gregorian calendar date
	{
		if(m < 10 && d < 15)
		{
			return false;
		}
	}
	if(d < 0 || d > daysInMonth(m,y))
	{
		return false;
	}
	if(isHoliday(m, d))
	{
		return false;
	}
	return true;
}

bool isHoliday(int m, int d)
{
	if(m == 1 && d == 1)
	{
		return true;
	}
	else if(m == 7 && d == 4)
	{
		return true;
	}
	else if(m == 12 && d == 25)
	{
		return true;
	}
	return false;
}

int getCurrentYear()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return(1900 + ltm->tm_year);
}

void printTime(std::string time, bool militaryTime)
{
	if(militaryTime)
	{
		std::cout << time;//HH:MM
				  //01234
	}
	else
	{
		std::string temp = time.substr(0,2);
		int hour = stoi(temp);
		if(hour > 12)
		{
			if(hour - 12 < 10)
			{
				std::cout << "0" + std::to_string(hour - 12) << time.substr(2,3) << " PM";
			}
			else
			{
				std::cout << hour - 12 << time.substr(2,3) << " PM";
			}
		}
		else
		{
			std::cout << time << " AM";
		}
	}
}

std::string formatTime(int hour, int minute)
{
	std::string formattedHour;
	std::string formattedMin;
	if(hour < 0 || hour > 24 || minute < 0 || minute > 60)
	{
		throw(std::runtime_error("invalid time to format"));
	}
	
	if(hour < 10)
	{
		formattedHour = "0" + std::to_string(hour);
	}
	else
	{
		formattedHour = std::to_string(hour);
	}

	if(minute < 10)
	{
		formattedMin = "0" + std::to_string(minute);
	}
	else
	{
		formattedMin = std::to_string(minute);
	}

	return (formattedHour + ":" +formattedMin);
}

int getValidIntFromUser(std::string errorMessage)
{
	int input;
	while(1)
	{
		std::cin >> input;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << errorMessage << std::endl;
		}
		else
		{
			return input;
		}
	}
}

int getIntRangeFromUser(int lowerBound, int upperBound, std::string errorMessage)
{
	int input;
	if(lowerBound > upperBound)
	{
		throw(std::runtime_error("Invalid bounds!"));
	}
	while(1)
	{
		std::cin >> input;
		if(std::cin.fail() || input < lowerBound || input > upperBound)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << errorMessage;
		}
		else
		{
			return input;
		}
	}
}

std::string getStrFromSet(int size, std::string arr[], std::string errorMessage)
{
	std::string input;
	while(1)
	{
		std::cin >> input;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else if(containsStr(input, size, arr))
		{
			return input;
		}
		std::cout << errorMessage << std::endl;
	}
}

bool containsStr(std::string str, int size, std::string arr[])
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == str)
		{
			return true;
		}
	}
	return false;
}


int getCharFromSet(int size, char arr[], std::string errorMessage)
{
	char input;
	while(1)
	{
		std::cin >> input;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else
		{
			for(int i = 0; i < size; i++)
			{

				if(arr[i] == input)
				{
					return input;
				}
			}
		}
		std::cout << errorMessage << std::endl;
	}
}

std::string generateID()
{
	std::string ID = "123456";
	std::random_device device;
	int seed = device();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(0,9);
	for(int i = 0; i < 6; i++)
	{
		ID[i] = '0' + distribution(generator);
	}
	return (ID);
}
