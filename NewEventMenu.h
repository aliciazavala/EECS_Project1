#ifndef NEWEVENTMENU_H
#define NEWEVENTMENU_H
#include"Menu.h"
#include "project1_lib.h"
class NewEventMenu: public Menu
{
public:
  NewEventMenu(int monthEvent);
  ~NewEventMenu();
  void print() const;
  NewEventMenu(const NewEventMenu& original);

  std::string getName() const;
  std::string getMonth() const;

private:
std::string m_menuName;
std::string m_month;
int totalEvents;
};
#endif
