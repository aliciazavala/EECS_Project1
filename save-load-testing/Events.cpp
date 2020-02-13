#include "Events.h"

Events::Events(string eName, User admin, string time)
{
  m_admin = admin;
  m_time = time;
  m_eName = eName;
  
}

string Events::getTime()
{
  return(m_time);
}

string Events::getAdmin()
{
  return(m_admin.getName());
}

string Events::getEName()
{
  return(m_eName);
}
