#include "project1_lib.h"

int daysInMonth(int m, int y)
{
	if(m == 2) //this checks for february, and the nested conditional statements check to see if it's a leap year.
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
	else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) //if the month is january, march, may, july, august, october, or december, retern 31 days.
	{
		return 31;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) //if month is april, june, september, or november, return 30 days.
	{
		return 30;
	}
	else
	{
		throw(std::runtime_error("invalid month")); //throws error if invalid month is given.
	}
}

std::string nameOfMonth(int m) //maps parameter to corresponding month and returns that month's name.
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
		case 10: return ("October");
			break;
		case 11: return ("November");
			break;
		case 12: return ("December");
			break;
		default: throw(std::runtime_error("Not a month"));
			break;
	}
}

std::string dayOfWeek(int m, int d, int y) //given a month, day, and year, the day of the week that date falls on is returned.
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
	if(m < 0 || m > 12) //checks to see if the month is one of the twelve existing months.
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
	if(d < 0 || d > daysInMonth(m,y)) //checks to see if the day exists for that month.
	{
		return false;
	}
	if(isHoliday(m, d)) //checks to see if the day is scheduleable, i.e. not a holiday.
	{
		return false;
	}
	return true;
}

bool isHoliday(int m, int d) //returns true if date is a holiday.
{
	if(m == 1 && d == 1) //checks to see if event is on new year's
	{
		return true;
	}
	else if(m == 7 && d == 4) //checks to see if event is on 4th of july
	{
		return true;
	}
	else if(m == 12 && d == 25) //checks to see if event is on Christmas
	{
		return true;
	}
	return false;
}

int getCurrentYear() //returns the current year
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return(1900 + ltm->tm_year);
}

void printTime(std::string time, bool militaryTime)
{
	if(militaryTime) //if militaryTime is true, then time will be printed as is.
	{
		std::cout << time;//HH:MM
				  //01234
	}
	else
	{
		std::string temp = time.substr(0,2); //the hour is extracted from the time string
		int hour = stoi(temp);
		if(hour > 12) //converts the hour from military time to standard time.
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

std::string stringToTime(std::string timeStr, bool military)
{
	timeStr = timeStr + "0";
	int i1 = -1;
	int i2 = 0;
	std::string finalString = "";
	bool first = true;
	for(int i = 0; i < 54; i++)
	{
		if(timeStr.at(i) == '1')
		{
			i1 = i;
			for(int j = i; j <= 54; j++)
			{
				if(timeStr[j] == '0')
				{
					i2 = j-1;
					if(military)
					{
						if(!first)
						{
							finalString = finalString + ", ";
						}
						finalString = finalString + indexToTime(i1) + " - " + indexToTime(i2+1);
					}
					else
					{
						if(!first)
						{
							finalString = finalString + ", ";
						}
						finalString = finalString + convertTo12Hr(indexToTime(i1)) + " - " + convertTo12Hr(indexToTime(i2+1));
					}
					first = false;
					i = j;
					break;
				}
			}
		}
	}
	return finalString;
}

std::string convertTo12Hr(std::string time)
{
	std::string temp = time.substr(0,2);
	int hour = stoi(temp);
	if(hour > 12)
	{
		if(hour - 12 < 10)
		{
			return( '0' + std::to_string(hour - 12) + time.substr(2,3) + " PM");
		}
		else
		{
			return(std::to_string(hour - 12) + time.substr(2,3) + " PM");
		}
	}
	else
	{
		return (time + " AM");
	}
}

std::string indexToTime(int index)
{

	switch (index)
	{
		case 0: return ("05:00");
		case 1: return ("05:20");
		case 2: return ("05:40");
		case 3: return ("06:00");
		case 4: return ("06:20");
		case 5: return ("06:40");
		case 6: return ("07:00");
		case 7: return ("07:20");
		case 8: return ("07:40");
		case 9: return ("08:00");
		case 10: return ("08:20");
		case 11: return ("08:40");
		case 12: return ("09:00");
		case 13: return ("09:20");
		case 14: return ("09:40");
		case 15: return ("10:00");
		case 16: return ("10:20");
		case 17: return ("10:40");
		case 18: return ("11:00");
		case 19: return ("11:20");
		case 21: return ("11:40");
		case 20: return ("13:00");
		case 22: return ("13:20");
		case 23: return ("13:40");
		case 24: return ("14:00");
		case 25: return ("14:20");
		case 26: return ("14:40");
		case 28: return ("15:00");
		case 27: return ("15:20");
		case 29: return ("15:40");
		case 30: return ("16:00");
		case 31: return ("16:20");
		case 32: return ("16:40");
		case 33: return ("17:00");
		case 34: return ("17:20");
		case 35: return ("17:40");
		case 36: return ("18:00");
		case 37: return ("18:20");
		case 38: return ("18:40");
		case 39: return ("19:00");
		case 40: return ("19:20");
		case 41: return ("19:40");
		case 42: return ("20:00");
		case 43: return ("20:20");
		case 44: return ("20:40");
		case 45: return ("21:00");
		case 46: return ("21:20");
		case 47: return ("21:40");
		case 48: return ("22:00");
		case 49: return ("22:20");
		case 50: return ("22:40");
		case 51: return ("23:00");
		case 52: return ("23:20");
		case 53: return ("23:40");
		case 54: return ("00:00");
		default: throw(std::runtime_error("invalid index"));
	}
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

int generateID()
{
	int ID;
	std::random_device device;
	int seed = device();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(100000000,999999999);
	ID =  distribution(generator);
	return (ID);
}

std::string getPassword()
{
	std::string password;
	std::string confirm;
	termios t_original, t_hideInput;

	//save original settings
	tcgetattr(STDIN_FILENO, &t_original);

	t_hideInput = t_original;
	t_hideInput.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &t_hideInput);

	while(1)
	{
		std::cout << "\nEnter a password (length 8-16): ";
		std::cin >> password;
		if(password.length() >= 8 || password.length() <= 16)
		{
			std::cout << "\nConfirm Password: ";
			std::cin >> confirm;
			if(password != confirm)
			{
				std::cout << "Passwords do not match!\n";
			}
			else
			{
				//enable ternimal echo
				tcsetattr(STDIN_FILENO, TCSANOW, &t_original);
				return password;
			}
		}
		else
		{
			std::cout << "Invalid length!\n";
		}
	}
}
