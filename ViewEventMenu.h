#ifndef VIEWEVENTMENU_H
#define VIEWEVENTMENU_H
#include <string>
#include "Menu.h"
#include "project1_lib.h"
class ViewEventMenu : public Menu
{
    public:
    ViewEventMenu(std::string eventName);
    ~ViewEventMenu();
    std::string getName() const;


    private:
    int totalAttendees;
    int totalTimes;
    std::string m_eventName;

};
#endif