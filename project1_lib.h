#ifndef PROJECT1_LIB
#define PROJECT1_LIB

#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

/******************************************************************************
 *   CALENDAR FUNCTIONS
 *******************************************************************************/


	//@pre none
	//@post returns the days in the given month as an integer
	//@param m=month, y=year
	//@throw throw if month entered is not valid
int daysInMonth(int m, int y);


	//@pre none
	//@post returns the month number m as a string
	//@throw throw if m is not a valid month number
std::string nameOfMonth(int m);


	//pre none
	//post returns the day which the date falls on as a string
	//param d=day, m=month, y=year
	//return a string which the first character capitalized and no whitespace
std::string dayOfWeek(int m, int d, int y);


	//pre none
	//post returns either true or false given a date
	//param d=day, m=month, y=year
bool isValidDate(int m, int d, int y);


	//pre none
	//post returns true if it's not New Years, 4th of July, or Christmas, false otherwise
	//param m = month, d = day
bool isHoliday(int m, int d);


	//@pre none
	//@post returns the current year as an integer*/
int getCurrentYear();

	//@pre none
	//@post returns a string with the format "HH:MM" representing 24 hour time
	//@throw throws a runtime_error if hour and minute do not represent a valid time in 24-hour format
std::string formatTime(int hour, int min);

	//@pre formattedTime must be a string representing a time in 24 hour format with structure "HH:MM"
	//@post prints the time to the terminal, converting to 12-hour format if mimiltaryTime == false
void printTime(std::string formattedTime, bool militaryTime);

	//@pre timeStr must be a string of lenth 54 containing only '1' and '0' getCharFromSet
	//@post returns a string with representing a list of condensed contiguous time slots separated by commas
std::string stringToTime(std::string timeStr, bool military);

	//@pre formattedTime must be a string representing a time in 24 hour format with structure "HH:MM"
	//@post returns a string representing a time "HH:MM" in 12-hour format
std::string convertTo12Hr(std::string time);

	//@pre none
	//@post returns a string representing a time "HH:MM" in 24-hour format
	//@throw throws a runtime_error if index < 0 or index > 54
std::string indexToTime(int index);

/******************************************************************************
 *   OTHER FUNCTIONS
 *******************************************************************************/


	//@pre none
	//@post returns an integer only after the user enters a valid integer
	//@param optional parameter for an error message displayed for non-integer inputs
int getValidIntFromUser(std::string errorMessage = "Invalid input!");


	//@pre none
	//@post returns a valid int from the user within the range [lowerbound, upperBound]
	//@param lowerbound and upperBound are inclusive and errorMessage is an optional parameter
	//@throw throws a runtime_error if lowerBound > upperBound
int getIntRangeFromUser(int lowerBound, int upperBound, std::string errorMessage = "Invalid input!");


	//@pre size must equal the total number of elements in arr and it cannot be 0
	//@post returns a valid string that belongs to the set arr
	//@param arr is a string array of size 'size' and errorMessage is an optional paramter
std::string getStrFromSet(int size, std::string arr[], std::string errorMessage = "Invalid input!");


	//@pre size must equal the total number of elements in arr and it cannot be 0
	//@post returns true if str is in the string array arr
	//@param arr is a string array of size 'size' and str is the string to search
bool containsStr(std::string str, int size, std::string arr[]);


	//@pre size must equal the total number of elements in arr and it cannot be 0
	//@post returns a char that is in the set arr
	//@param arr is a char array of size 'size' and errorMessage is an optional parameter*/
int getCharFromSet(int size, char arr[], std::string errorMessage = "Invalid input!");


	//@pre none
	//@post returns a string representing an ID of 6 digits
int generateID();

	//@pre none
	//@post returns a password of length 8-16 chars after prompting the user at terminal
std::string getPassword();

#endif
