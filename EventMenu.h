#ifndef EVENTMENU_H
#define EVENTMENU_H

#include "Menu.h"
#include "project1_lib.h"
#include <fstream>
#include <string.h>


class EventMenu : public Menu
{
  public:
    EventMenu(int id);
    EventMenu();
    ~EventMenu();
    void print(int loadedmonth, int loadedyear);
    void print()const;
    std::string getName() const;

  private:
    std::string m_menuName;
    int m_ID;


};
#endif
