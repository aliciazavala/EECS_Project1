#include <iostream>
#include <fstream>
#include <string>

#include "User.h"
#include "Events.h"

using namespace std;

int main()
{
  char option;
  User Alicia("Alicia","eecs448");
  Events BirthdayAli("Alicia's Birthday",Alicia,"12/20 4pm - 7pm");
  string name, passw, eName, time;
  while(option != 'q')
  {
    cout<<"Select an option:\na) Create Event\nb) See Events\nq) Quit\n";
    cin>>option;
    if(option == 'a')
      {
        cout<<"\nEnter event admin name: ";
        cin>>name;
        cout<<"\nEnter event admin password: ";
        cin>>passw ;
        cout<<"\nEnter event name: ";
        cin>>eName;
        cout<<"\nEnter event date and time: ";
        cin>>time;
        User newAdmin(name,passw);
        Events(eName, newAdmin,time);

      }
    if(option == 'b')
      {

      }
  }
  return(0);
}
