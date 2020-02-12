#ifndef PROJECT1_LIB
#define PROJECT1_LIB

#include <math.h>
#include <string>
#include <stdexcept>
#include <random>

/******************************************************************************
 *   DEFINITIONS
 *******************************************************************************/
//constant 

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
	@post returns the day which the date falls on as a string
	@param d=day, m=month, y=year
	@return a string which the first character capitalized and no whitespace*/
std::string dayOfWeek(int m, int d, int y);

/**
	@pre none
	@post returns either true or false given a date
	@param d=day, m=month, y=year*/
bool isValidDate(int m, int d, int y);

/******************************************************************************
 *   OTHER FUNCTIONS
 *******************************************************************************/
	/**
	@pre none
	@post returns an integer only after the user enters a valid integer
	@param optional parameter for an error message displayed for non-integer inputs*/
int getValidIntFromUser(std::string errorMessage = "Invalid input!"); 

std::string generateID();

#endif
