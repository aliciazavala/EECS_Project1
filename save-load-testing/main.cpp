#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  char option;
  string name,eName,startT, endT;
  //writes
  ofstream events;
  //reads
  ifstream output;

  while(option != 'q')
  {
    cout<<"Select an option:\na) Create Event in January\nb) See Events\nq) Quit\n";
    cin>>option ;


    // OLD, DO NOT USE!!
    if(option == 'a')
      {
        //saving format:
        // EVENT NAME     ADMIN NAME      EVENT START TIME      EVENT END TIME
        events.open("./data/January.txt", fstream::app); //::app to keep writing on files
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


    //
    if(option == 'b')
      {

        output.open("./data/January.txt");

        string temp;


        //ADDED EVENTID VARIABLE
        int eventID;



        string creatorName;
        string attendeeName;
        string eventName;
        int month;
        int day;
        int year;
        int userChoice;
        while(output>>temp)
        {
            output>>eventID;
    				getline(output,eventName);
    				getline(output,creatorName);
    				output>>month;
    				output>>day;
    				output>>year;

    			  cout << "\t ===== " << eventName << " =====" <<endl;
    				//USE LIBRARY TO ALSO GET DAY OF THE WEEK??
            //cout<<"Date: "<< nameOfMonth(m_loadedMonth) <<", "<< dayOfWeek(m_loadedMonth,day,m_loadedYear) << " "<< m_loadedYear << "\n" ;
    				cout<<"Date: "<< " January, (Day of the week) "<< year << "\n" ;
    				cout<<"Event Creator: "<<creatorName<<"\n";
    			  cout<<"Attendees: "<<"\n";

            //READ ATTENDEES
            ifstream attendees;
            string attendeeName;
            int id;
            int i = 0;
            //attendee time variable

            attendees.open("./data/Attendees.txt");
            while(attendees>>id)
            {
              if(id == eventID)
              {
                getline(attendees,attendeeName);
                //get attendee time variable
                cout<<attendeeName<<endl;
                //GET ATTENDEES TIMES AND PRINT THEM
                i++;
              }
              else
              {
                getline(attendees,attendeeName);
                //getline(attendees,attendeeTime);
              }
            }
            if(i == 0)
            {
              cout<<"No attendees yet.\n";
            }
            attendees.close();
        	}
          cout<<endl;
        }
      }
  return(0);
}
