#ifndef EVENTS_H
#define EVENTS_H


#include "User.h"
#include <string>

using namespace std;

class Events
{
private:
  User m_admin;
  string m_time;
  string m_eName;
public:
  Events(string eName, User admin, string time);
  string getTime();
  string getAdmin();
  string getEName();
};

#endif
