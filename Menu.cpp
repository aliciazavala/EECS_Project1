#include "Menu.h"


void Menu::clearScreen(int lines) const
{
	for(int i = 0; i < lines; i++)	//displays a large number of lines to create the illusion of a live updated screen.
	{
		std::cout << std::endl;
	}
}
