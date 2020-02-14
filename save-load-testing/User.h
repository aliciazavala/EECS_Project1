#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
private:
  string m_name;
  string m_passw;


public:
  User(string name, string passw);
  User(){};
  string getName();
  string getPass();

};
#endif
