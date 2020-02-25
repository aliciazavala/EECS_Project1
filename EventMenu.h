#ifndef EVENTMENU_H
#define EVENTMENU_H

#include <vector>
#include "Menu.h"
#include "project1_lib.h"
#include <fstream>
#include <string.h>


class EventMenu : public Menu
{
  public:
    EventMenu(int id, bool militaryTime, bool adminMode);
    EventMenu();
    ~EventMenu();
    void print(int loadedmonth, int loadedyear,bool& pass);
    void print()const;
    std::string getTime() const;
    std::string getName() const;
    std::string getPassword() const;
    int getTimeSlot(int x);
    int countAttendees(int index);
    void printAvailability();

  private:
    std::string m_menuName;
    std::string m_eventTime;
    std::string m_password;
    std::string m_eventname;
    int m_ID;
    bool m_militaryTime;
    bool m_adminMode;
    std::vector<std::string>* times;
};
#endif
