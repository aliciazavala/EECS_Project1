#include <iostream>
#include <fstream>
#include <string>

#include "User.h"
#include "Events.h"

using namespace std;

int main()
{
  char option;
  ofstream users;
  ofstream events;
  users.open("users.txt");
  events.open("events.txt");
  User Alicia("Alicia","eecs448");
  users << "Alicia\teecs448";
  Events BirthdayAli("Alicia's Birthday",Alicia,"12/20 4pm - 7pm");
  events<<BirthdayAli.getEName()<<'\t'<<Alicia.getName()<<'\t'<<BirthdayAli.getTime()<<'\n';
  string name, passw, eName, time;
  while(option != 'q')
  {
    cout<<"Select an option:\na) Create Event\nb) See Events\nq) Quit\n";
    cin>>option ;
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
        users<<name<<'\t'<<passw<<'\n';
        events<<eName<<'\t'<<name<<'\t'<<time<<'\n';
        Events(eName, newAdmin,time);
      }
    if(option == 'b')
      {
        //event.open("events.txt");
        /*while(event)
        {
          event>>eName;
          event>>name;
          event>>time;
          cout<<"Event name: "<<eName<<"\nEvent date and time: "<<time<<"Event creator: "<<name;
        }*/
      }
  }
  return(0);
}
