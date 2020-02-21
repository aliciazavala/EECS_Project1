#ifndef VIEWEVENTMENU_H
#define VIEWEVENTMENU_H
#include"Menu.h"
#include "project1_lib.h"
class ViewEventMenu: public Menu
{
public:
  ViewEventMenu(int monthEvent);
  ~ViewEventMenu();
  void print() const;

  std::string getName() const;

private:
std::string m_menuName;

};
#endif
