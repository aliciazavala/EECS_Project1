#include "Menu.h"


void Menu::clearScreen(int lines) const
{
	for(int i = 0; i < lines; i++)
	{
		std::cout << std::endl;
	}
}
