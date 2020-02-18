#ifndef PROJECT1_LIB
#define PROJECT1_LIB

#include <math.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime>


/******************************************************************************
 *   CONSTANT DEFINITIONS
 *******************************************************************************/


/******************************************************************************
 *   CALENDAR FUNCTIONS
 *******************************************************************************/

/**
	@pre none
	@post returns the days in the given month as an integer
	@param m=month, y=year
	@throw throw if month entered is not valid*/
int daysInMonth(int m, int y);

/**
	@pre none
	@post returns the month number m as a string
	@throw throw if m is not a valid month number*/
std::string nameOfMonth(int m);

/**
	@pre none
	@post returns the day which the date falls on as a string
	@param d=day, m=month, y=year
	@return a string which the first character capitalized and no whitespace*/
std::string dayOfWeek(int m, int d, int y);

/**
	@pre none
	@post returns either true or false given a date
	@param d=day, m=month, y=year*/
bool isValidDate(int m, int d, int y);

/**
	@pre none
	@post returns true if it's not New Years, 4th of July, or Christmas, false otherwise
	@param m = month, d = day*/
bool isHoliday(int m, int d)

/**
	@pre none
	@post returns the current year as an integer*/
int getCurrentYear();

/******************************************************************************
 *   OTHER FUNCTIONS
 *******************************************************************************/

	/**
	@pre none
	@post returns an integer only after the user enters a valid integer
	@param optional parameter for an error message displayed for non-integer inputs*/
int getValidIntFromUser(std::string errorMessage = "Invalid input!"); 

	/**
	@pre none
	@post returns a valid int from the user within the range [lowerbound, upperBound]
	@param lowerbound and upperBound are inclusive and errorMessage is an optional parameter*/
int getIntRangeFromUser(int lowerBound, int upperBound, std::string errorMessage = "Invalid input!");

	/**
	@pre none
	@post returns a valid string that belongs to the set arr
	@param arr is a string array of size 'size' and errorMessage is an optional paramter
	*/
std::string getStrFromSet(int size, std::string arr[], std::string errorMessage = "Invalid input!");
	
	/**
	@pre none
	@post returns true if str is in the string array arr
	@param */
bool containsStr(std::string str, int size, std::string arr[]);

	/**
	@pre none
	@post returns a char that is in the set arr
	@param arr is a char array of size 'size' and errorMessage is an optional parameter*/
int getCharFromSet(int size, char arr[], std::string errorMessage = "Invalid input!");

	/**
	@pre none
	@post returns a string representing an ID of 6 digits
	*/
std::string generateID();

#endif
