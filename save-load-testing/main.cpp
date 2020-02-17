#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  char option;
  string name,eName,startT, endT;
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
        // EVENT NAME     ADMIN NAME      EVENT START TIME      EVENT END TIME
        events.open("January.txt", fstream::app); //::app to keep writing on files
        cout<<"\nEnter event admin name: ";
        cin>>name;
        cout<<"\nEnter event name: ";
        cin>>eName;
        cout<<"\nEnter event start time (XX:XX): ";
        cin>>startT;
        cout<<"\nEnter event end time (XX:XX): ";
        cin>>endT;
        cout<<"\nEvent saved\n";
        events<<eName<<'\t'<<name<<'\t'<<startT<<'\t'<<endT<<'\n';
        events.close();
      }
    if(option == 'b')
      {
        //reading format:
        // EVENT NAME     ADMIN NAME      EVENT START TIME      EVENT END TIME
        output.open("January.txt");
        int i = 1;
        while(output >> eName)
        {
          output>>name;
          output>>startT;
          output>>endT;
          cout<<"===========\nEVENT "<<i<<"\n===========\n";
          cout<<"Name of the Event:" << eName<<"\nEvent admin: "<<name<<"\nEvent start time: "<<startT<<"\nEvent end time: "<<endT<<"\n\n";
          i++;
        }
        output.close();
      }

  }
  return(0);
}
