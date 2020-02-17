#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  char option;
  string name,eName,time;
  ofstream events;
  ifstream output;


  while(option != 'q')
  {
    cout<<"Select an option:\na) Create Event in January\nb) See Events\nq) Quit\n";
    cin>>option ;
    if(option == 'a')
      {
        events.open("January.txt", fstream::app);
        cout<<"\nEnter event admin name: ";
        cin>>name;
        cout<<"\nEnter event name: ";
        cin>>eName;
        cout<<"\nEnter event date and time: ";
        cin>>time;
        cout<<"\nEvent saved\n";
        events<<eName<<'\t'<<name<<'\t'<<time<<'\n';

      }
    if(option == 'b')
      {
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
      events.close();
  }
  return(0);
}
