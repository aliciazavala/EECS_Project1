#ifndef VIEWEVENTMENU_H
#define VIEWEVENTMENU_H
#include <string>
#include "Menu.h"
#include "project1_lib.h"
class ViewEventMenu : public Menu
{
    public:
    ViewEventMenu(int eventId);
    ~ViewEventMenu();
    std::string getName() const;
    int getEventId() const;
    void print() const;


    private:
    int totalAttendees;
    int totalTimes;
    int m_eventId;

};
#endif
