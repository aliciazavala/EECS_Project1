#include "User.h"

string User::getName()
{
  return (m_name);
}
string User::getPass()
{
  return (m_passw);
}
User::User(string name, string passw)
{
  m_name = name;
  m_passw = passw;
}
