#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  char option;
  string name,eName,time;
  //writes events
  ofstream events;
  //reads events
  ifstream output;

  while(option != 'q')
  {
    cout<<"Select an option:\na) Create Event in January\nb) See Events\nq) Quit\n";
    cin>>option ;
    if(option == 'a')
      {
        //saving format:
        // EVENT NAME     ADMIN NAME      EVENT TIME
        events.open("January.txt", fstream::app); //::app to keep writing on files
        cout<<"\nEnter event admin name: ";
        cin>>name;
        cout<<"\nEnter event name: ";
        cin>>eName;
        cout<<"\nEnter event date and time: ";
        cin>>time;
        cout<<"\nEvent saved\n";
        events<<eName<<'\t'<<name<<'\t'<<time<<'\n';
        events.close();
      }
    if(option == 'b')
      {
        //reading format:
        // EVENT NAME     ADMIN NAME      EVENT TIME
        output.open("January.txt");
        int i = 1;
        while(output >> eName)
        {
          output>>name;
          output>>time;
          cout<<"===========\nEVENT "<<i<<"\n===========\n";
          cout<<"Name of the Event:" << eName<<"\nEvent admin: "<<name<<"\nEvent time and date: "<<time<<"\n\n";
          i++;
        }
        output.close();
      }

  }
  return(0);
}
