#ifndef ATTENDMENU_H
#define ATTENDMENU_H

#include "Menu.h"
#include "project1_lib.h"
#include <fstream>
#include <string.h>


class AttendMenu : public Menu
{
  public:
    AttendMenu(int id);
    AttendMenu();
    ~AttendMenu();
    void print();
    void print()const;
    std::string getName() const;

  private:
    std::string m_menuName;
    int m_ID;
    std::string m_name;


};
#endif
